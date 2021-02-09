#ifndef JO418361_PK418346_COMPONENTS_H
#define JO418361_PK418346_COMPONENTS_H

#include "Memory.h"
#include <memory>

class Rval {
public:
    virtual memVal_t getVal(const Memory& memory) const = 0;
};
using rval_t = std::shared_ptr<Rval>;

class Num : public Rval{
    memVal_t val;
public:
    Num(memVal_t);
    memVal_t getVal(const Memory&) const override;
    memVal_t getVal() const;
};
using num_t = std::shared_ptr<Num>;

class Lea : public Rval{
    Id name;
public:
    Lea(Id name);
    memVal_t getVal(const Memory &memory) const override;
};


class Lval : public Rval {
public:
    virtual void setVal(Memory& memory, memVal_t memVal) const = 0;
};
using lval_t = std::shared_ptr<Lval>;


class Mem : public Lval{
    rval_t memAddr;
public:
    explicit Mem(rval_t memAddr);
    void setVal(Memory &memory, memVal_t memVal) const override;
    memVal_t getVal(const Memory &memory) const override;
};

#endif //JO418361_PK418346_COMPONENTS_H
