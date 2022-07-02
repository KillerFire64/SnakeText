CC=g++
EXE=snake
CPP=main.cpp snake.cpp
HPP=snake.hpp

$(EXE): $(CPP)
	$(CC) $(CPP) -o $@

count:
	wc -l $(CPP) $(HPP)
