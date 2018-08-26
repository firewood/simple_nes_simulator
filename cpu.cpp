#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include "cpu.h"

using namespace std;

static const int OP_BRK = 0;

static const int OP_BIT = 1 << 5;
static const int OP_JMP = 2 << 5;
static const int OP_JMPIND = 3 << 5;
static const int OP_STY = 4 << 5;
static const int OP_LDY = 5 << 5;
static const int OP_CPY = 6 << 5;
static const int OP_CPX = 7 << 5;

static const int OP_ORA = (0 << 5) | 1;
static const int OP_AND = (1 << 5) | 1;
static const int OP_EOR = (2 << 5) | 1;
static const int OP_ADC = (3 << 5) | 1;
static const int OP_STA = (4 << 5) | 1;
static const int OP_LDA = (5 << 5) | 1;
static const int OP_CMP = (6 << 5) | 1;
static const int OP_SBC = (7 << 5) | 1;

static const int OP_ASL = (0 << 5) | 2;
static const int OP_ROL = (1 << 5) | 2;
static const int OP_LSR = (2 << 5) | 2;
static const int OP_ROR = (3 << 5) | 2;
static const int OP_STX = (4 << 5) | 2;
static const int OP_LDX = (5 << 5) | 2;
static const int OP_DEC = (6 << 5) | 2;
static const int OP_INC = (7 << 5) | 2;

static const int ADDR1_OP_ = 0;
static const int ADDR1_OP_INDZPX = 0;
static const int ADDR1_OP_ZP = 1;
static const int ADDR1_OP_IMM = 2;
static const int ADDR1_OP_ABS = 3;
static const int ADDR1_OP_INDZP_Y = 4;
static const int ADDR1_OP_ZP_X = 5;
static const int ADDR1_OP_ABS_Y = 6;
static const int ADDR1_OP_ABS_X = 7;
static const int ADDR2_OP_ = 0;
static const int ADDR2_OP_IMM = 0;
static const int ADDR2_OP_ZP = 1;
static const int ADDR2_OP_A = 2;
static const int ADDR2_OP_ABS = 3;
static const int ADDR2_OP_ZP_X = 5;
static const int ADDR2_OP_ZP_Y = 5;
static const int ADDR2_OP_ABS_X = 7;
static const int ADDR2_OP_ABS_Y = 7;

typedef void InstructionHandler(int addr_mode);

struct InstructionTable {
  InstructionHandler *instruction_handler;
  const char *name;
  unsigned char code;
  unsigned char addr_mode;
};

void handle_BRK(int addr_mode) {
  cout << "HANDLE_BRK" << endl;
}

void handle_BIT(int addr_mode) {
}

void handle_JMP(int addr_mode) {
}

void handle_JMPIND(int addr_mode) {
}

void handle_STY(int addr_mode) {
}

void handle_LDY(int addr_mode) {
}

void handle_CPY(int addr_mode) {
}

void handle_CPX(int addr_mode) {
}

void handle_ORA(int addr_mode) {
}

void handle_AND(int addr_mode) {
}

void handle_EOR(int addr_mode) {
}

void handle_ADC(int addr_mode) {
}

void handle_STA(int addr_mode) {
}

void handle_LDA(int addr_mode) {
}

void handle_CMP(int addr_mode) {
}

void handle_SBC(int addr_mode) {
}

void handle_ASL(int addr_mode) {
}

void handle_ROL(int addr_mode) {
}

void handle_LSR(int addr_mode) {
}

void handle_ROR(int addr_mode) {
}

void handle_STX(int addr_mode) {
}

void handle_LDX(int addr_mode) {
}

void handle_DEC(int addr_mode) {
}

void handle_INC(int addr_mode) {
}

#define INSTRUCTION(NAME, ADDR1, ADDR2, LENGTH, CYCLES) { handle_##NAME, #NAME "_" #ADDR1 #ADDR2, OP_##NAME | ((ADDR1_OP_##ADDR1 | ADDR2_OP_##ADDR2) << 2) },
InstructionTable instruction_table[] = {
#include "instruction.h"
};
#undef INSTRUCTION

void dump_instructions() {
  const size_t nr_instructions = (sizeof(instruction_table) / sizeof(instruction_table[0]));
  int f[256] = {};
  fill(f, f + 256, -1);
  for (int i = 0; i < nr_instructions; ++i) {
    f[instruction_table[i].code] = i;
  }
  for (int i = 0; i < 256; ++i) {
    if (f[i] >= 0) {
      printf("%s %02x\n", instruction_table[f[i]].name, instruction_table[f[i]].code);
    }
  }
}

