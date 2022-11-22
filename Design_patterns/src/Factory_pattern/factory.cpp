#include <bits/stdc++.h>

class Pizza
{
public:
    virtual void print() = 0;
    virtual ~Pizza() {}
};

class ChickenPizza : public Pizza
{
public:
    virtual void print()
    {
        std::cout << "Chicken pizza\n";
    }
};

class VegPizza : public Pizza
{
public:
    virtual void print()
    {
        std::cout << "Veg pizza\n";
    }
};

class VegChickenPizza : public Pizza
{
public:
    virtual void print()
    {
        std::cout << "Veg nd Chicken pizza\n";
    }
};

class PizzaFactory
{
public:
    std::shared_ptr<Pizza> createPizza(std::string pizzaType)
    {
        std::shared_ptr<Pizza> ptr = NULL;
        if (pizzaType == "Chicken")
        {
            ptr = std::make_shared<ChickenPizza>(ChickenPizza());
        }
        else if (pizzaType == "Veg")
        {
            ptr = std::make_shared<VegPizza>(VegPizza());
        }
        else if (pizzaType == "ChickenVeg")
        {
            ptr = std::make_shared<VegChickenPizza>(VegChickenPizza());
        }
        return ptr;
    }
};

class PizzaStore
{
    PizzaFactory pizzaFactory;

public:
    PizzaStore(PizzaFactory &l_pizzaFactory)
    {
        pizzaFactory = l_pizzaFactory;
    }

    void orderPizza(std::string pizzaType)
    {
        auto ptr = pizzaFactory.createPizza(pizzaType);
        ptr->print();
    }
};

int main()
{
    PizzaFactory pizzaFactory;
    PizzaStore pizzaStore(pizzaFactory);
    pizzaStore.orderPizza("Chicken");
    pizzaStore.orderPizza("Veg");
    pizzaStore.orderPizza("ChickenVeg");
    return 0;
}