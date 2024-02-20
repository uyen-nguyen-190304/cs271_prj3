# Target for main1 (testing the heap)
main1: main1.o
	g++ -o main1 main1.o

main1.o: main1.cpp Heap.h
	g++ -c main1.cpp

# Target for main2 (testing for priority queue)
main2: main2.o
	g++ -o main2 main2.o

main2.o: main2.cpp PQueue.h
	g++ -c main2.cpp
