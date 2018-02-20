#!/bin/sh

for ac_header in pcre.h
do
	echo "as_var = $ac_header"
done

POS="pos"
COC="coc"

if test "x$POS" = "xpos" -a "x$COC" = "xcoc"; then
	echo
	echo "dafuq"
	exit
else
	echo
	echo "holy shit"
	exit
fi
