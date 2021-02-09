#include "Flags.h"

void Flags::setSF(bool val) {
    SF_val = val;
}

void Flags::setZF(bool val) {
    ZF_val = val;
}

Flags::Flags()
        : SF_val(false), ZF_val(false) {}

bool Flags::SF() {
    return SF_val;
}

bool Flags::ZF() {
    return ZF_val;
}