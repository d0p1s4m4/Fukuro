noinst_DATA = crt0.o

crt0.o: minilibc/@systype@/crt0.S
	$(CC) -c $(AM_CPPFLAGS) $(CFLAGS) -o $@ $^
