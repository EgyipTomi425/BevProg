#include <iostream>

int ga[10]={1,2,4,8,16,32,64,128,256,512};

void f(int la[], int szam)
{
    for(int i=0;i<10;i++)
    {
        std::cout<<la[i]<<std::endl;
    }
    std::cout<<std::endl;

    int* p=new int[10];
    for(int i=0;i<10;i++)
    {
        p[i]=la[i];
        std::cout<<p[i]<<std::endl;
    }
    delete[] p;
}

int main()
{
    f(ga,10);
    int aa[10]={1,2,6,24,120,720,5040,40320,362880,3628800};
    std::cout<<std::endl;
    f(aa,10);

    return 0;
}
