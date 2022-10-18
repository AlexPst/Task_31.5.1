#include "../include/SharedToyPtr.h"

SharedToyPtr makeSharedToy(string name)
{
    return {name};
}

SharedToyPtr makeSharedToy(Toy* toy)
{
    if(toy == nullptr)
    {
        return SharedToyPtr();
    }
    else
    {
      return {toy};
    }
}

unsigned int SharedToyPtr::getUseCount() const {
    if(checkBlock== nullptr)
    {
        return 0;
    }
    else
    {
        return checkBlock->getUseCount();
    }
}

void SharedToyPtr::reset() {
    if(checkBlock == nullptr)
    {
        return;
    }
    else
    {
        checkBlock->decrementCount();
        checkBlock = nullptr;
    }
}

SharedToyPtr::SharedToyPtr(const SharedToyPtr &other)
{
    if(other.checkBlock != nullptr)
    {
        this->checkBlock = other.checkBlock;
        this->checkBlock->incrementCount();
    }
}

SharedToyPtr& SharedToyPtr::operator=(const SharedToyPtr &other) {
    if(this->checkBlock == other.checkBlock)
    {
        return *this;
    }
    else if (this->checkBlock != nullptr)
    {
        this->checkBlock->decrementCount();
    }else {
        this->checkBlock = other.checkBlock;
    }
    if(this->checkBlock != nullptr)
    {
        this->checkBlock->incrementCount();
    }
    return *this;
}

Toy* SharedToyPtr::get() {
    if(checkBlock == nullptr)
    {
        return nullptr;
    }
    else
    {
        return checkBlock->getToy();
    }
}

CheckBlock* SharedToyPtr::getCheckBlock() {
    return checkBlock;
}

SharedToyPtr::~SharedToyPtr() {
    cout<<"SharedPtr is deleted "<<this<<endl;
    if(checkBlock != nullptr)
    {
        checkBlock->decrementCount();
    }
}