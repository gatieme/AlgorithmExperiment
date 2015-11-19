ROOT=..
PLATFORM=$(shell $(ROOT)/systype.sh)
include $(ROOT)/Make.defines.$(PLATFORM)

target=BruteForce GrahamScan DivideConvex



all:$(target)

BruteForce : BruteForce.o
	$(CC) $^ -o $@ $(LDFLAGS)
	echo "编译凸包暴力解法"

DivideConvex: DivideConvex.o
	$(CC) $^ -o $@ $(LDFLAGS)
	echo "编译凸包分治解法"

GrahamScan : GrahamScan.o
	$(CC) $^ -o $@ $(LDFLAGS)
	echo "编译凸包扫描解法"
%.o : %.c
	$(CC) -c $^ -o $@  $(CFLAGS) $(DEFINES)

clean :
	rm *.o
	rm $(target)
