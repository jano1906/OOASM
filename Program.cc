#include "Program.h"

program::program(std::initializer_list<instruction_t> initializerList)
    : instructionList(initializerList), read_it(0) {}

size_t program::size() {
    return instructionList.size();
}

const Instruction& program::next(){
    return *instructionList[read_it++];
}

void program::restartIterator() {
    read_it = 0;
}
