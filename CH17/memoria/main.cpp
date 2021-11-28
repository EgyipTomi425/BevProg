#include "std_lib_facilities.h"
#include <vector>

void print_array(ostream& os, int* a)
{
    for(int i=0;i<10;i++)
    {
        os<<a[i]<<endl;
    }
}

void print_vector(ostream& os, vector<int>a)
{
    for(int i=0;i<10;i++)
    {
        os<<a[i]<<endl;
    }
}

void print_vector(ostream& os, vector<int>a, int n)
{
    for(int i=0;i<n;i++)
    {
        os<<a[i]<<endl;
    }
}

void print_array(ostream& os, int* a, int n)
{
    for(int i=0;i<n;i++)
    {
        os<<a[i]<<endl;
    }
}

void print_array2(ostream& os, int* a, int n)
{
    for(int i=0;i<n;i++)
    {
        os<<"Memoria: "<<a<<" ertek: "<<a[i]<<endl;
    }
}

int main()
{
    int* p=new int[10]{1,2,3,4,5,6,7,8,9,10};
    print_array(cout,p);
    cout<<endl;
    delete[] p;

    int* k=new int[10]{101,102,103,104,105,106,107,108,109,110};
    print_array(cout,k);
    cout<<endl;
    delete[] k;

    int* z=new int[20]{101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120};
    print_array(cout,z,20);
    cout<<endl;
    delete[] z;

    cout<<"Vector:"<<endl;
    vector<int>a;
    for(int i=0;i<20;i++) a.push_back(i);
    print_vector(cout,a);
    cout<<endl;
    print_vector(cout,a,20);

    cout<<endl<<endl<<"Program2:"<<endl;;

    int* p1=new int(7);
    cout<<"Memoria: "<<p1<<" ertek: "<<*p1<<endl;

    int* p2=new int[7]{1,2,4,8,16,32,64};
    print_array2(cout,p2,7);


    int* p3=p2;

    //nem lehet a mutatót átállítani, mert memóriaszivárgáshoz vezet

    delete[] p3;
    delete[] p1;
    delete[] p2;



    return 0;
}
