all:
	gcc main.c ./sources/tarefaA.c ./sources/tarefaB.c ./sources/casamento.c ./sources/cifra.c -o ./bin/exe
	./bin/exe