#ifndef HOMEWORK_31_5_1_SHAREDTOYPTR_H
#define HOMEWORK_31_5_1_SHAREDTOYPTR_H

#include <iostream>
#include "CheckBlock.h"

class SharedToyPtr{

private:
    CheckBlock* checkBlock;
public:
    SharedToyPtr() : checkBlock(nullptr){};
    SharedToyPtr(Toy* toy):checkBlock(new CheckBlock(toy)){};
    SharedToyPtr(string toyName):checkBlock(new CheckBlock(toyName)){};
    ~SharedToyPtr();
    SharedToyPtr(const SharedToyPtr& other);
    SharedToyPtr& operator = (const SharedToyPtr& oth);
    unsigned int getUseCount() const;
    void reset();
    Toy* get();
    CheckBlock* getCheckBlock();
};

SharedToyPtr makeSharedToy(string name);
SharedToyPtr makeSharedToy(Toy* toy);

#endif //HOMEWORK_31_5_1_SHAREDTOYPTR_H
