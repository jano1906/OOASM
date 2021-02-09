#include "Processor.h"

Processor::Processor()
    : flags() {}

void Processor::exec(program &program, Memory &memory) {
    memory.reset();
    program.restartIterator();
    for(size_t i=0;i<program.size();i++)
        program.next().decl(memory);
    program.restartIterator();
    for(size_t i=0;i<program.size();i++)
        program.next().exec(memory, flags);
}
