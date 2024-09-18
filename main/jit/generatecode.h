#include "../vm.h"
#include <sstream>
#include <string>
#include <vector>

std::vector<uint8_t> assemble(const std::string &asm_code) {
  std::vector<uint8_t> machine_code;
  std::istringstream iss(asm_code);
  std::string line;

  while (std::getline(iss, line)) {
    std::istringstream line_stream(line);
    std::string instruction;
    line_stream >> instruction;

    if (instruction == "LOAD") {
      int32_t value;
      line_stream >> value;
      machine_code.push_back(LOAD);
      machine_code.push_back(value);
    } else if (instruction == "ADD") {
      int32_t reg;
      line_stream >> reg;
      machine_code.push_back(ADD);
      machine_code.push_back(reg);
    } else if (instruction == "SUB") {
      int32_t reg;
      line_stream >> reg;
      machine_code.push_back(SUB);
      machine_code.push_back(reg);
    } else if (instruction == "JMP") {
      int32_t offset;
      line_stream >> offset;
      machine_code.push_back(JMP);
      machine_code.push_back(offset);
    } else if (instruction == "JE") {
      int32_t offset;
      line_stream >> offset;
      machine_code.push_back(JE);
      machine_code.push_back(offset);
    } else if (instruction == "JNE") {
      int32_t offset;
      line_stream >> offset;
      machine_code.push_back(JNE);
      machine_code.push_back(offset);
    } else if (instruction == "MOV") {
      int32_t src_reg, dst_reg;
      line_stream >> src_reg >> dst_reg;
      machine_code.push_back(MOV);
      machine_code.push_back(src_reg);
      machine_code.push_back(dst_reg);
    }
  }

  return machine_code;
}