#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "structures/string.h"

typedef enum {
    INSTR_TYPE_R,
    INSTR_TYPE_I,
    INSTR_TYPE_J,
    INSTR_TYPE_UNKNOWN
} InstructionType;

typedef struct {
    unsigned int line;
    string mnemonic;
    InstructionType type;
    uint8_t opcode, rs, rt, rd, shamt, funct;
    uint16_t immediate;
    uint32_t address, pc;
} Instruction;

void instruction_init(Instruction* instr, const char* mnemonic, InstructionType type, unsigned int line, uint32_t address, uint32_t pc);
void instruction_destructor(Instruction* instr);
int parse_instruction(Instruction* instr, const char* line);
void print_instruction(const Instruction* instr);

#endif