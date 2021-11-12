#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class pontok
{
private:
    vector<double>x;
    vector<double>y;

public:
    void addpont(int a, int b)
    {
        x.push_back(a);
        y.push_back(b);
    }

    double getpontx(int index)
    {
        return x[index];
    }

    double getponty(int index)
    {
        return y[index];
    }

    void printpoints()
    {
        for(int i=0;i<x.size();i++)
        {
            cout<<"( "<<x[i]<<" , "<<y[i]<<" )"<<endl;
        }
    }

    int pontszam()
    {
        return x.size();
    }
};

int main()
{
    pontok p;
    double x,y;

    cout<<"Irjon be 7 pontot az alabbi formatumban: 'x y'!"<<endl;
    for(int i=0; i<7; i++)
    {
        cin>>x;
        cin>>y;
        p.addpont(x,y);
    }
    p.printpoints();

    ofstream fki;
    fki.open("mydata.txt");
    for(int i=0;i<p.pontszam();i++)
    {
        fki<<"( "<<p.getpontx(i)<<" , "<<p.getponty(i)<<" )"<<endl;
    }
    fki.close();

    pontok p2;
    ifstream fbe;
    fbe.open("mydata.txt");
    string a;
    while(!fbe.eof())
    {
        fbe>>a;
        fbe>>x;
        fbe>>a;
        fbe>>y;
        fbe>>a;
        p2.addpont(x,y);
    }
    fbe.close();
    cout<<endl<<"Elemek beolvasva:"<<endl;
    p2.printpoints(); //eredetit már egyszer megmutattam, de amúgy "p.printpoints();"

    cout<<endl<<"Elemszam: "<<p.pontszam()<<endl;
    return 0;
}
