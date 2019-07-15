#include "DuckSmart.h"

int main(int argc, char const *argv[])
{
    auto mallard = std::make_unique<MallardDuck>();
    mallard->display();
    mallard->performFly();
    mallard->performQuack();

    auto model = std::make_unique<ModelDuck>();
    model->display();
    model->performQuack();
    model->performFly();
    model->setFlyBehavior(std::make_unique<FlyWithRocket>());
    model->performFly();
    
    return 0;
}
