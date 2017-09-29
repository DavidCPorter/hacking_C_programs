# tools
CC := gcc
CXX := g++
RM := rm -f
CP := cp

# flags
CFLAGS := -ggdb -Wall -std=gnu99 -w -g -O1 -zexecstack -fno-stack-protector -U_FORTIFY_SOURCE
CXXFLAGS := $(CFLAGS)
LDFLAGS :=
LDLIBS := -lcrypt

# sources
sources := sploit1.c sploit2.c sploit3.c sploit4.c sploit5.c sploit6.c
sploits := $(sources:.c=)
targets := ../targets/target1 ../targets/target2 ../targets/target3 ../targets/target4 ../targets/target5 ../targets/target6
installed_targets := $(addprefix /tmp/,$(targets))

# gmake magic
.PHONY: all clean install

#sploits
all: $(sploits)	$(targets)

target4: target4.cc
	$(CXX) $(CXXFLAGS) -fstack-protector $(LDFLAGS) -o $@ $<

install: $(targets)
	sudo $(CP) $(targets) /tmp
	sudo chown root:toor $(installed_targets)
	sudo chmod 04755 $(installed_targets)

clean:
	$(RM) $(sploits)
	$(rm) $(targets)
	sudo $(RM) $(installed_targets)

#dependencies
$(sploits): shellcode.h
target5: smalloc.c

