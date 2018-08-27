#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include "cpu.h"
#include "opcode.h"

static const unsigned short reset_vector = 0xfffc;

Cpu::Cpu() {
  setup_instructions();
  reset();
}

void Cpu::reset() {
  tick_counter = 0;
  a = x = y = 0;
  s = 0xff;
  p = 0;
  pc = reset_vector;
}

void Cpu::step() {
  unsigned char i = 0;
  switch (i) {
#define SINGLE_INSTRUCTION(NAME, LENGTH, CYCLES) case OP_##NAME: handle_##NAME(0); tick_counter += CYCLES; break;
#define INSTRUCTION(NAME, ADDR1, ADDR2, LENGTH, CYCLES) case OP_##NAME | ((ADDR1_OP_##ADDR1 | ADDR2_OP_##ADDR2) << 2): handle_##NAME(ADDR1_OP_##ADDR1 | ADDR2_OP_##ADDR2); tick_counter += CYCLES; break;
#include "instruction.h"
#undef SINGLE_INSTRUCTION
#undef INSTRUCTION
  default:
    // invalid instruction
    break;
  }
}

void Cpu::dump_instructions() {
  for (int i = 0; i < 256; ++i) {
    if (instructions[i].name) {
      printf("%02x: %s %s\n", i, instructions[i].name, instructions[i].addr_mode ? instructions[i].addr_mode : "");
    }
  }
}

void Cpu::setup_instructions() {
  std::fill(instructions, instructions + 256, Instruction());
#define SINGLE_INSTRUCTION(NAME, LENGTH, CYCLES) instructions[OP_##NAME] = {#NAME, NULL, LENGTH, CYCLES};
#define INSTRUCTION(NAME, ADDR1, ADDR2, LENGTH, CYCLES) instructions[OP_##NAME | ((ADDR1_OP_##ADDR1 | ADDR2_OP_##ADDR2) << 2)] = {#NAME, #ADDR1 #ADDR2, LENGTH, CYCLES};
#include "instruction.h"
#undef SINGLE_INSTRUCTION
#undef INSTRUCTION
}

void Cpu::handle_BRK(int addr_mode) {
  std::cout << "HANDLE_BRK" << std::endl;
}

void Cpu::handle_JSR(int addr_mode) {
}

void Cpu::handle_RTI(int addr_mode) {
}

void Cpu::handle_RTS(int addr_mode) {
}

void Cpu::handle_PHP(int addr_mode) {
}

void Cpu::handle_PLP(int addr_mode) {
}

void Cpu::handle_PHA(int addr_mode) {
}

void Cpu::handle_PLA(int addr_mode) {
}

void Cpu::handle_DEY(int addr_mode) {
}

void Cpu::handle_TAY(int addr_mode) {
}

void Cpu::handle_INY(int addr_mode) {
}

void Cpu::handle_INX(int addr_mode) {
}

void Cpu::handle_BPL(int addr_mode) {
}

void Cpu::handle_BMI(int addr_mode) {
}

void Cpu::handle_BVC(int addr_mode) {
}

void Cpu::handle_BVS(int addr_mode) {
}

void Cpu::handle_BCC(int addr_mode) {
}

void Cpu::handle_BCS(int addr_mode) {
}

void Cpu::handle_BNE(int addr_mode) {
}

void Cpu::handle_BEQ(int addr_mode) {
}

void Cpu::handle_CLC(int addr_mode) {
}

void Cpu::handle_SEC(int addr_mode) {
}

void Cpu::handle_CLI(int addr_mode) {
}

void Cpu::handle_SEI(int addr_mode) {
}

void Cpu::handle_TYA(int addr_mode) {
}

void Cpu::handle_CLV(int addr_mode) {
}

#if 0
void Cpu::handle_CLD(int addr_mode) {
}

void Cpu::handle_SED(int addr_mode) {
}
#endif

void Cpu::handle_TXA(int addr_mode) {

}

void Cpu::handle_TAX(int addr_mode) {

}

void Cpu::handle_DEX(int addr_mode) {

}

void Cpu::handle_TXS(int addr_mode) {

}

void Cpu::handle_TSX(int addr_mode) {

}

void Cpu::handle_NOP(int addr_mode) {

}

void Cpu::handle_BIT(int addr_mode) {
}

void Cpu::handle_JMP(int addr_mode) {
}

void Cpu::handle_JMPIND(int addr_mode) {
}

void Cpu::handle_STY(int addr_mode) {
}

void Cpu::handle_LDY(int addr_mode) {
}

void Cpu::handle_CPY(int addr_mode) {
}

void Cpu::handle_CPX(int addr_mode) {
}

void Cpu::handle_ORA(int addr_mode) {
}

void Cpu::handle_AND(int addr_mode) {
}

void Cpu::handle_EOR(int addr_mode) {
}

void Cpu::handle_ADC(int addr_mode) {
}

void Cpu::handle_STA(int addr_mode) {
}

void Cpu::handle_LDA(int addr_mode) {
}

void Cpu::handle_CMP(int addr_mode) {
}

void Cpu::handle_SBC(int addr_mode) {
}

void Cpu::handle_ASL(int addr_mode) {
}

void Cpu::handle_ROL(int addr_mode) {
}

void Cpu::handle_LSR(int addr_mode) {
}

void Cpu::handle_ROR(int addr_mode) {
}

void Cpu::handle_STX(int addr_mode) {
}

void Cpu::handle_LDX(int addr_mode) {
}

void Cpu::handle_DEC(int addr_mode) {
}

void Cpu::handle_INC(int addr_mode) {
}
