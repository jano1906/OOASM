#include "Id.h"
#include <cstring>

Id::Id(const char *name) {
    size_t len = strlen(name);

    if(len < 1 || len > 10)
        throw wrongIdentifierException();
    else
        this->id = std::string(name);
}

bool Id::operator<(const Id &a) const {
    return this->id < a.id;
}

bool Id::operator==(const Id &a) const {
    return this->id == a.id;
}


