
#ifndef HOMEWORK_31_5_1_CHECKBLOCK_H
#define HOMEWORK_31_5_1_CHECKBLOCK_H

#include "Toy.h"

class CheckBlock{

private:
    unsigned int useCount;
    Toy* toy;

public:
    CheckBlock(Toy* toy):useCount(1), toy(new Toy(*toy)){};
    CheckBlock(string toyName) : useCount(1), toy(new Toy(toyName)){};
    ~CheckBlock();
    unsigned int getUseCount() const;
    void incrementCount();
    void decrementCount();
    Toy* getToy();
};



#endif //HOMEWORK_31_5_1_CHECKBLOCK_H
