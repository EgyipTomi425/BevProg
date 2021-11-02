#include "my.h"
//using namespace Y; k�s�bb van deklar�lva

namespace X
{
    int var=1;
    void printvar(){
        cout<<"X's var: "<<var<<endl;
    }
}

namespace Y
{
    int var=2;
    void printvar(){
        cout<<"Y's var: "<<var<<endl;
    }
}

namespace Z
{
    int var=3;
    void printvar(){
        cout<<"Z's var: "<<var<<endl;
    }
}

swap_r(int& a, int& b)
{
    int c=a;
    a=b;
    b=c;
    //nem m�k�dik konstans referenci�val, illetve sima int bemeneti param�terrel
}

swap_r2(int a, int b)
{
    int c=a;
    a=b;
    b=c;
    //nem m�k�dik konstans referenci�val, illetve sima int bemeneti param�terrel
}

/*swap_r3(const int a,const int b)
{
    int c=a;
    a=b;
    b=c;
    //nem m�k�dik konstans referenci�val, illetve sima int bemeneti param�terrel
    //ett�l fejre�ll a program
}*/

int main()
{
    int x=7;
    int y=9;
    cout<< "x is: " << x << " y is: " << y <<endl;
    swap_r(x,y);
    //constansokkal nem m�k�dik, double-llel sem j�, mert intet haszn�ltunk
    cout<< "After swap: x is: " << x << " y is: " << y <<endl;

    cout<<endl;
    X::var=7;
    X::printvar();

    using namespace Y;
    var=9;
    printvar();

    Z::var=11;
    Z::printvar();

}
