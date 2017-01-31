compile = gcc -Ilib -Llib

all: prob2 prob3 prob4
prob2: prob2.c
	$(compile) -lnumbers -o prob2 prob2.c
prob3: prob3.c
	$(compile) -lnumbers -o prob3 prob3.c
prob4: prob4.c
	$(compile) -lnumbers -lstrings -o prob4 prob4.c
prob5: prob5.c
	$(compile) -lnumbers -o prob5 prob5.c
prob7: prob7.c
	$(compile) -lnumbers -o prob7 prob7.c
prob8: prob8.c
	$(compile) -o prob8 prob8.c
clean: 
	ls -F | grep "*" | sed 's/*//' | xargs rm
