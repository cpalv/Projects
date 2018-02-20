#!/usr/bin/perl -w

while(<ARGV>) {
	if( /\S/) {
		s/[ 	]+/ /g;
		if(/^\/\*.*\*\/$/) {
	    		s/perl/PERL/g;
		}
		print;
	}
}

