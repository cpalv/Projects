#!/usr/bin/perl -w

$divide = shift;
@lines = <>;
chop @lines;
$rem = @lines % $divide;
$numf = (@lines - $rem) / $divide;
$f = 1;
@remlines = splice(@lines,$#lines-$rem, $rem+1);
for($i = 0; $i < $numf; $i++) {
	open(OUT," > file.doc.$f");
	@l = splice(@lines, 0, 100);
	print OUT join("\n",@l),"\n";
	$f++;
}
open (REM, "> file.doc.$f");
print REM join ("\n",@remlines),"\n";
