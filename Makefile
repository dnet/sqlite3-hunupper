SHARED_LIB=hunupper.so

$(SHARED_LIB): hunupper.c
	$(CC) $(CFLAGS) -g -fPIC -Wall -Wextra -O3 -shared $< -o $@

clean:
	rm -f $(SHARED_LIB)
