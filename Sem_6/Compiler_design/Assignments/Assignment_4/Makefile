lexfile = A3.l
yaccfile = A3.y

a.out: $(lexfile) $(yaccfile)
	lex $(lexfile)
	yacc $(yaccfile) -d
	gcc lex.yy.c y.tab.c -w -lm

run: a.out
	./a.out

clean: 
	rm -rf a.out *.c