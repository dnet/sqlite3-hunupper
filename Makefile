SHARED_LIB=hunupper.so

$(SHARED_LIB): hunupper.c
	$(CC) -g -fPIC -Wall -O3 -shared $< -o $@

clean:
	rm -f $(SHARED_LIB)
