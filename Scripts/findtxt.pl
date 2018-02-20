#!/usr/bin/perl -w

#	Find all text files below my home directory

open(FN, "find `pwd` -print| sort |") or die "did not find find";

while(<FN>) {
	chop $_;
	print"$_\n" if -f && -T;
}
