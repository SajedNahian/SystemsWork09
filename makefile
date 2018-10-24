all: main.c
	gcc -o out main.c

run:
	./out

clean:
	rm *.txt