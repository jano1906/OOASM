#ifndef JO418361_PK418346_MEMORY_H
#define JO418361_PK418346_MEMORY_H

#include "Id.h"
#include <cstdint>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <exception>

class variableDoesNotExistException : public std::exception {
public:
    [[nodiscard]] const char * what() const noexcept override{
        return "Variable does not exist";
    }
};

class indexOutOfBoundsException : public std::exception {
public:
    [[nodiscard]] const char * what() const noexcept override{
        return "Index out of bounds";
    }
};

using memVal_t = int64_t;
using memAddr_t = uint64_t;
using memArr_t = std::vector<memVal_t>;
using variableArr_t = std::unordered_map<Id, memAddr_t>;

class Memory {
    memArr_t memArr;
    variableArr_t variableArr;
    memAddr_t w_idx;
public:
    explicit Memory(size_t size);
    memVal_t getMemVal(memAddr_t memAddr) const;
    memAddr_t getMemAddr(const Id& name) const;
    void varDecl(const Id& name, memVal_t memVal);
    void set(memAddr_t memAddr, memVal_t memVal);
    void dump(std::ostream& ostream) const;
    void reset();
};


#endif //JO418361_PK418346_MEMORY_H
