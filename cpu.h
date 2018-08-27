struct Instruction {
  const char *name;
  const char *addr_mode;
  int length;
  int cycles;
};

class Cpu {
public:
  Cpu();
  void reset();
  void step();
  void dump_instructions();

private:
  int tick_counter;
  unsigned char a;
  unsigned char x;
  unsigned char y;
  unsigned char s;
  unsigned char p;
  unsigned short pc;
  Instruction instructions[256];

  void setup_instructions();
  void handle_BRK(int addr_mode);
  void handle_JSR(int addr_mode);
  void handle_RTI(int addr_mode);
  void handle_RTS(int addr_mode);
  void handle_PHP(int addr_mode);
  void handle_PLP(int addr_mode);
  void handle_PHA(int addr_mode);
  void handle_PLA(int addr_mode);
  void handle_DEY(int addr_mode);
  void handle_TAY(int addr_mode);
  void handle_INY(int addr_mode);
  void handle_INX(int addr_mode);
  void handle_BPL(int addr_mode);
  void handle_BMI(int addr_mode);
  void handle_BVC(int addr_mode);
  void handle_BVS(int addr_mode);
  void handle_BCC(int addr_mode);
  void handle_BCS(int addr_mode);
  void handle_BNE(int addr_mode);
  void handle_BEQ(int addr_mode);
  void handle_CLC(int addr_mode);
  void handle_SEC(int addr_mode);
  void handle_CLI(int addr_mode);
  void handle_SEI(int addr_mode);
  void handle_TYA(int addr_mode);
  void handle_CLV(int addr_mode);
  //void handle_CLD(int addr_mode);
  //void handle_SED(int addr_mode);
  void handle_TXA(int addr_mode);
  void handle_TAX(int addr_mode);
  void handle_DEX(int addr_mode);
  void handle_TXS(int addr_mode);
  void handle_TSX(int addr_mode);
  void handle_NOP(int addr_mode);

  void handle_BIT(int addr_mode);
  void handle_JMP(int addr_mode);
  void handle_JMPIND(int addr_mode);
  void handle_STY(int addr_mode);
  void handle_LDY(int addr_mode);
  void handle_CPY(int addr_mode);
  void handle_CPX(int addr_mode);
  void handle_ORA(int addr_mode);
  void handle_AND(int addr_mode);
  void handle_EOR(int addr_mode);
  void handle_ADC(int addr_mode);
  void handle_STA(int addr_mode);
  void handle_LDA(int addr_mode);
  void handle_CMP(int addr_mode);
  void handle_SBC(int addr_mode);
  void handle_ASL(int addr_mode);
  void handle_ROL(int addr_mode);
  void handle_LSR(int addr_mode);
  void handle_ROR(int addr_mode);
  void handle_STX(int addr_mode);
  void handle_LDX(int addr_mode);
  void handle_DEC(int addr_mode);
  void handle_INC(int addr_mode);
};
