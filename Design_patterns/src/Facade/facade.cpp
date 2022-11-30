#include <bits/stdc++.h>

using namespace std;

class Door
{
public:
    void open()
    {
        cout << "Door open\n";
    }
};

class Fan
{
public:
    void on()
    {
        cout << "Fan on\n";
    }
};

class Lights
{
public:
    void on()
    {
        cout << "Lights on\n";
    }
};

class Home
{
    Door door;
    Fan fan;
    Lights lights;

public:
    void enter()
    {
        cout << "Entering home......\n";
        door.open();
        fan.on();
        lights.on();
    }
};

int main()
{
    Home home;
    home.enter();
    return 0;
}