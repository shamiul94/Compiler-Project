cp tem.cpp 1505038.y
echo '00'

# Assume your parser(yacc/bison) file with .y extention is named simplecalc.y. The followings are the sequence of commands you need to give to compile your parser and scanner(from previous assignment and modified). Find the details of the commands used here from manual of flex and bison. Some explanations are given here also.
g++ -w -c -o s.o SymbolTable.cpp
echo '0'

bison -d -y -v 1505038.y	# -d creates the header file y.tab.h that helps in communication(i.e. pass tokens) between parser and scanner; -y is something similar to -o y.tab.c, that is it creates the parser; -v creates an .output file containing verbose descriptions of the parser states and all the conflicts, both those resolved by operator precedence and the unresolved ones
echo '1'
g++ -w -c -o y.o y.tab.c	# -w stops the list of warnings from showing; -c compiles and assembles the c code, -o creates the y.o output file    

echo '2'
flex 1505038.l		#creates the lexical analyzer or scanner named lex.yy.c

echo '3'
#g++ -w -c -o l.o lex.yy.c
g++ -fpermissive -w -c -o l.o lex.yy.c
# if the above command doesn't work try g++ -fpermissive -w -c -o l.o lex.yy.c

echo '4'
g++ -o a.out s.o y.o l.o -lfl -ly	#compiles the scanner and parser to create output file a.out; -lfl and -ly includes library files 					for lex and yacc(bison)

chmod +x ./a.out

echo '5'
./a.out	in2.c	# you will need to provide proper input files with ./a.out command as instructed in assignment specification

