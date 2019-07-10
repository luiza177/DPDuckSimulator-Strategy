#include "Duck.h"

// TODO: Reorganize  .h and files
// TODO: re-work with smart pointers

int main(int argc, char const *argv[])
{
    Duck* mallard = new MallardDuck();
    mallard->display();
    mallard->performFly();
    mallard->performQuack();

    Duck* model = new ModelDuck();
    model->display();
    model->performQuack();
    model->performFly();
    model->setFlyBehavior(new FlyWithRocket());
    model->performFly();
    
    delete mallard;
    delete model;

    return 0;
}
