#target: dependences
#	rules (instructions)

CC := gcc
INLCUDEPATH := -I .


ac : ac.tab.c lex.yy.c
	$(CC) $(INLCUDEPATH) ac.tab.c lex.yy.c -ll -o ac

ac.tab.c:
	bison -d ac.y

lex.yy.c:
	flex ac.l
