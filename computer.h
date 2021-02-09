#ifndef JO418361_PK418346_COMPUTER_H
#define JO418361_PK418346_COMPUTER_H

#include <vector>
#include <iostream>
#include "Memory.h"
#include "Program.h"
#include "Processor.h"

class Computer {
    Memory memory;
    Processor processor;
public:
    explicit Computer(size_t size);
    void boot(program& prog);
    void memory_dump(std::ostream& ostream) const;
};




#endif //JO418361_PK418346_COMPUTER_H