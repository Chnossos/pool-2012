EXE	:=	$(patsubst %.c, %, $(wildcard *.c))
CC	:=	clang

override CFLAGS	+=	-ansi -Weverything

.PHONY: all clean

all: $(EXE)

%:	CFLAGS += -D$(shell echo $* | tr a-z A-Z)

clean:
	@$(RM) $(EXE)
