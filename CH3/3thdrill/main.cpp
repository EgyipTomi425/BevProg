#include <iostream>
#include <list>
#include "std_lib_facilities.h"
using namespace std;

class osztaly
{
    list<string>sor;
    list<string>::iterator l;
    string felado;
    string cimzett;
    string barat;
    char nem='0';
    int age=0;


    public: void ujsor(string bemenetisor)
    {
        sor.push_back(bemenetisor);
    }

    public: void lastsormod(string bemenetisor)
    {
        sor.pop_back();
        sor.push_back(bemenetisor);
        //random norvég komment
    }

    public: void qlevelnez()
    {
        string answer;
        cout<<"Meg akarod nezni a leveled? (y/n)"<<endl;
        cin >> answer;
        if(answer=="y")
        {
            mutasslevel();
            //random norveg komment
        }
    }

    public: void mutasslevel()
    {
        for(l=sor.begin(); l!=sor.end(); l++)
            {
                cout<<*l<<endl;
                //random norveg komment
            }
    }

    public: string utolsosor()
    {
        l=sor.end();
        l--;
        return *l;
    }

    public: void go()
    {
        cout<<"A programot irta: Menyhart Tamas"<<endl;

        cout<<"Add meg a neved!"<<endl;
        cin>>felado;
        cout<<"Szia, "<<felado<<"!"<<endl;
        ujsor("Felado: "+felado);

        cout<<"Add meg a cimzett nevet!"<<endl;
        cin>>cimzett;
        ujsor("Kedves, "+cimzett);
        ujsor("Hogy vagy? En jol. Hianyzol. Mit csinalsz mostanaban? En mar fel napja szenvedek egy programmal, mert a valtozok hatokore miatt nem ismeri fel a fuggveny a korabban deklaralt valtozokat :D");

        cout<<"Adja meg egy masik baratja nevet, hogy megemlitse ot is!"<<endl;
        cin>>barat;
        ujsor("Reg láttam "+barat+"t is.");
        ujsor("Lattad mostanaban "+barat+"t?");
        qlevelnez();
        //random norvég komment

        cout<<"Ferfi vagy no a megemlitett baratod? (f/n)"<<endl;
        cin>>nem;
        if(nem=='f')
        {
            lastsormod("Lattad mostanában a baratunkat?");
        }else if(nem=='n'){
            lastsormod("Lattad mostanaban a baratnonket?");
        }else{
            lastsormod("Lattad mostanaban ot?");
        }
        ujsor("Ha igen, mondd neki, hogy hivjon fel!");

        cout<<"Hany eves a cimzett?"<<endl;
        cin>>age;
        if(age<1 || age>109)
        {
            simple_error("Vicces vagy...");
        }else if(age<12 && age>0)
        {
            stringstream ss;
            ss<<age;
            ujsor("Hallottam nemreg volt a szulinapod, utolag is gratulalok, hogy mar "+ss.str()+" eves vagy!");
            stringstream sa;
            sa<<age+1;
            ujsor("Jovore mar "+sa.str()+" eves leszel!");
        }else if(age==17)
        {
            stringstream ss;
            ss<<age;
            ujsor("Hallottam nemreg volt a szulinapod, utolag is gratulalok, hogy mar "+ss.str()+" eves vagy!");
            ujsor("Jovore mar tudsz szavazni is :)");
        }else if(age>70 && age<110)
        {
            stringstream ss;
            ss<<age;
            ujsor("Hallottam nemreg volt a szulinapod, utolag is gratulalok, hogy mar "+ss.str()+" eves vagy!");
            ujsor("Remelem jol telnek a nyugdijas evek");
        }else{
            stringstream ss;
            ss<<age;
            ujsor("Hallottam nemreg volt a szulinapod, utolag is gratulalok, hogy mar "+ss.str()+" eves vagy!");
        }

        ujsor("Tisztelettel:");
        ujsor("");
        ujsor("");
        ujsor(felado);

        mutasslevel();
    }
};

int main()
{
    osztaly o;
    //random norveg komment
    o.go();
    return 0;
}
