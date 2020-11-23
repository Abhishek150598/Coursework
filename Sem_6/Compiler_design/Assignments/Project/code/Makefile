lex_analyser.out: lex_analyser.o get_type.o
	@g++ -std=c++14 lex_analyser.o get_type.o -o lex_analyser.out -g
	@rm lex_analyser.o get_type.o

lex_analyser.o: lex_analyser.cpp
	@g++ -std=c++14 -c lex_analyser.cpp -g

get_type.o: get_type.cpp get_type.h
	@g++ -std=c++14 -c get_type.cpp -g

parser.out: parser.cpp
	@g++ -std=c++14 parser.cpp -o parser.out

run_lex: lex_analyser.out
	@./lex_analyser.out

run_lex_details: lex_analyser.out
	@./lex_analyser.out details

run_parser: parser.out
	@./parser.out 

run_parser_details: parser.out
	@./parser.out details

run: run_lex run_parser

run_with_details: run_lex_details run_parser_details

clean:
	@rm -f *.o lex_analyser.out
