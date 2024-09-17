#include "../vm/vm.h"
#include <cassert>
#include <iostream>
#include <vector>

int main() {
  VMState state;
  state.registers.resize(16, 0); // 初始化16个寄存器
  state.memory = {
      LOAD, 5,   // 将5加载到寄存器0
      ADD,  1,   // 将寄存器1的值加到寄存器0
      SUB,  1,   // 将寄存器1的值从寄存器0中减去
      JE,   3,   // 如果寄存器0等于0，则跳转到位置3
      MOV,  0, 1 // 将寄存器0的值移动到寄存器1
  }; // 示例字节码
  execute(state);

  // 打印寄存器0的值
  std::cout << "Register 0: " << state.registers[0] << std::endl;
  std::cout << "Register 1: " << state.registers[1] << std::endl;

  return 0;
}