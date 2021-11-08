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
        if(x==centimeter || x==inch || x==feet || x==meter)
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

    public: double szorzo(int i)
    {
        if(mertek[i]==meter)
        {
            return 1;
        }else if(mertek[i]==centimeter)
        {
            return 0.01;
        }else if(mertek[i]==feet)
        {
            return 0.3048;
        }else if(mertek[i]==inch)
        {
            return 0.0254;
        }
    }

    public: double szorzom()
    {
        if(x==meter)
        {
            return 1;
        }else if(x==centimeter)
        {
            return 1/0.01;
        }else if(x==feet)
        {
            return 1/0.3048;
        }else if(x==inch)
        {
            return 1/0.0254;
        }
    }


    public: void atvalt()
    {
        vector<double>ertek;

        for(int i=0;i<szam.size();i++)
        {
            ertek.push_back(szam[i] * szorzo(i));
            szam[i]=ertek[i];
            mertek[i]="m";
        }
        sort(szam.begin(),szam.end());

        for(int i=0;i<szam.size();i++)
        {
            szam[i]=szam[i] * szorzom();
            mertek[i]=x;
        }
    }

    public: void sorbarendez()
    {
        vector<double>ertek;
        int atmenet1=0;
        int atmenet2=0;
        string atmenets1="";

        for(int i=0;i<szam.size();i++)
        {
            ertek.push_back(szam[i] * szorzo(i));
        }

        for(int i=0;i<ertek.size();i++)
        {
            for(int j=i;j<ertek.size();j++)
            {
                if(ertek[i]>ertek[j])
                {
                    atmenet1=ertek[i];
                    atmenet2=szam[i];
                    atmenets1=mertek[i];
                    ertek[i]=ertek[j];
                    szam[i]=szam[j];
                    mertek[i]=mertek[j];
                    ertek[j]=atmenet1;
                    szam[j]=atmenet2;
                    mertek[j]=atmenets1;
                }
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
        cout<<"Elfogadott mertekegysegek: "<<meter<<", "<<centimeter<<", "<<inch<<", "<<feet<<endl;
        cout<<"A program elfogadja szokozzel, illetve anelkul is a hosszusagokat. (Akar felvaltva is)"<<endl;
        cout<<"Negativ szamokat pozitivra cserel. Ha eleget irt be, irjon be valamit, ami nem mertekegyseg! (pl.: x)"<<endl;
        cout<<"(| jel kilep a programbol.)"<<endl;

        int temp=0;
        stringstream ss;
        mertek.push_back("");

        while(cin>>mertek[temp])
        {
            try
            {
                szam.push_back(stod(mertek[temp]));
                ss<<szam[szam.size()-1];
                if(mertek[temp].find('.')==-1)
                {
                    x=mertek[temp].substr((ss.str()).size(),mertek[temp].size()-(ss.str()).size());
                    y=mertek[temp].substr(0,(ss.str()).size());
                }else{
                    if(ss.str().size()+1<mertek[temp].size())
                    {
                        szam.push_back(mertek[temp].find('.')+1);
                        mertek.push_back(mertek[temp].substr(szam[temp+1],mertek[temp].size()-szam[temp+1]));
                        szam[temp+1]=stoi(mertek[temp+1]);
                        ss.str("");
                        ss<<(int)szam[temp];
                        y=ss.str();
                        y+=".";
                        ss.str("");
                        ss<<szam[temp+1];
                        y+=ss.str();
                        x=mertek[temp].substr(y.size(),mertek[temp].size()-y.size());
                        szam.pop_back();
                        mertek.pop_back();
                    }else{
                        x=mertek[temp].substr((ss.str()).size(),mertek[temp].size()-(ss.str()).size());
                        y=mertek[temp].substr(0,(ss.str()).size());
                        }
                }
                if(mertekegyseg())
                {
                    mertek[temp]=x;
                    if(abs(stod(y))!=stod(y))
                    {
                        y=y.substr(1,y.size()-1);
                        cout<<"Negativ szam nincs ertelmezve. -"<<y<<" javitva: "<<y<<endl;
                    }
                    szam.pop_back();
                    szam.push_back(stod(y));
                }else if(y==mertek[temp])
                {
                    cin>>x;
                    if(mertekegyseg())
                    {
                        mertek[temp]=x;
                        if(abs(stod(y) != stod(y)))
                        {
                            y=y.substr(1,y.size()-1);
                            cout<<"Negativ szam nincs ertelmezve. -"<<y<<" javitva: "<<y<<endl;
                        }
                        szam.pop_back();
                        szam.push_back(stod(y));
                    }else{
                        cout<<mertek[temp]<<" ervenytelen. Beolvasas vege."<<endl;
                        break;
                    }
                }else
                {
                        cout<<mertek[temp]<<" ervenytelen. Beolvasas vege."<<endl;
                        szam.pop_back();
                        break;
                }
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
            ss.str("");
            mertek.push_back("");
        }
        mertek.pop_back();

        cout<<endl;
        cout<<"Beolvasott ertekek:"<<endl;
        for(int i=0;i<szam.size();i++)
        {
            cout<<szam[i]<<mertek[i]<<endl;
        }
        cout<<endl;

        sorbarendez();

        cout<<"Elemszam: "<<szam.size()<<endl;
        cout<<"Sorbarendezes utan:"<<endl;
        for(int i=0;i<szam.size();i++)
        {
            cout<<szam[i]<<mertek[i]<<endl;
        }
        cout<<endl;
        cout<<"Elemszam: "<<szam.size()<<endl;
        cout<<"Legkisebb: "<<szam[0]<<mertek[0]<<endl;
        cout<<"Legnagyobb: "<<szam[szam.size()-1]<<mertek[mertek.size()-1]<<endl;
        cout<<endl;

        cout<<"Milyen mertekegysegben szeretne dolgozni? (pl.: in, ft, m, cm)"<<endl;
        cout<<"(Ervenytelen ertek eseten meter lesz az eredmeny.)"<<endl;
        cin>>x;
        cout<<endl;
        if(mertekegyseg()==false)
        {
            x="m";
        }

        atvalt();

        cout<<"Ertekek atvaltas utan:"<<endl;
        for(int i=0; i<szam.size();i++)
        {
            cout<<szam[i]<<mertek[i]<<endl;
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
