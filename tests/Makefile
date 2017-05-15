tests_main.o: tests_main.cpp catch.hpp
	g++ tests_main.cpp -c
test_stack: tests_main.o test_stack.cpp
	g++ tests_main.o test_stack.cpp -o temp && ./temp -s -d yes; rm temp
