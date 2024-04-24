CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++17 -g
COVERAGE_FLAGS = --coverage  -fprofile-arcs -ftest-coverage
TEST_FILES = tests/main.cc tests/list/*.cc tests/vector/*.cc tests/seq_containers/*.cc
TEST_FLAGS = -lgtest -pthread
PATH_BUILD = tests/build

.PHONY : all test gcov_report leaks valgrind clean

all : test

clean :
	rm -rf $(PATH_BUILD)

valgrind :
	valgrind --leak-check=full ./tests/test

leaks :
	leaks -atExit -- ./tests/test

test : clean
	mkdir $(PATH_BUILD)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) -o $(PATH_BUILD)/test $(TEST_FLAGS)
	./$(PATH_BUILD)/test

gcov_report : test_coverage
	gcovr --html-details -o $(PATH_BUILD)/test_list.html
	open ./$(PATH_BUILD)/test_list.html

test_coverage : clean
	mkdir $(PATH_BUILD)
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) $(TEST_FILES) -o $(PATH_BUILD)/test $(TEST_FLAGS)
	./$(PATH_BUILD)/test

