#!/usr/bin/perl -w

#  10. word based with 2 extra symbols in the middle

$regex = pop @ARGV;
print $regex,"\n";
@dict = <ARGV>;
@sym = ('~','`','!','@','#','$','%','^','&','*','_','-','+','=','|',':','?','/','.','>','<',','); 

@regdict = grep(/$regex/, @dict);
chop @regdict;
#foreach $rw ( @regdict) {
#	print $rw,"\n";
#}

foreach $word ( @regdict) {

	$i = 0;

	while( $i < 1000000000000) {
		$word = substr($word,0,6);
		@letters = split(//,$word);
	
		$j = int(rand(@letters-2))+1;
		#print $j,"\n";
		splice(@letters, $j,0,$sym[int(rand @sym)]);
	
		$j = int(rand(@letters-2))+1;
		#print $j,"\n";
		splice(@letters, $j,0,$sym[int(rand @sym)]);

		$pw = join("",@letters);
		print $pw,"\n";
		$i++;
	}#end while
}#end for
