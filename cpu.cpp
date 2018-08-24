#include <iostream>
#include <sstream>
#include <algorithm>
#include "cpu.h"

using namespace std;

typedef void InstructionHandler(void);

struct InstructionTable {
  InstructionHandler *instruction_handler;
  const char *name;
};

void handle_BRK() {
  cout << "HANDLE_BRK" << endl;
}

#define INSTRUCTION(NAME, CODE, LENGTH, CYCLES, MEM_ACCESS_TYPE) { handle_##NAME, #NAME },
InstructionTable instruction_table[] = {
#include "instruction.h"
};
#undef INSTRUCTION

void dump_instructions() {
  const size_t nr_instructions = (sizeof(instruction_table) / sizeof(instruction_table[0]));
  for (int i = 0; i < nr_instructions; ++i) {
    cout << instruction_table[i].name << endl;
  }
}
