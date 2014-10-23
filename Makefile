EXE	:=	$(patsubst %.c, %, $(wildcard *.c))
CC	:=	clang

ifeq ($(OS),Windows_NT)
EXE	:=	$(EXE:%=%.exe)
endif

ifeq ($(CC),clang)
override CFLAGS	+=	-ansi -Weverything
else
override CFLAGS	+=	-ansi -pedantic -W -Wall
endif

.PHONY: all clean

all: $(EXE)

%:	CFLAGS += -D$(shell echo $* | tr a-z A-Z)

clean:
	@$(RM) $(EXE)
