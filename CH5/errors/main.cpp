#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

class osztaly
{
    public:void o1()
    {
        cout << "Success!\n";
    }
    public:void o2()
    {
        cout << "Success!\n";
    }
    public:void o3()
    {
        cout << "Success!" << '\n';
    }
    public:void o4()
    {
        cout << "Success!" << '\n';
    }
    public:void o5()
    {
        int res = 7;
        vector<int> v(10);
        v[5] = res;
        cout << "Success!\n";
    }
    public:void o6()
    {
        vector<int> v(10);
        v[5] = 7;
        if (v[5]!=7)
        cout << "Success!\n";
    }
    public:void o7()
    {
        bool cond=true;
        if (cond) cout << "Success!\n";
        else cout << "Fail!\n";
    }
    public:void o8()
    {
        bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
    }
    public:void o9()
    {
        string s = "ape"; bool c=true; if (c) cout << "Success!\n";
    }
    public:void o10()
    {
        string s = "fool"; if (s=="fool") cout << "Success!\n";
    }
    public:void o11()
    {
        string s = "ape"; if (s=="fool") cout << "Success!\n";
    }
    public:void o12()
    {
        string s = "ape"; if (s=="ape") cout << "Success!\n";
    }
    public:void o13()
    {
        vector<char> v(5);
        for (int i=0; i<v.size(); ++i)
        cout << "Success!\n";
    }
    public:void o14()
    {
        vector<char> v(5);
        for (int i=0; i<v.size(); ++i)
        cout << "Success!\n";
    }
    public:void o15()
    {
        string s = "Success!\n";
        for (int i=0; i<1; ++i) cout << s;
    }
    public:void o16()
    {
        if (true)  cout << "Success!\n"; else cout << "Fail!\n";
    }
    public:void o17()
    {
        int x = 1; char c = x; if (c==1) cout << "Success!\n";
    }
    public:void o18()
    {
        string s = "Success!"; for (int i=0; i<1; ++i) cout << s <<endl;
    }
    public:void o19()
    {
        vector<int> v(5); for (int i=0; i<v.size(); ++i) cout << "Success!\n";
    }
    public:void o20()
    {
        int i=0; int j = 9; while (i<10) ++i; if (j<i) cout << "Success!\n";
    }
    public:void o21()
    {
         int x = 3;
         double d = 5 / (x-2);
         if (d==5) cout << "Success!\n";
    }
    public:void o22()
    {
        vector<string> s(11,"Success!"); for (int i=0; i<=10; ++i) cout << s[i];
    }
    public:void o23()
    {
        int i,j=0; while (i<10){ ++i; if (j<i) cout << "Success!\n";}
    }
    public:void o24()
    {
        int x = 4; double d = 5 / (x-2); if (d==2.5) cout << "Success!\n";
    }
    public:void o25()
    {
        cout<<"Success!"<<endl;
    }
};

int main()
{
    osztaly o;
    o.o1();
    o.o2();
    o.o3();
    o.o4();
    o.o5();
    o.o6();
    o.o7();
    o.o8();
    o.o9();
    o.o10();
    o.o11();
    o.o12();
    o.o13();
    o.o14();
    o.o15();
    o.o16();
    o.o17();
    o.o18();
    o.o19();
    o.o20();
    o.o21();
    o.o22();
    o.o23();
    o.o24();
    o.o25();
}
