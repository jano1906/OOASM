#include "Memory.h"

Memory::Memory(size_t size)
    : memArr(size, 0), w_idx(0) {}

memAddr_t Memory::getMemAddr(const Id &name) const {
    auto it = variableArr.find(name);
    if(it == variableArr.end()){
        throw variableDoesNotExistException();
    }
    return it->second;
}

memVal_t Memory::getMemVal(memAddr_t memAddr) const {
    if(memAddr >= memArr.size())
        throw indexOutOfBoundsException();
    return memArr[memAddr];
}

void Memory::varDecl(const Id &name, memVal_t memVal) {
    auto it = variableArr.find(name);
    if(it == variableArr.end()){
        variableArr.insert({name, w_idx});
    }
    set(w_idx, memVal);
    w_idx++;
}

void Memory::set(memAddr_t memAddr, memVal_t memVal) {
    if(memAddr >= memArr.size())
        throw indexOutOfBoundsException();
    memArr[memAddr] = memVal;
}

void Memory::dump(std::ostream &ostream) const {
    for(auto x : memArr)
        ostream<<x<<" ";
}

void Memory::reset() {
    std::fill(memArr.begin(), memArr.end(), 0);
    this->variableArr.clear();
    this->w_idx = 0;
}
