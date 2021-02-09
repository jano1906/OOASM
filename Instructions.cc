#include "Instructions.h"

Arithmetic::Arithmetic(lval_t lval)
    : lval(std::move(lval)) {}

void Arithmetic::exec(Memory &memory, Flags &flags) const {
    memVal_t res = compute(memory);
    lval->setVal(memory, res);
    flags.setZF(res == 0);
    flags.setSF(res < 0);
}

Data::Data(Id name, const num_t& val)
    : name(name), memVal(val->getVal()) {}

void Data::decl(Memory &memory) const {
    memory.varDecl(name, memVal);
}

Add::Add(lval_t lval, rval_t rval)
    : Arithmetic(std::move(lval)), rval(std::move(rval)){}

memVal_t Add::compute(Memory &memory) const {
    return lval->getVal(memory) + rval->getVal(memory);
}

Sub::Sub(lval_t lval, rval_t rval)
    : Arithmetic(std::move(lval)), rval(std::move(rval)){}

memVal_t Sub::compute(Memory &memory) const {
    return lval->getVal(memory) - rval->getVal(memory);
}

Inc::Inc(lval_t lval)
    : Arithmetic(std::move(lval)){}

memVal_t Inc::compute(Memory &memory) const {
    return lval->getVal(memory)+1;
}

Dec::Dec(lval_t lval)
    : Arithmetic(std::move(lval)){}

memVal_t Dec::compute(Memory &memory) const {
    return lval->getVal(memory)-1;
}

One::One(lval_t lval)
    : lval(std::move(lval)){}

void One::exec(Memory &memory, Flags&) const {
        lval->setVal(memory,1);
}

Ones::Ones(lval_t lval)
    : lval(std::move(lval)){}

void Ones::exec(Memory &memory, Flags &flags) const {
    if(flags.SF())
        lval->setVal(memory, 1);
}

Onez::Onez(lval_t lval)
    : lval(std::move(lval)){}

void Onez::exec(Memory &memory, Flags &flags) const {
    if(flags.ZF())
        lval->setVal(memory, 1);
}

Mov::Mov(lval_t dst, rval_t src)
        : dst(std::move(dst)), src(std::move(src)){}

void Mov::exec(Memory &memory, Flags&) const {
    dst->setVal(memory, src->getVal(memory));
}
