#ifndef INSTRUCTIONMANAGER_H
#define INSTRUCTIONMANAGER_H

#include <stdint.h>
#include <stdio.h>
#include "core/instruction/Instruction.h"
#include "structures/vector.h"

typedef struct {
    vector instructions;
    uint32_t start_address, current_address;
} InstructionManager;

void instruction_manager_init(InstructionManager* manager, uint32_t start_address);
void instruction_manager_destructor(InstructionManager* manager);
void instruction_manager_add(InstructionManager* manager, const Instruction* instr);
Instruction* instruction_manager_get(InstructionManager* manager, size_t index);
size_t instruction_manager_size(const InstructionManager* manager);
void instruction_manager_print(const InstructionManager* manager);

#endif