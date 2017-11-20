	CFLAGS = -Wall -fpic -coverage -lm

# Dominion Makefile

# General Purpose Make rules
rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
	# To run playdom you need to enter: ./playdom <any integer number> like ./playdom 10


testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testBuyCard.c dominion.o rngs.o
	gcc -o testBuyCard -g  testBuyCard.c dominion.o rngs.o $(CFLAGS)


# Run and log the basic testing suite to unittestresult.out
builtintests: testDrawCard testBuyCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out
	./testBuyCard >> unittestresult.out 2>&1
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

# Unit test Make rules
unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)

# Compile and run randomtest1 and output results to randomtest1.out
randomtest1.out: randomtest1.c dominion.o rngs.o
	gcc -o randomtest1 -g  randomtest1.c dominion.o rngs.o $(CFLAGS)
	./randomtest1 >> testresults.out 2>&1
	gcov dominion.c -b >> testresults.out
	cat dominion.c.gcov >> testresults.out

# Compile and run randomtest2 and output results to randomtest2.out
randomtest2.out: randomtest2.c dominion.o rngs.o
	gcc -o randomtest2 -g  randomtest2.c dominion.o rngs.o $(CFLAGS)
	./randomtest2 >> testresults.out  2>&1
	gcov dominion.c -b >> testresults.out
	cat dominion.c.gcov >> testresults.out

# Compile and run randomtest3 and output results to randomtest3.out
randomtest3.out: randomtest3.c dominion.o rngs.o
	gcc -o randomtest3 -g  randomtest3.c dominion.o rngs.o $(CFLAGS)
	./randomtest3 >> testresults.out 2>&1
	gcov dominion.c -b >> testresults.out
	cat dominion.c.gcov >> testresults.out

# Compile and run all card and unit tests and output results to unittestresult.out
unittestresult.out: unittest1 unittest2 unittest3
	./unittest1 >> testresults.out 2>&1
	gcov unittest1.c -b >> testresults.out
	cat unittest1.c.gcov >> testresults.out

	./unittest2 >> testresults.out 2>&1
	gcov unittest2.c -b >> testresults.out
	cat unittest2.c.gcov >> testresults.out
	
	./unittest3 >> testresults.out 2>&1
	gcov unittest3.c -b >> testresults.out
	cat unittest3.c.gcov >> testresults.out 

	gcov dominion.c >> testresults.out
	cat dominion.c.gcov >> testresults.out


# Run and log the basic testing suite to unittestresult.out
runtests: unittestresult.out randomtest1.out randomtest2.out randomtest3.out 


# Compile the interface object file
interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom player *.exe *.gcov *.gcda *.gcno *.so *.out testDrawCard testBuyCard unittest1 unittest2 unittest3 randomtest1 randomtest2 randomtest3
	rm -rf *.dSYM/
