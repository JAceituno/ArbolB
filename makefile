btree.exe:	node.o tree.o main.o
	g++ node.o tree.o main.o

node.o: node.cpp node.hpp
	g++ -c node.cpp

tree.o: tree.cpp tree.hpp node.hpp
	g++ -c tree.cpp

clean:
	rm *.o *.out