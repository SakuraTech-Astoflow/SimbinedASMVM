#include "state.h"

void execute(VMState &state) {
  while (state.ip < state.memory.size()) {
    uint8_t opcode = state.memory[state.ip++];
    switch (opcode) {
    case LOAD: // LOAD 立即数加载
      if (state.ip + 1 < state.memory.size()) {
        int32_t value = state.memory[state.ip++];
        state.registers[0] = value;
      }
      break;
    case ADD: // ADD 加法
      if (state.ip < state.memory.size()) {
        int32_t regIndex = state.memory[state.ip++];
        state.registers[0] += state.registers[regIndex];
      }
      break;
    case SUB: // SUB 减法
      if (state.ip < state.memory.size()) {
        int32_t regIndex = state.memory[state.ip++];
        state.registers[0] -= state.registers[regIndex];
      }
      break;
    case JMP: // JMP 无条件跳转
      if (state.ip < state.memory.size()) {
        int32_t offset = state.memory[state.ip++];
        state.ip = offset;
      }
      break;
    case JE: // JE 相等时跳转
      if (state.ip + 1 < state.memory.size()) {
        int32_t offset = state.memory[state.ip++];
        if (state.registers[0] == 0)
          state.ip = offset;
      }
      break;
    case JNE: // JNE 不等时跳转
      if (state.ip + 1 < state.memory.size()) {
        int32_t offset = state.memory[state.ip++];
        if (state.registers[0] != 0)
          state.ip = offset;
      }
      break;
    case intrruput:
      break;
    case MOV:
      if (state.ip + 1 < state.memory.size()) {
        int32_t srcReg = state.memory[state.ip++];
        int32_t dstReg = state.memory[state.ip++];
        if (srcReg >= state.registers.size() ||
            dstReg >= state.registers.size()) {
          std::cerr << "MOV: 寄存器索引超出范围" << std::endl;
          return;
        }
        state.registers[dstReg] = state.registers[srcReg];
      } else {
        std::cerr << "MOV: 不足的参数" << std::endl;
        return;
      }
      break;
    default:
      std::cout << "Unknown opcode" << std::endl;
      return;
    }
  }
}