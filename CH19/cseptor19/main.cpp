#include <iostream>
#include <vector>

template<typename t>
struct s
{
private:
    t val;

public:
    s(t x)
    {
        val=x;
    }

    t get()const;

    t& get();

    void kiir()
    {
        std::cout<<val<<std::endl;
    }

    void operator=(const t& stemp)
    {
        val=stemp;
    }
};

template<typename t>
t s<t>::get()const
{
     return val;
}

template<typename t>
t& s<t>::get()
{
     return val;
}

template<typename t>
std::ostream& operator<<(std::ostream& os,s<t>& stemp)
{
    return os<<stemp.get();
}

template<typename t>
std::istream& operator>>(std::istream& is,s<t>& stemp)
{
    return is>>stemp.get();
}

void kiirvector(std::ostream& os,std::vector<int>vektor)
{
    std::cout<<"Vector elemei:"<<std::endl;
    for(int i=0;i<vektor.size();i++)
    {
        std::cout<<vektor[i]<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    s<int>sint(42);
    sint.kiir();
    s<char>schar('C');
    schar.kiir();
    s<double>sdouble(4.2);
    sdouble.kiir();
    s<std::vector<int>>svector({32,21,5,12});
    kiirvector(std::cout,svector.get());

    std::cout<<std::endl;
    std::cout<<sint.get()<<std::endl;
    std::cout<<schar.get()<<std::endl;
    std::cout<<sdouble.get()<<std::endl;
    kiirvector(std::cout,svector.get());
    std::cout<<std::endl;

    std::cout<<"Irjon be inputot!"<<std::endl;
    std::cin>>sint;
    std::cout<<sint<<std::endl;
    std::cin>>schar;
    std::cout<<schar<<std::endl;
    std::cin>>sdouble;
    std::cout<<sdouble<<std::endl;

    return 0;
}
