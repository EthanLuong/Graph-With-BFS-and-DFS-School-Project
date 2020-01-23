eluong2Proj7: eluong2Proj7.o MyList.o Island.o Node.o MyStack.o MyQueue.o
	g++ -o eluong2Proj7 eluong2Proj7.o Node.o MyStack.o MyList.o MyQueue.o Island.o
    
eluong2Proj7.o: eluong2Proj7.cpp Island.h
	g++ -c eluong2Proj7.cpp
    
Node.o: Node.cpp Node.h
	g++ -c Node.cpp
    
MyStack.o: MyStack.cpp MyStack.h
	g++ -c MyStack.cpp
    
MyList.o: MyList.cpp MyList.h
	g++ -c MyList.cpp
    
MyQueue.o: MyQueue.cpp MyQueue.h
	g++ -c MyQueue.cpp
    
Island.o: Island.cpp Island.h
	g++ -c Island.cpp