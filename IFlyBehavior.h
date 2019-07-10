#ifndef IFLYBEHAVIOR_H
#define IFLYBEHAVIOR_H

#include <iostream>

class IFlyBehavior
{
public:
    IFlyBehavior(){}
    virtual ~IFlyBehavior(){}

    virtual void fly() = 0;
};


class FlyWithWings : public IFlyBehavior
{
public:
    FlyWithWings(){}
    virtual ~FlyWithWings(){}

    void fly() override { std::cout << "I'm flying!\n"; }
};

class FlyNoWay : public IFlyBehavior
{
public:
    FlyNoWay(){}
    virtual ~FlyNoWay(){}

    void fly() override { std::cout << "I can't fly.\n"; }
};

class FlyWithRocket : public IFlyBehavior
{
public:
    FlyWithRocket(){}
    ~FlyWithRocket(){}

    void fly() override { std::cout << "WHOOOOOOSH!\n"; }
};

#endif