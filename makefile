all: stat.c
	gcc -o stat stat.c
run: all
	./stat
clean:
	rm foo
	rm stat