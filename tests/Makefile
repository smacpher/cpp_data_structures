tests_main.o: tests_main.cpp catch.hpp
	g++ -std=c++11 tests_main.cpp -c
test_stack: tests_main.o test_stack.cpp
	g++ -std=c++11 tests_main.o test_stack.cpp -o temp && ./temp -s -d yes; rm temp
test_queue: tests_main.o test_queue.cpp
	g++ -std=c++11 tests_main.o test_queue.cpp -o temp && ./temp -s -d yes; rm temp
reset:
	rm tests_main.o
