#include "../registers.h"


class JITCompiler {
public:
  JITCompiler(ASMRunnerTrafficLight &state) : state(state) {}

  void loadInstructions(const std::vector<Instruction> &instructions) {
    this->instructions = instructions;
  }

  void execute() {
    while (ip < instructions.size()) {
      const Instruction &instr = instructions[ip];
      switch (instr.opcode) {
      case LOAD:
        load(instr.arg1, instr.arg2);
        break;
      case ADD:
        add(instr.arg1, instr.arg2);
        break;
      case SUB:
        sub(instr.arg1, instr.arg2);
        break;
      case JMP:
        jmp(instr.arg1);
        break;
      case JE:
        je(instr.arg1, instr.arg2);
        break;
      case JNE:
        jne(instr.arg1, instr.arg2);
        break;
      case MOV:
        mov(instr.arg1, instr.arg2);
        break;
      case INT:
        intHandler();
        break;
      default:
        std::cerr << "Unknown opcode: " << static_cast<int>(instr.opcode)
                  << std::endl;
        break;
      }
      ++ip;
    }
  }

  void printRegisters() const {
    for (size_t i = 0; i < state.registers.size(); ++i) {
      std::cout << "Register " << i << ": " << state.registers[i] << std::endl;
    }
  }

private:
  ASMRunnerTrafficLight &state;
  std::vector<Instruction> instructions;
  size_t ip;

  void load(int32_t reg, int32_t value) {
    state.registers[reg] = value;
  }

  void add(int32_t reg1, int32_t reg2) {
    state.registers[reg1] += state.registers[reg2];
  }

  void sub(int32_t reg1, int32_t reg2) {
    state.registers[reg1] -= state.registers[reg2];
  }

  void jmp(int32_t target) {
    ip = target;
  }

  void je(int32_t reg, int32_t target) {
    if (state.registers[reg] == 0) {
      ip = target;
    }
  }

  void jne(int32_t reg, int32_t target) {
    if (state.registers[reg] != 0) {
      ip = target;
    }
  }

  void mov(int32_t reg1, int32_t reg2) {
    state.registers[reg1] = state.registers[reg2];
  }

  void intHandler() {
    // 处理中断
  }
};

