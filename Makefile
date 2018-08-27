default: test

test: sim
	./sim

sim: main.o cpu.o
	g++ -g -std=c++14 $+ -o $@

main.o: main.cpp cpu.h
cpu.o: cpu.cpp cpu.h instruction.h opcode.h

.cpp.o:
	g++ -g -std=c++14 -c $< -o $@
