#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class pontok
{
private:
    double x;
    double y;

public:
    pontok(int a,int b)
    {
        x=a;
        y=b;
    }
/*    void addpont(int a, int b)
    {
        x.push_back(a);
        y.push_back(b);
    }
*/
    double getpontx()
    {
        return x;
    }

    double getponty()
    {
        return y;
    }

    void printpoints()
    {
        cout<<"( "<<x<<" , "<<y<<" )"<<endl;
    }

/*    int pontszam()
    {
        return x.size();
    }
*/
};

int main()
{
    double x,y;
    vector<pontok>pont1;

    cout<<"Irjon be 7 pontot az alabbi formatumban: 'x y'!"<<endl;
    for(int i=0; i<7; i++)
    {
        cin>>x;
        cin>>y;
        pont1.push_back(pontok(x,y));
        cout<<"( "<<pont1[i].getpontx()<<" , "<<pont1[i].getponty()<<" )"<<endl;
    }

    ofstream fki;
    fki.open("mydata.txt");
    for(int i=0;i<pont1.size();i++)
    {
        fki<<"( "<<pont1[i].getpontx()<<" , "<<pont1[i].getponty()<<" )"<<endl;
    }
    fki.close();

    ifstream fbe;
    fbe.open("mydata.txt");
    string a;
    int i=0;
    vector<pontok>pont2;
    while(!fbe.eof())
    {
        fbe>>a;
        fbe>>x;
        fbe>>a;
        fbe>>y;
        fbe>>a;
        pont2.push_back(pontok(x,y));
    }
    pont2.pop_back();

    fbe.close();
    cout<<endl<<"Elemek beolvasva:"<<endl;
    for(int i=0;i<pont2.size();i++)
    {
        cout<<"( "<<pont2[i].getpontx()<<" , "<<pont2[i].getponty()<<" )"<<endl;
    } //eredetit már egyszer megmutattam, de amúgy "p.printpoints();"

    cout<<endl<<"Elemszam: "<<pont2.size()<<endl;
    return 0;
}
