CFLAGS = -O3 -Wall

assert: assert.c

.PHONY: clean
clean:
	rm -f assert
