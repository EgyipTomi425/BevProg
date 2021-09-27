#include "std_lib_facilities.h"

class osztaly
{
    string x;
    string y;
    vector<string>mertek;
    vector<double>szam;

    const string meter={"m"};
    const string centimeter={"cm"};
    const string inch={"in"};
    const string feet={"ft"};

    public: bool mertekegyseg()
    {
        if(y==meter || y==centimeter || y==inch || y==feet)
        {
            return true;
        }else{
            return false;
        }
    }

    public: void kiirv()
    {
        for(int i=0;i<szam.size();i++)
        {
            cout<<szam[i]<<endl;
        }
    }

    public: void sortszam()
    {
        double temp;
        for(int i=0;i<szam.size();i++)
        {
            for(int j=i;j<szam.size();j++)
            {
                if(szam[i]<szam[j])
                {
                    temp=szam[i];
                    szam[i]=szam[j];
                    szam[j]=temp;
                }
            }
        }
    }

    public: void osszehasonlito()
    {
        cout<<"Tobbszor szereplo szamok: "<<endl;

        vector<double>temp;
        double temp2=0;

        for(int i=0;i<szam.size();i++)
        {
            for(int j=0;j<temp.size();j=j+2)
            {
                if(szam[i]==temp[j])
                {
                    temp[j+1]++;
                    temp2++;
                    break;
                }
            }
            temp.push_back(szam[i]);
            temp.push_back(1);
        }

        for(int i=0;i<temp.size();i=i+2)
        {
            if(temp[i+1]>1)
            {
                cout<<temp[i]<<" ("<<temp[i+1]<<"x)"<<endl;
            }
        }

        if(temp2==0)
        {
            cout<<"Minden szamot csak egyszer irtunk le."<<endl;
        }else
        {
            cout<<temp2<<" alkalommal irtuk le ujra valamelyik szamot."<<endl;
        }
        temp2=0;

        cout<<endl;
        cout<<"A szamok (ismetles nelkul) novekvo sorrendben:"<<endl;

        for(auto it=szam.begin();it!=szam.end();it++)
        {
            if(temp2<szam.size()-1 && szam[temp2]==szam[temp2+1])
            {
               szam.erase(it);
               it--;
               temp2--;
            }
            temp2++;
        }

        for (auto it = szam.begin(); it != szam.end(); ++it)
        {
            cout << ' ' << *it<<endl;
        }
        cout<<endl;

        cout<<"Az alabbi szamok majdnem egyenloek (kisebb, mint 0.01 elteres):"<<endl;

        for(int i=0;i<szam.size();i++)
        {
            for(temp2=1;i-temp2>=0 && szam[i]-szam[i-temp2]<0.01 && szam[i]!=szam[i-temp2];temp2++)
            {
                cout<<szam[i]<<" majdnem egyenlo "<<szam[i-temp2]<<" ("<<szam[i]-szam[i-temp2]<<") elteres."<<endl;
            }
        }
    }

    public: void go()
    {
        cout<<endl;
        cout<<"Beolvasott szamok: "<<endl;
        kiirv();

        cout<<endl;
        cout<<"Sorbarendezes utan (csokkeno):"<<endl;
        sortszam();
        kiirv();

        cout<<endl;
        cout<<"Sorbarendezes utan (novekvo):"<<endl;
        sort(szam.begin(),szam.end());
        kiirv();

        cout<<endl;
        cout<<"Legkisebb: "<<szam[0]<<endl;
        cout<<"Legnagyobb: "<<szam[szam.size()-1]<<endl;

        cout<<endl;
        osszehasonlito();
    }

    public: void verzio1()
    {
        cout<<"Ez a verzio 1! Adjon meg szamokat! (Utolso szam utan tegyen egy szokozt es irjon be egy betut!)"<<endl;
        cout<<"(| jel kilep a programbol.)"<<endl;

        while(cin>>x)
        {
            try
            {
                if(stoi(x)==stod(x))
                {
                    szam.push_back(stoi(x));
                }else
                {
                    szam.push_back(stoi(x));
                    cout<<"Szam kerekitve: "<<szam[szam.size()-1]<<endl;
                }
            }catch(invalid_argument)
            {
                if(x=="|")
                {
                    simple_error("Program vege!");
                }else{
                    cout<<x<<" ervenytelen. Beolvasas vege."<<endl;
                    break;
                }
            }
        }
        go();
    }

    public: void verzio2()
    {
        cout<<"Ez a verzio 2! Adjon meg szamokat! (Utolso szam utan tegyen egy szokozt es irjon be egy betut!)"<<endl;
        cout<<"(| jel kilep a programbol.)"<<endl;

        while(cin>>x)
        {
            try
            {
                szam.push_back(stod(x));
            }catch(invalid_argument)
            {
                if(x=="|")
                {
                    simple_error("| parancs vegrehajtva. Program vege!");
                }else{
                    cout<<x<<" ervenytelen. Beolvasas vege."<<endl;
                    break;
                }
            }
        }
        go();
    }

    public: void verzio3()
    {
        cout<<"Ez a verzio 3! Adjon meg hosszusagokat mertekegyseggel! (pl. 12m vgy 5 cm)"<<endl;
        cout<<"A program elfogadja szokozzel, illetve anelkul is a hosszusagokat. (Akar felvaltva is)"<<endl;
        cout<<"Negativ szamokat pozitivra cserel. Ha eleget irt be, irjon be valami, ami nem mertekegyseg!"<<endl;
        cout<<"(| jel kilep a programbol.)"<<endl;

        int temp=0;

        while(cin>>mertek[temp])
        {
            try
            {
                szam.push_back(stod(mertek[temp]));
            }catch(invalid_argument)
            {
                if(mertek[temp]=="|")
                {
                    simple_error("| parancs vegrehajtva. Program vege!");
                }else if(mertekegyseg() && szam.size()>0)
                {
                    try
                    {
                        szam.push_back(stod(mertek[temp]));
                        //Igen, így ha pl. beírjuk, hogy 12m cm, akkor a másodiket úgy fogja
                        //venni, hogy 12cm, de ez érvényes mérték, egy "h"-t nem fogadna el.
                        //ez csak egy autocorrect funkció

                    }catch(invalid_argument)
                    {
                        cout<<mertek[temp]<<" ervenytelen. Beolvasas vege."<<endl;
                        break;
                    }
                }else
                {
                    cout<<mertek[temp]<<" ervenytelen. Beolvasas vege."<<endl;
                    break;
                }
            }
            temp++;
        }
    }
};

int main()
{
    cout << "A programot irta: Menyhart Tamas." << endl;
    osztaly o;
    string valasztas;
    cout<<"Melyik verziot szeretne betolteni? 1 / 2 /3 ?"<<endl;
    cout<<"(1. - Egesz szamokkal dolgozik. (Ha nem egesz szamot ad meg, lekerekiti.))"<<endl;
    cout<<"(2. - Valos szamokkal dolgozik.)"<<endl;
    cout<<"(3. - Tavolsagertekekkel dolgozik. (Negativ tavolsagot pozitivra cserel.))"<<endl;
    cin>>valasztas;

    if(valasztas=="1")
    {
        o.verzio1();
    }else if(valasztas=="2"){
        o.verzio2();
    }
    else if(valasztas=="3")
    {
        o.verzio3();
    }else
    {
        cout<<"Ervenytelen ertek. Program vege."<<endl;
    }

    return 0;
}
