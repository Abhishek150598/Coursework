filename = A3_2.lex

a.out: $(filename)
	lex $(filename)
	gcc lex.yy.c -ll

run: a.out
	./a.out

clean: 
	rm -rf a.out *.c