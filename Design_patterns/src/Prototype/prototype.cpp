#include <bits/stdc++.h>

class House
{
public:
    std::string roof;
    std::string wall;
    std::string floor;

public:
    House()
    {
    }
    House(House *ptr)
    {
        this->floor = ptr->floor;
        this->wall = ptr->wall;
        this->roof = ptr->roof;
    }
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
    House *clone()
    {
        return new House(this);
    }
};

std::ostream &operator<<(std::ostream &os, House hse)
{
    os << hse.roof << hse.wall << hse.floor;
    return os;
}

int main()
{
    House hse;
    hse.setRoof("wood roof\t");
    hse.setWall("wood wall\t");
    hse.setFloor("wood floor\n");
    std::cout << hse;

    auto hse1 = hse.clone();
    std::cout << *hse1;
    return 0;
}