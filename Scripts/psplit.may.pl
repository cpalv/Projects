#!/usr/bin/perl -w

$num = shift;
@lines = <>;
$n = 1;
while( @lines) {
	open(OUT, "> $ARGV[0].$n") or die "Unable to open $ARGV[0].$n: $!\n";
	if ( $num <= @lines) {
		print @lines[0..($num-1)];
		@lines = @lines[$num..$#lines];
	} else {
		print @lines[0..$#lines];
		last;
	}
	$n++;
}
