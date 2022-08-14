AFLCOV = /home/hikari/afl-cov/afl-cov
AFLCXX = afl-g++
AFLFLAGS = -lgtest -pthread -fprofile-arcs -ftest-coverage
TARGET = afl_test

all:
	mkdir fuzz_out
	$(AFLCXX) -g -o $(TARGET).o $(AFLFLAGS) -c $(TARGET).cpp
	$(AFLCXX) -g -o $(TARGET) $(TARGET).o $(AFLFLAGS)
	$(AFLCOV) -d ./fuzz_out --live --coverage-cmd="./$(TARGET) AFL_FILE" --code-dir .

clean:
	rm -f $(TARGET)
	rm -f $(TARGET).o
	rm -f *.gcno
	rm -f *.gcda
	rm -rf fuzz_out
