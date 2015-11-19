ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

target=Hamilton 


all:$(target)

Hamilton : Hamilton.o
	$(CC) $^ -o $@ $(LDFALGS)
	echo "编译哈密顿环"

%.o : %.c
	$(CC) -c $^ -o $@  $(CFLAGS) $(DEFINES)

clean :
	rm *.o
	rm $(target)
