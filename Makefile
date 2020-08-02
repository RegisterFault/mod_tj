all: mod_tj.c
	apxs -i -a -c mod_tj.c

clean:
	rm -rf *.la *.slo *.lo *.o .libs
