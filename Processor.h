//
// Created by jan-dev on 14.01.2021.
//

#ifndef JO418361_PK418346_PROCESSOR_H
#define JO418361_PK418346_PROCESSOR_H

#include "Program.h"
#include "Flags.h"
#include "Memory.h"

class Processor {
private:
    Flags flags;
public:
    Processor();
    void exec(program& prog, Memory& memory);
};


#endif //JO418361_PK418346_PROCESSOR_H
