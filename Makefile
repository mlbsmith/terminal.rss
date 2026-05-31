CC = cc
CFLAGS = -Wall -Wextra -Wpedantic -std=c17

terminal-rss: main.c
	$(CC) $(CFLAGS) main.c -o terminal-rss

.PHONY: clean
clean:
	rm -f terminal-rss
