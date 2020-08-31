#!/bin/bash
set -x -e

################################################################################
# Usage example:
# ./build_all.sh PKG_LVERSION=4.0.0-123
################################################################################

OPENOCD_BRANCH=icw/4.1

for cmd in "${@}"; do
	eval "${cmd}"
done

: "${PKG_LVERSION:?Variable not set or empty}"

################################################################################
STATIC="${STATIC:-0}"
OPENOCD_BRANCH="${OPENOCD_BRANCH:-develop}"
PKG_LVERSION=${PKG_LVERSION:-${OPENOCD_BRANCH}-latest}
LIBUSB_BRANCH=${LIBUSB_BRANCH:-master}
HIDAPI_BRANCH=${HIDAPI_BRANCH:-master}
################################################################################
HIDAPI_REPO=https://github.com/libusb/hidapi.git
LIBUSB_REPO=https://github.com/libusb/libusb.git
OPENOCD_REPO=http://git-ore.aus.cypress.com/repo/cyopenocd.git
#OPENOCD_REPO=https://void.in.ua/git/void/OpenOCD.git
SOURCE_PREFIX=`pwd`/build/_src
BUILD_PREFIX=`pwd`/build/_libs
INSTALL_PREFIX=`pwd`/install
BIN_PREFIX=${INSTALL_PREFIX}/openocd/bin
CONTRIB_PREFIX=${INSTALL_PREFIX}/openocd/contrib
#-------------------------------------------------------------------------------

export MAKEFLAGS=${MAKEFLAGS:=-j8}
XTRA_CFLAGS+=" -O2 -URELSTR -DRELSTR=\\\"-${PKG_LVERSION}\\\""

case "$OSTYPE" in
	darwin*)
		if [ ${STATIC} -eq 1 ]; then
			echo "Static build is not supported on Mac OS"
			STATIC=0
		fi
		export XTRA_CFLAGS+=" -Qunused-arguments"
		;;
	linux*)
		XTRA_CFLAGS+=" -Wl,-rpath,XORIGIN"
		;;
	msys*)
		if [ ${STATIC} -eq 1 ]; then
			XTRA_CFLAGS+=" -Wl,-static"
		fi
		;;
	*)	echo "Unknown operating system: $OSTYPE"
		exit 1
		;;
esac

if [ ${STATIC} -eq 1 ]; then
	XTRA_CFLAGS+=" -static -static-libgcc"
	XTRA_LDFLAGS+=" -static"
	LIBUSB_BUILD_TYPE="--enable-shared=no"
else
	LIBUSB_BUILD_TYPE="--enable-static=no"
fi

maybe_fetch_package()
{
	if [ ! -d ${SOURCE_PREFIX}/${1} ]; then
		git clone --branch ${3} ${2} ${SOURCE_PREFIX}/${1} ${@:4}
	else
		cd ${SOURCE_PREFIX}/${1}
		git fetch --all
		git reset --hard origin/${3}
		git clean -fd
		cd -
	fi
}

maybe_build_library()
{
	cd ${SOURCE_PREFIX}/${1}
	if [ ! -f Makefile ]; then
		./bootstrap || ./autogen.sh
		./configure --prefix=${BUILD_PREFIX} --enable-silent-rules ${@:2}
	fi
	make
	make install
	cd -
}

maybe_fetch_package hidapi ${HIDAPI_REPO} ${HIDAPI_BRANCH} --depth=1
maybe_fetch_package libusb ${LIBUSB_REPO} ${LIBUSB_BRANCH} --depth=1
maybe_fetch_package openocd ${OPENOCD_REPO} ${OPENOCD_BRANCH}

maybe_build_library libusb ${LIBUSB_BUILD_TYPE}
maybe_build_library hidapi --enable-shared=no \
	LD_LIBRARY_PATH=:${BUILD_PREFIX}/lib \
	PKG_CONFIG_PATH=${BUILD_PREFIX}/lib/pkgconfig

rm -rf ${INSTALL_PREFIX}

cd ${SOURCE_PREFIX}/openocd

if [ -f Makefile ]; then
	make distclean
fi

./bootstrap
./configure --enable-silent-rules --disable-werror \
	--disable-ulink --disable-usbprog --disable-rlink --disable-armjtagew \
	CFLAGS="${CFLAGS} ${XTRA_CFLAGS}" LDFLAGS="${LDFLAGS} ${XTRA_LDFLAGS}" \
	LD_LIBRARY_PATH=:${BUILD_PREFIX}/lib:${BUILD_PREFIX}/bin:${LD_LIBRARY_PATH} \
	PKG_CONFIG_PATH=${BUILD_PREFIX}/lib/pkgconfig \
	CC="gcc" \
	--prefix=${BUILD_PREFIX} \
	--mandir=${BUILD_PREFIX}/share/man \
	--infodir=${BUILD_PREFIX}/share/info \
	--bindir=${BIN_PREFIX} \
	--datarootdir=${INSTALL_PREFIX}

make
make install-strip
cd -

mkdir -p ${INSTALL_PREFIX}/openocd/source
cp -av ${SOURCE_PREFIX}/openocd/build/*.sh ${INSTALL_PREFIX}/openocd/source/

mkdir -p ${INSTALL_PREFIX}/openocd/docs
cp -av ${SOURCE_PREFIX}/openocd/doc/third_party_licenses ${INSTALL_PREFIX}/openocd/docs
cp -av ${SOURCE_PREFIX}/openocd/doc/*.pdf ${INSTALL_PREFIX}/openocd/docs

rm -rf ${CONTRIB_PREFIX}

case "$OSTYPE" in
	darwin*)
		if [ ${STATIC} -eq 0 ]; then
			cp ${BUILD_PREFIX}/lib/libusb-1.0.0.dylib ${BIN_PREFIX}/
			install_name_tool -change ${BUILD_PREFIX}/lib/libusb-1.0.0.dylib @executable_path/libusb-1.0.0.dylib ${BIN_PREFIX}/openocd
#			oocd_file="$(find ${BIN_PREFIX} -iname 'openocd')"
#			mv $oocd_file ${oocd_file}_run
#			cp `which dirname` ${oocd_file}_dirname
#			echo "#!/bin/bash" > ${oocd_file}
#			echo "export DYLD_LIBRARY_PATH=\`\$0_dirname \$0\`:$DYLD_LIBRARY_PATH" >> ${oocd_file}
#			echo "\${0}_run \"\$@\"" >> ${oocd_file}
#			chmod a+x ${oocd_file}
		fi
		;;
	msys*)
		if [ ${STATIC} -eq 0 ]; then
#			cp /mingw64/bin/libwinpthread-1.dll ${BIN_PREFIX}/
			cp /c/msys64/mingw32/bin/libwinpthread-1.dll ${BIN_PREFIX}/
			cp ${BUILD_PREFIX}/bin/libusb-1.0.dll ${BIN_PREFIX}/
			strip ${BIN_PREFIX}/*.dll
		fi
		;;
	linux*)
		cp -av ${SOURCE_PREFIX}/openocd/udev_rules ${INSTALL_PREFIX}/openocd/
		if [ ${STATIC} -eq 0 ]; then
			find ${BUILD_PREFIX}/lib/ -maxdepth 1 -type f -name libusb*.so.* \
				-exec cp -av {} ${BIN_PREFIX}/libusb-1.0.so.0 \;
			strip ${BIN_PREFIX}/libusb-1.0.so.0
			chrpath -r '$ORIGIN' ${BIN_PREFIX}/openocd
		fi
		;;
esac

