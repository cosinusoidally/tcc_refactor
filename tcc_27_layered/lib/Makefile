#
# Minimal runtime archive build for the layered i386 ELF target.
#

TOP = ..
XAR ?= ../tcc -ar
XCC ?= ../tcc
BIN = ../libtcc1.a
OBJS = libtcc1.o alloca86.o

$(BIN) : $(OBJS)
	$(XAR) rcs $@ $^

%.o : %.c
	$(XCC) -c $< -o $@

%.o : %.S
	$(XCC) -c $< -o $@

clean :
	rm -f *.a *.o $(BIN)
