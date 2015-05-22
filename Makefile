EXE	:=	$(patsubst %.c, %, $(wildcard *.c))

ifeq ($(OS),Windows_NT)
EXE	:=	$(EXE:%=%.exe)
else
CC	:=	clang
endif

ifeq ($(CC),clang)
override CFLAGS	+=	-ansi -Weverything
else
override CFLAGS	+=	-ansi -pedantic -W -Wall
endif

.PHONY: all clean

all: $(EXE)

%: CFLAGS += -D$(shell echo $* | tr a-z A-Z)

# Thank you stupid MinGW-Make ...
ifeq ($(OS),Windows_NT)
%: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@
endif

clean:
	@$(RM) $(EXE)
