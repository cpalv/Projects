#!/usr/bin/perl -w

open(FILE, "> file.doc");
for( $i = 0; $i < 420; $i++) {
	print FILE "line $i: This is some text\n";
}
