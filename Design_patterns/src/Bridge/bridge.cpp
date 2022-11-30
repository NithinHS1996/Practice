#include <bits/stdc++.h>

using namespace std;

class Device
{
public:
    int volume;
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void setVol(int vol) = 0;
    virtual int getVol() = 0;
};

class Tv : public Device
{
public:
    virtual void on()
    {
        cout << "Swithced TV on\n";
    }
    virtual void off()
    {
        cout << "Swithced TV off\n";
    }
    virtual void setVol(int vol)
    {
        volume = vol;
    }
    virtual int getVol()
    {
        return volume;
    }
};

class Remote
{
    Device *dev;

public:
    Remote(Device *Dev) : dev(Dev) {}
    void incVolume()
    {
        dev->setVol(dev->getVol() + 1);
    }

    void decVolume()
    {
        dev->setVol(dev->getVol() - 1);
    }

    void on()
    {
        dev->on();
    }

    void off()
    {
        dev->off();
    }
};

int main()
{
    Device *dev = new Tv;
    Remote remote(dev);
    remote.on();
    remote.off();
    return 0;
}