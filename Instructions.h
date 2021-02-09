#ifndef JO418361_PK418346_INSTRUCTIONS_H
#define JO418361_PK418346_INSTRUCTIONS_H

#include <memory>
#include "Memory.h"
#include "Flags.h"
#include "Components.h"

class Instruction {
public:
    virtual void exec(Memory& memory, Flags& flags) const = 0;
    virtual void decl(Memory& memory) const = 0;
};
using instruction_t = std::shared_ptr<Instruction>;

class Declarable : public Instruction{
    void exec(Memory&, Flags&) const final {}
};

class Data : public Declarable {
    Id name;
    memVal_t memVal;
public:
    Data(Id name, const num_t& val);
    void decl(Memory &memory) const override;
};

class Executable : public Instruction {
public:
    void decl(Memory&) const final {}
};

class Mov : public Executable {
    lval_t dst;
    rval_t src;
public:
    Mov(lval_t dst, rval_t src);
    void exec(Memory& memory, Flags& flags) const override;
};

class Arithmetic : public Executable {
protected:
    lval_t lval;
public:
    explicit Arithmetic(lval_t lval);
    void exec(Memory& memory, Flags& flags) const final;
    virtual memVal_t compute(Memory& memory) const = 0;
};

class Add : public Arithmetic {
    rval_t rval;
public:
    memVal_t compute(Memory& memory) const override;
    Add(lval_t lval, rval_t rval);
};

class Sub : public Arithmetic {
    rval_t rval;
public:
    memVal_t compute(Memory& memory) const override;
    Sub(lval_t lval, rval_t rval);
};

class Inc : public Arithmetic {
public:
    memVal_t compute(Memory& memory) const override;
    Inc(lval_t lval);
};

class Dec : public Arithmetic {
public:
    memVal_t compute(Memory& memory) const override;
    Dec(lval_t lval);
};

class One : public Executable{
    lval_t lval;
public:
    void exec(Memory& memory, Flags&) const override;
    One(lval_t lval);
};

class Ones : public Executable {
    lval_t lval;
public:
    void exec(Memory& memory, Flags& flags) const override;
    Ones(lval_t lval);
};

class Onez : public Executable {
    lval_t lval;
public:
    void exec(Memory& memory, Flags& flags) const override;
    Onez(lval_t lval);
};

#endif //JO418361_PK418346_INSTRUCTIONS_H
