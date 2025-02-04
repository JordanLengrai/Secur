TARGET := swap

.PRECIOUS: %.exe

all: $(TARGET)

# Work on everyone's machine (out of tree)
-include ../../Makefile.inc

.PHONY: show

show: $(TARGET)
	objdump -dS $<

# Disable default rule
MAKEFLAGS += --no-builtin-rules

%.exe: %.c
	gcc -O1				\
	    -g				\
	    -fno-stack-protector	\
	    -fcf-protection=none	\
	    -U_FORTIFY_SOURCE		\
	    -o $@			\
	    $<

%: %.exe
	rm -f $@
	ln -s $< $@

clean:
	rm -f $(TARGET) $(TARGET).exe $(TARGET).log
