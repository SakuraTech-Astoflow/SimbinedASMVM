#include <cstdint>
#include <iostream>
#include <vector>

enum Opcode {
  LOAD = 0x00,
  ADD = 0x01,
  SUB = 0x02,
  JMP = 0x03,
  JE = 0x04,
  JNE = 0x05,
  MOV = 0x06,
  INT = 0x21
};

struct Instruction {
  Opcode opcode;
  int32_t arg1;
  int32_t arg2;
};

struct ASMRunnerTrafficLight {
  std::vector<int32_t> registers; // 寄存器
  size_t ip = 0;                  // 指令指针
};