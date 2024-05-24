CC=gcc # COMPILER NAME
CFLAGS=-pedantic -march=native -Wall -Wextra -g # COMPILER FLAGS
LFLAGS=-lncurses # LINKER FLAGS
SRCS=sabs.c # SOURCE FILES
TARG=sabs # EXECUTABLE NAME
OBJS=$(SRCS:.c=.o) # OBJECT FILES

# TARGET
all: $(TARG)

# LINK
$(TARG): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARG) $(OBJS) $(LFLAGS)

# COMPLILE
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# CLEAN
clean:
	rm -f $(TARG) $(OBJS)
