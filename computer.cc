#include "computer.h"

void Computer::boot(program& prog) {
    processor.exec(prog, memory);
}

void Computer::memory_dump(std::ostream &ostream) const {
    memory.dump(ostream);
}

Computer::Computer(size_t size)
    : memory(size) {}