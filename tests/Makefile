CC     := clang
CFLAGS := -Wall -Werror -O0
IFLAGS := -I../include/

SRCS   := $(wildcard *.c)
OUTS   := $(basename $(SRCS))

all: $(OUTS)
	rm -f $(OUTS)

$(OUTS): %: %.c
	$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@
	- ./$@

