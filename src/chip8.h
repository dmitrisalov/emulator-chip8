#ifndef CHIP8
#define CHIP8

#include <stdint.h>

#define NUM_REGISTERS 16
#define STACK_SIZE 16
#define PC_STEP_SIZE 2      // 2 bytes per instruction
#define MEMORY_SIZE 0x1000  // 4kb
#define PC_START 0x200      // 0-1ff reserved for interpreter, RAM starts here

typedef struct StateChip8 {
    // Registers
    uint8_t v[NUM_REGISTERS];       // 8-bit Vx registers           (bytes)
    uint16_t i;                     // 12-bit I register            (address)
    uint8_t dt;                     // 8-bit delay timer register   (byte)
    uint8_t st;                     // 8-bit sound timer register   (byte)

    // Memory
    uint16_t pc;                    // 12-bit program counter       (address)
    uint16_t* sp;                   // 16-bit stack                 (addresses)
    uint8_t* memory;                // 8-bit memory space, 4kb      (bytes)

    // Other
    uint16_t program_size;          // 16-bit, up to 3.5kb
    uint16_t last_opcode;           // 16-bit opcode
} StateChip8;

StateChip8* state_chip8_new();
void state_chip8_delete(StateChip8** state);
void print_state(StateChip8* state);

#endif