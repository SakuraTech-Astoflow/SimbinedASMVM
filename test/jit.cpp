#include "../main/jit/generatecode.h"

int main() {
  std::string asm_code = R"(
    LOAD 5
    ADD 1
    SUB 2
    MOV 0, 3
    JMP 5
    JE 10
    JNE 15
  )";

  auto machine_code = assemble(asm_code);
  for (auto byte : machine_code) {
    std::cout << static_cast<int>(byte) << " ";
  }
  std::cout << std::endl;

  // 初始化虚拟机状态
  VMState state;
  state.memory = machine_code;
  execute(state);

  return 0;
}