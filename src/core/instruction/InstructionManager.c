#include "core/instruction/InstructionManager.h"

void instruction_manager_init(InstructionManager* manager, const uint32_t start_address) {
    if(!manager) return;
    vector_init(&manager->instructions, sizeof(Instruction));
    manager->start_address = start_address;
    manager->current_address = start_address;
}
void instruction_manager_destructor(InstructionManager* manager) {
    if(!manager) return;
    for(int i = 0; i < manager->instructions.size; i++) {
        Instruction* instr = vector_at(&manager->instructions, i);
        instruction_destructor(instr);
    }
    vector_destructor(&manager->instructions);
}
void instruction_manager_add(InstructionManager* manager, const Instruction* instr) {
    if(!manager || !instr) return;
    vector_push_back(&manager->instructions, instr);
    manager->current_address++;
}
Instruction* instruction_manager_get(InstructionManager* manager, const int index) {
    if(!manager || index >= manager->instructions.size) return NULL;
    return (Instruction*)vector_at(&manager->instructions, index);
}
size_t instruction_manager_size(const InstructionManager* manager) {
    if(!manager) return 0;
    return manager->instructions.size;
}
void instruction_manager_print(const InstructionManager* manager) {
    if(!manager) return;
    for(int i = 0; i < manager->instructions.size; i++) {
        const Instruction* instr = vector_at(&manager->instructions, i);
        print_instruction(instr);
    }
}