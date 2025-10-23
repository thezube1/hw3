CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test stack-test heap-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec-test.cpp llrec.cpp
	$(CXX) $(CXXFLAGS) llrec-test.cpp llrec.cpp -o llrec-test

stack-test: stack-test.cpp stack.h
	$(CXX) $(CXXFLAGS) stack-test.cpp -o stack-test

heap-test: heap-test.cpp heap.h
	$(CXX) $(CXXFLAGS) heap-test.cpp -o heap-test

clean:
	rm -f *.o rh llrec-test stack-test heap-test*~

.PHONY: clean 