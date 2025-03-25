TARGET := stackinstr

.PRECIOUS: %.exe

all: $(TARGET)

# Work on everyone's machine (out of tree)
-include ../../Makefile.inc

# Disable default rule
MAKEFLAGS += --no-builtin-rules

%.exe: %.c
	gcc -O1				\
	    -g				\
	    -fno-stack-protector	\
	    -fcf-protection=none	\
	    -U_FORTIFY_SOURCE		\
	    -Wall                       \
	    -o $@			\
	    $<

%: %.exe
	rm -f $@
	ln -s $< $@

clean:
	rm -f $(TARGET) $(TARGET).exe $(TARGET).log
