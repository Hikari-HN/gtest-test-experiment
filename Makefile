all:
	g++ -o test.o -fprofile-arcs -ftest-coverage -lgtest -pthread -c test.cpp
	g++ -o test test.o -lgtest -pthread -fprofile-arcs -ftest-coverage
	./test
	gcov -b test.cpp
	lcov -c -d . -o test.info
	genhtml test.info -o ./output
clean:
	rm test *.gcno *.gcda *.o *.info *.gcov
	rm -rf output