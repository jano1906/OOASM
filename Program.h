#ifndef JO418361_PK418346_PROGRAM_H
#define JO418361_PK418346_PROGRAM_H

#include <memory>
#include <vector>
#include "Instructions.h"

using instructionList_t = std::vector<instruction_t>;

class program {
    instructionList_t instructionList;
    size_t read_it;
public:
    program(std::initializer_list<instruction_t> initializerList);
    const Instruction& next();
    void restartIterator();
    size_t size();
};

#endif //JO418361_PK418346_PROGRAM_H
