#!/bin/sh

find -L  -type f -name "*.[od]" -delete
find -L  -type f -name "*.elf" -delete
for tgt in *.mk;
do
  tgt=`basename ${tgt} .mk`
  echo "----- ${tgt} -----"
  make -rR TARGET=${tgt} clean
  make -rR TARGET=${tgt}
  mv out/${tgt}.elf ../../../../flm/cypress/traveo2/
done
