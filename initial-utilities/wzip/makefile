SRCS = wzip.c

TARG = wzip.out

CC = gcc

OPTS = -Wall
OTPS += -O

OBJS = $(SRCS:.c=.o)

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS)

clean:
	rm -f $(OBJS) $(TARG)

depend:
	makedepend  $(SRCS)
