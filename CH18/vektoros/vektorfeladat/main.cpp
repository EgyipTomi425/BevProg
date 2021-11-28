#include <iostream>
#include <vector>

std::vector<int>gv={1,2,4,8,16,32,64,128,256,512};

void f(std::vector<int>lv)
{
    for(int i=0;i<10;i++)
    {
        std::cout<<lv[i]<<std::endl;
    }
    std::cout<<std::endl;

    std::vector<int>* p=new std::vector<int>;
    for(int i=0;i<10;i++)
    {
        p->push_back(lv[i]);
        std::cout<<(*p)[i]<<std::endl;
    }
    delete p;
}

int main()
{
    f(gv);
    std::vector<int>vv={1,2,6,24,120,720,5040,40320,362880,3628800};
    std::cout<<std::endl;
    f(vv);

    return 0;
}
