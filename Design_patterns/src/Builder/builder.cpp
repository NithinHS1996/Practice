#include <bits/stdc++.h>

class House
{
public:
    std::string roof;
    std::string wall;
    std::string floor;

public:
    void setRoof(std::string l_roof)
    {
        roof = l_roof;
    }
    void setWall(std::string l_wall)
    {
        wall = l_wall;
    }
    void setFloor(std::string l_floor)
    {
        floor = l_floor;
    }
};

std::ostream &operator<<(std::ostream &os, House hse)
{
    os << hse.roof << hse.wall << hse.floor;
    return os;
}

class HouseBuilder
{
public:
    virtual void buildRoof() = 0;
    virtual void buildWall() = 0;
    virtual void buildFloor() = 0;
    virtual House getHouse() = 0;
};

class WoodenHouseBuilder : public HouseBuilder
{
    House house;

public:
    virtual void buildRoof()
    {
        house.setRoof("wood roof\n");
    }
    virtual void buildWall()
    {
        house.setWall("wood wall\n");
    }
    virtual void buildFloor()
    {
        house.setFloor("wood floor\n");
    }
    virtual House getHouse()
    {
        return house;
    }
};

class ConcreteHouseBuilder : public HouseBuilder
{
    House house;

public:
    virtual void buildRoof()
    {
        house.setRoof("Concrete roof\n");
    }
    virtual void buildWall()
    {
        house.setWall("Concrete wall\n");
    }
    virtual void buildFloor()
    {
        house.setFloor("Concrete floor\n");
    }
    virtual House getHouse()
    {
        return house;
    }
};

class Director
{
public:
    void buildHouse(std::shared_ptr<HouseBuilder> builder)
    {
        builder->buildFloor();
        builder->buildWall();
        builder->buildRoof();
    }
};

int main()
{
    auto woodHsebldr = std::make_shared<WoodenHouseBuilder>(WoodenHouseBuilder());
    Director director;
    director.buildHouse(woodHsebldr);
    House hse = woodHsebldr->getHouse();
    std::cout << hse;
    return 0;
}