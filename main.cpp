#include <iostream>
#include <sstream>
#include <algorithm>
#include "cpu.h"

using namespace std;

int main(int argc, char *argv[])
{
  Cpu cpu;
  cpu.dump_instructions();
//  dump_instructions();
  return 0;
}
