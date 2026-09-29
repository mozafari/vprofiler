CC = $(which gcc)
CXX = $(which g++)

C_FLAGS = -O3
CXX_FLAGS = -o3 --std=c++11
BOOST_THREAD_LIBDIR ?=
LINK_FLAG = -lpthread -lrt $(if $(BOOST_THREAD_LIBDIR),-L$(BOOST_THREAD_LIBDIR)) -lboost_thread

SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
clean: 
	rm -f $(PROGS)
