EXE	:=	$(shell ls | grep -v "\." | grep -v $(MAKEFILE_LIST))

CFLAGS	:=	-W -Wall -ansi -pedantic

.PHONY: all clean

all:
	@echo "Usage: make exercise_name (without extension)"

%:	CPPFLAGS = -D$(shell echo $* | tr a-z A-Z)

clean:
	@$(RM) $(EXE)
