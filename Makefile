all:
	gcc src/main.c -o diagnostic

clean:
	rm -f diagnostic
