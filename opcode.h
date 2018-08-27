static const int OP_BRK = 0;
static const int OP_JSR = 1 << 5;
static const int OP_RTI = 2 << 5;
static const int OP_RTS = 3 << 5;

static const int OP_PHP = (0 << 5) | 8;
static const int OP_PLP = (1 << 5) | 8;
static const int OP_PHA = (2 << 5) | 8;
static const int OP_PLA = (3 << 5) | 8;
static const int OP_DEY = (4 << 5) | 8;
static const int OP_TAY = (5 << 5) | 8;
static const int OP_INY = (6 << 5) | 8;
static const int OP_INX = (7 << 5) | 8;

static const int OP_BPL = (0 << 5) | 0x10;
static const int OP_BMI = (1 << 5) | 0x10;
static const int OP_BVC = (2 << 5) | 0x10;
static const int OP_BVS = (3 << 5) | 0x10;
static const int OP_BCC = (4 << 5) | 0x10;
static const int OP_BCS = (5 << 5) | 0x10;
static const int OP_BNE = (6 << 5) | 0x10;
static const int OP_BEQ = (7 << 5) | 0x10;

static const int OP_CLC = (0 << 5) | 0x18;
static const int OP_SEC = (1 << 5) | 0x18;
static const int OP_CLI = (2 << 5) | 0x18;
static const int OP_SEI = (3 << 5) | 0x18;
static const int OP_TYA = (4 << 5) | 0x18;
static const int OP_CLV = (5 << 5) | 0x18;
static const int OP_CLD = (6 << 5) | 0x18;
static const int OP_SED = (7 << 5) | 0x18;

static const int OP_TXA = (4 << 5) | 0xa;
static const int OP_TAX = (5 << 5) | 0xa;
static const int OP_DEX = (6 << 5) | 0xa;
static const int OP_NOP = (7 << 5) | 0xa;
static const int OP_TXS = (4 << 5) | 0x1a;
static const int OP_TSX = (5 << 5) | 0x1a;

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
