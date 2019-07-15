#ifndef DUCKSMART_H
#define DUCKSMART_H
#include <memory>
#include "IFlyBehavior.h"
#include "IQuackBehavior.h"

/////////////////////ABSTRACT BASE///////////////
class Duck
{
public:
    Duck() {}
    virtual ~Duck(){}
    void performFly()
    {
        m_FlyBehavior->fly();
    }
    void performQuack()
    {
        m_QuackBehavior->quacking();
    }
    void setFlyBehavior(std::unique_ptr<IFlyBehavior> fb) 
    {
        m_FlyBehavior = std::move(fb);
    }
    void setQuackBehavior(std::unique_ptr<IQuackBehavior> qb)
    {
        m_QuackBehavior = std::move(qb);
    }

    virtual void display() = 0;
protected:    
    std::unique_ptr<IFlyBehavior> m_FlyBehavior = nullptr;
    std::unique_ptr<IQuackBehavior> m_QuackBehavior = nullptr;
};


///////////////////CONCRETES//////////////////////////
class MallardDuck : public Duck
{
public:
    MallardDuck() 
    {
        m_FlyBehavior = std::make_unique<FlyWithWings>();
        m_QuackBehavior = std::make_unique<Quack>();
    }
    virtual ~MallardDuck(){}

    void display() override { std::cout << "I look like a mallard!\n"; }
};

class ModelDuck : public Duck
{
public:
    ModelDuck()
    {
        m_FlyBehavior = std::make_unique<FlyNoWay>();
        m_QuackBehavior = std::make_unique<NoQuack>();
    }
    virtual ~ModelDuck(){}
    void display() override { std::cout << "I look like a model duck!\n"; }
};

#endif