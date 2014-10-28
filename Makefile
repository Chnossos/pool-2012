EXE	:=	$(patsubst %.c, %, $(wildcard *.c))

ifeq ($(OS),Windows_NT)
EXE	:=	$(EXE:%=%.exe)
else
CC	:=	clang
endif

ifeq ($(CC),clang)
override CFLAGS	+=	-ansi -pedantic -W -Wall
else
override CFLAGS	+=	-ansi -pedantic -Weverything
endif

.PHONY: all clean

all: $(EXE)

%: CFLAGS += -D$(shell echo $* | tr a-z A-Z)

clean:
	@$(RM) $(EXE)
