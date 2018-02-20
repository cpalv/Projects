#!/usr/bin/perl -w

@list = ('cat','dog','horse');
@other = ('human', 'animal', 'dinosaur', 'creature');

@new = splice(@other, 1, 2, @list);

print "@new\n";
print "@other\n";
print "@list\n";

if ( @ARGV) {
	print "Hi\n";
} else {
	print "No args\n";
}
