#include "../jit/x86withx64/jitcompiler.h"

int main() {
  // 创建虚拟机状态
  ASMRunnerTrafficLight state;
  state.registers.resize(16); // 假设我们有16个寄存器

  // 创建虚拟机指令
  std::vector<Instruction> instructions = {
      {LOAD, 0, 10}, // 将10加载到寄存器0
      {LOAD, 1, 20}, // 将20加载到寄存器1
      {ADD, 0, 1},   // 寄存器0 += 寄存器1
      {MOV, 1, 0},   // 将寄存器0的值复制到寄存器1
      {INT, 0, 0}    // 触发中断
  };

  JITCompiler vm(state);
  vm.loadInstructions(instructions);
  vm.execute();

  // 打印寄存器的值
 // vm.printRegisters();

  return 0;
}