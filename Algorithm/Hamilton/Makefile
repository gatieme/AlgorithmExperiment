ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

target=Hamilton AllHamilton SimAllHamilton  CostSimAllHamilton Random


all:$(target)

Hamilton : Hamilton.o
	$(CC) $^ -o $@ $(LDFALGS)
	echo "输出图中一条密顿环"

AllHamilton : AllHamilton.o
	$(CC) $^ -o $@ $(LDFALGS)
	echo "输出图中所有的密顿环"

SimAllHamilton : SimAllHamilton.o
	$(CC) $^ -o $@ $(LDFALGS)
	echo "输出图中单个顶点的所有的密顿环"

CostSimAllHamilton : CostSimAllHamilton.o
	$(CC) $^ -o $@ $(LDFALGS)
	echo "输出图中单个顶点的所有的密顿环及其权值"

Random : Random.o
	$(CC) $^ -o $@ $(LDFALGS)
	echo "生成数据集"



%.o : %.c
	$(CC) -c $^ -o $@  $(CFLAGS) $(DEFINES)

clean :
	rm *.o
	rm $(target)
