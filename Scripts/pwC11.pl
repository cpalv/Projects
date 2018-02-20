#!/usr/bin/perl -w

#  11. word based with extra symbol and special character replacement

$word = "thisword";
@sym = ('~','`','!','@','#','$','%','^','&','*','_','-','+','=','|',':','?','/','.','>','<',','); 
%equiv = (	'a' , '@',
			'A' , '@',
			'c' , '(',
			'C' , '(',
			'd' , '.',
			'D' , '.',
			'i' , '!',
			'I' , '!',
			'l' , '|',
			'L' , '|',
			'o' , '0',
			'O' , '0',
			'v' , '^',
			'V' , '^',
			'n' , '#',
			'N' , '#',
			's' , '$',
			'S' , '$'
		);

$i = 0;

while( $i < 100) {
	$word = substr($word,0,7);
	@letters = split(//,$word);
	foreach $c (@letters) {
		$c = $equiv{$c} if defined $equiv{$c};
	}
	splice(@letters,int(rand(@letters-2))+1,0,$sym[int(rand @sym)]);
	$pw = join("",@letters);
	print $pw,"\n";
	$i++;
}#end while
