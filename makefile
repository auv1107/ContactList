test.out: _main.cpp ContactInfo.h ArrayList.h HashTable.h ContactList.h
	g++ -o test.out -g -Wall _main.cpp

run: test.out
	./test.out

clean:
	rm -rf test.out
