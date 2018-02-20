#!/usr/bin/perl -w

$num = shift;
@lines = <>;
chop @lines;
$fnum = 1;
while ( @lines ) {
	if ( @lines > $num) {
		open (FILE, "> file.doc.$fnum");
		@out = split( @lines, 0, $num);
		print FILE join("\n",@out),"\n";
		$fnum++;
	} else {
		open(REM, "> file.doc.$fnum");
		print REM join("\n", @lines),"\n" and exit;
	}
}
