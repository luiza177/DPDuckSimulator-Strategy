#ifndef DUCK_H
#define DUCK_H
#include <memory>
#include "IFlyBehavior.h"
#include "IQuackBehavior.h"

/////////////////BASE ABSTRACT/////////////////
class Duck
{
public:
    Duck() {}
    virtual ~Duck() 
    {
        delete m_FlyBehavior;
        delete m_QuackBehavior;
    }
    void performFly()
    {
        m_FlyBehavior->fly();
    }
    void performQuack()
    {
        m_QuackBehavior->quacking();
    }
    void setFlyBehavior(IFlyBehavior* fb) 
    {
        if (m_FlyBehavior != nullptr) delete m_FlyBehavior; //
        m_FlyBehavior = fb;
    }
    void setQuackBehavior(IQuackBehavior* qb)
    {
        if (m_QuackBehavior != nullptr) delete m_QuackBehavior; //
        m_QuackBehavior = qb;
    }

    virtual void display() = 0;
protected:    
    IFlyBehavior* m_FlyBehavior = nullptr; //Change to smart pointers
    IQuackBehavior* m_QuackBehavior = nullptr;
};


///////////////// CONCRETES ///////////////////
class MallardDuck : public Duck
{
public:
    MallardDuck() 
    {
        m_FlyBehavior = new FlyWithWings();
        m_QuackBehavior = new Quack();
    }
    virtual ~MallardDuck(){}

    void display() override { std::cout << "I look like a mallard!\n"; }
};

class ModelDuck : public Duck
{
public:
    ModelDuck()
    {
        m_FlyBehavior = new FlyNoWay();
        m_QuackBehavior = new NoQuack();
    }
    virtual ~ModelDuck(){}
    void display() override { std::cout << "I look like a model duck!\n"; }
};

#endif