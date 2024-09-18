enum Opcode {
  LOAD = 0x00,
  ADD = 0x01,
  SUB = 0x02,
  JMP = 0x03,
  JE = 0x04,
  JNE = 0x05,
  MOV = 0x06,
  intrruput = 0x21
};

#include <cstdint>
#include <iostream>
#include <vector>
#include <windows.h>

struct VMState {
  std::vector<uint8_t> memory;    // 存储字节码
  std::vector<int32_t> registers; // 寄存器
  size_t ip = 0;                  // 指令指针
};