CC=gcc
CFLAGS=-std=c99
LFALGS=-lm
DEFINES=-DTIME -DLINUX
target=BruteForce GrahamScan DivideConvex



all:$(target)

BruteForce : BruteForce.o
	$(CC) $^ -o $@ $(LFALGS)
	echo "编译凸包暴力解法"

DivideConvex: DivideConvex.o
	$(CC) $^ -o $@ $(LFALGS)
	echo "编译凸包分治解法"

GrahamScan : GrahamScan.o
	$(CC) $^ -o $@ $(LFALGS)
	echo "编译凸包扫描解法"
%.o : %.c
		$(CC) -c $^ -o $@  $(CFLAGS) $(DEFINES)

clean :
	rm *.o
	rm $(target)
