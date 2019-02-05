all: wordcount

prog: wordcount.c
	gcc wordcount.c -wall -o wordcount

clean:
	rm -f -o wordcount *.c
