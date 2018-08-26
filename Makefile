default: test

test: sim
	./sim

sim: main.o cpu.o
	g++ -g -std=c++14 $+ -o $@

cpu.o: cpu.cpp instruction.h

.cpp.o:
	g++ -g -std=c++14 -c $< -o $@
