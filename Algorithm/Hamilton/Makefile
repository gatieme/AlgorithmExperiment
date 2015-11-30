ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

target=FindAllHamilton Hamilton Random


all:$(target)

Hamilton : Hamilton.o
	$(CC) $^ -o $@ $(LDFALGS)
	echo "输出图中一条密顿环"

FindAllHamilton : FindAllHamilton.o
	$(CC) $^ -o $@ $(LDFALGS)
	echo "输出图中所有的密顿环\n"

Random : Random.o
	$(CC) $^ -o $@ $(LDFALGS)
	echo "生成数据集"



%.o : %.c
	$(CC) -c $^ -o $@  $(CFLAGS) $(DEFINES)

clean :
	rm *.o
	rm $(target)
