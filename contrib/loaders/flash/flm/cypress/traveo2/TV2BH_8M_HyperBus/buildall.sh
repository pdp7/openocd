#!/bin/sh

for tgt in *.mk;
do
  make TARGET=${tgt} clean
  make TARGET=${tgt}
done

find -L  -type f -name "*.[od]" -delete