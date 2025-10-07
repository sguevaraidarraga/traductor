#include "core/instruction/Instruction.h"

void instruction_init(Instruction* instr, const char* mnemonic, InstructionType type, unsigned int line, uint32_t address, uint32_t pc) {
    if (!instr) return;
    instr->line = line;
    string_init(&instr->mnemonic, mnemonic);
    instr->type = type;
    instr->opcode = instr->rs = instr->rt = instr->rd = instr->shamt = instr->funct = 0;
    instr->immediate = 0;
    instr->address = address;
    instr->pc = pc;
}
void instruction_destructor(Instruction* instr) {
    if (!instr) return;
    string_destructor(&instr->mnemonic);
}
int parse_instruction(Instruction* instr, const char* line) {
    if (!instr || !line) return 0;
    // Simple parsing: extract mnemonic (first word)
    char mnemonic[32] = {0};
    sscanf(line, "%31s", mnemonic);
    string_assign(&instr->mnemonic, mnemonic);
    // Example: set type based on mnemonic (real implementation should be more robust)
    if (strcmp(mnemonic, "add") == 0 || strcmp(mnemonic, "sub") == 0) {
        instr->type = INSTR_TYPE_R;
    } else if (strcmp(mnemonic, "lw") == 0 || strcmp(mnemonic, "sw") == 0) {
        instr->type = INSTR_TYPE_I;
    } else if (strcmp(mnemonic, "j") == 0) {
        instr->type = INSTR_TYPE_J;
    } else {
        instr->type = INSTR_TYPE_UNKNOWN;
    }
    // Other fields should be parsed here as needed.
    return 1;
}
void print_instruction(const Instruction* instr) {
    if(!instr) return;
    printf("Line: %u | Mnemonic: %s | Type: %d | Opcode: %u | rs: %u | rt: %u | rd: %u | shamt: %u | funct: %u | imm: %u | addr: %u | pc: %u\n",
        instr->line,
        string_c_str(&instr->mnemonic),
        instr->type,
        instr->opcode,
        instr->rs,
        instr->rt,
        instr->rd,
        instr->shamt,
        instr->funct,
        instr->immediate,
        instr->address,
        instr->pc
    );
}