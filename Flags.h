//
// Created by jan-dev on 15.01.2021.
//

#ifndef JO418361_PK418346_FLAGS_H
#define JO418361_PK418346_FLAGS_H

class Flags {
    bool SF_val;
    bool ZF_val;
public:
    Flags();
    void setSF(bool val);
    void setZF(bool val);
    bool SF();
    bool ZF();
};


#endif //JO418361_PK418346_FLAGS_H
