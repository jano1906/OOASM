#ifndef JO418361_PK418346_OOASM_H
#define JO418361_PK418346_OOASM_H

#include "Instructions.h"
#include "Components.h"

/// ======= Components =======
num_t num(memVal_t memVal){
    return std::make_shared<Num>(Num(memVal));
}

rval_t lea(const char* name){
    return std::make_shared<Lea>(Lea(Id(name)));
}

lval_t mem(const rval_t& memAddr){
    return std::make_shared<Mem>(Mem(memAddr));
}

/// ======= Instructions =======

instruction_t data(const char* name, const num_t& val){
    return std::make_shared<Data>(Data(Id(name), val));
}

instruction_t mov(const lval_t& dst, const rval_t& src){
    return std::make_shared<Mov>(Mov(dst, src));
}

instruction_t add(const lval_t& lval, const rval_t& rval){
    return std::make_shared<Add>(Add(lval, rval));
}

instruction_t sub(const lval_t& lval, const rval_t& rval){
    return std::make_shared<Sub>(Sub(lval, rval));
}

instruction_t inc(const lval_t& lval){
    return std::make_shared<Inc>(Inc(lval));
}

instruction_t dec(const lval_t& lval){
    return std::make_shared<Dec>(Dec(lval));
}

instruction_t one(const lval_t& lval){
    return std::make_shared<One>(One(lval));
}

instruction_t ones(const lval_t& lval){
    return std::make_shared<Ones>(Ones(lval));
}

instruction_t onez(const lval_t& lval){
    return std::make_shared<Onez>(Onez(lval));
}


#endif //JO418361_PK418346_OOASM_H
