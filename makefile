all:
	g++ main.cpp scanner.cpp scanner.h token.cpp token.cpp util.cpp util.h parser.cpp parser.h node.cpp node.h -o P2 -std=c++11
