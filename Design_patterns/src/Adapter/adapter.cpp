#include <bits/stdc++.h>

using namespace std;

class IndianSocket
{
public:
    void charge()
    {
        cout << "Chargin from Indian socket\n";
    }
};

class USSocket
{
public:
    virtual void charge() = 0;
};

class Adapter : public USSocket
{
    IndianSocket indSock;

public:
    virtual void charge()
    {
        indSock.charge();
    }
};

int main()
{
    USSocket *usSOcket = new Adapter;
    usSOcket->charge();
    return 0;
}