
#ifndef HOMEWORK_31_5_1_TOY_H
#define HOMEWORK_31_5_1_TOY_H

#include <iostream>

using namespace std;
class Toy{

private:
    string name;

public:
    Toy():name("UndefinedName"){cout<<"This is new one toy: "<<name<<", "<<this<<endl;}
    Toy(string name) : name(name){cout<<"This is new one toy: "<<name<<", "<<this<<endl;}
    ~Toy();
};


#endif //HOMEWORK_31_5_1_TOY_H
