#include "Components.h"

Num::Num(memVal_t memVal)
        : val(memVal){}

memVal_t Num::getVal(const Memory&) const {
    return val;
}

memVal_t Num::getVal() const {
    return val;
}



Lea::Lea(Id name)
        : name(name) {}

memVal_t Lea::getVal(const Memory &memory) const {
    return (memVal_t) memory.getMemAddr(name);
}

Mem::Mem(rval_t memAddr)
        : memAddr(std::move(memAddr)) {}

memVal_t Mem::getVal(const Memory &memory) const {
    return memory.getMemVal(memAddr->getVal(memory));
}

void Mem::setVal(Memory &memory, memVal_t memVal) const {
    memory.set(memAddr->getVal(memory), memVal);
}
