#include <bits/stdc++.h>

class Printer
{
private:
    Printer(){};

public:
    static Printer *getInstance()
    {
        static Printer self;
        return &self;
    }

    void print()
    {
        std::cout << "Hey I'm printer\n";
    }
};

int main()
{
    auto printer = Printer::getInstance();
    printer->print();
}