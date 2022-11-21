#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class size{small,medium,large};
enum class color{black,orange,white};

struct product
{
    string name;
    size esize;
    color ecolor;

};

struct filter
{
    
void filter_by_color(const product &prod, color clr)
{
    if(prod.ecolor == clr)
    {
	cout << "Products under color are: " << prod.name << "\n";
    }
}

void filter_by_size(const product &prod, size sze)
{
    if(prod.esize == sze)
    {
	cout << "Products under size are: " << prod.name << "\n";
    }
}
};

template <typename T> 
struct Specification
{
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T>
struct Filter
{
    virtual vector<T*> filter(vector<T*> items, Specification<T> &spec) = 0;
};

struct ColorSpecification:Specification<product>
{
    color clr;
    ColorSpecification(color clr):clr(clr){}
    bool is_satisfied(product* item) override
    {
	return item->ecolor == clr;
    }
}
;
struct BetterFilter:Filter<product>
{
    vector<product*> filter(vector<product*> items, Specification<product> &spec) override
    {
	vector <product*> result;
	for(auto i:items)
	{
	    if(spec.is_satisfied(i))
		result.push_back(i);
	}
	return result;
    } 
};

int main()
{
    product Apple{"Apple",size::medium,color::orange};
    product Banana{"Banana",size::medium,color::black};
    product Mango{"Mango",size::small,color::orange};

    vector<product> prod_list;
    prod_list.push_back(Apple);
    prod_list.push_back(Banana);
    prod_list.push_back(Mango);

    filter fltr;
    for(auto i : prod_list){
        fltr.filter_by_size(i, size::medium);
        fltr.filter_by_color(i, color::orange);
    }

    vector<product*> prd = {&Apple, &Banana, &Mango};
    BetterFilter bf;
    ColorSpecification clr(color::orange);
    for(auto i:bf.filter(prd,clr))
        cout << i->name << "is orange\n"; 

}
