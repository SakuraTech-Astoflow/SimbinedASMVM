#include "../main/vm.h"

int main() {
    VMState state;
    state.registers.resize(16, 0); // 初始化16个寄存器
    state.memory = {
      LOAD,
      5,
      ADD,
      1,
      SUB,
      1,
      JE,3,

      
      }; // 示例字节码

    execute(state);

    // 打印寄存器0的值
    std::cout << "Register 0: " << state.registers[0] << std::endl;

    return 0;
}