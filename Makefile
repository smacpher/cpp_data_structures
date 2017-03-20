stack.o: stack.cpp stack.h
	g++ -c stack.cpp
linked_list.o: linked_list.cpp linked_list.h
	g++ -c linked_list.cpp
queue.o: queue.cpp queue.h
	g++ -c queue.cpp
clean:
	rm a.out *.o