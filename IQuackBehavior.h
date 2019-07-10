#ifndef IQUACKBEHAVIOR_H
#define IQUACKBEHAVIOR_H

#include <iostream>

class IQuackBehavior
{
public:
    IQuackBehavior(){}
    virtual ~IQuackBehavior(){}

    virtual void quacking() = 0;
};


class Quack : public IQuackBehavior
{
public:
    Quack(){}
    virtual ~Quack(){}

    void quacking() override { std::cout << "Quack!\n"; }
};

class Squeak : public IQuackBehavior
{
public:
    Squeak();
    virtual ~Squeak(){}

    void quacking() override { std::cout << "Squeak!\n"; }
};

class NoQuack : public IQuackBehavior
{
public:
    NoQuack(){}
    virtual ~NoQuack(){}

    void quacking() override { std::cout << "...\n"; }
};

#endif