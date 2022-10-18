#include "../include/CheckBlock.h"


unsigned int CheckBlock::getUseCount() const
{
    return useCount;
}

void CheckBlock::incrementCount()
{
    ++useCount;
}

void CheckBlock::decrementCount()
{
    if(useCount>1) {
        --useCount;
    }
    else
    {
        delete this;
    }
}

Toy* CheckBlock::getToy()
{
    return toy;
}

CheckBlock::~CheckBlock()
{
    cout<<"CheckBlock is deleted "<< this<<endl;
    if(useCount>0 && toy != nullptr){delete toy;}
}