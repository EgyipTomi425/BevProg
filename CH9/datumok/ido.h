//Program megírásában segített: Tóth Kristóf
#include "std_lib_facilities.h"
#include <vector>
static const int honapszam[12]={31,28,31,30,31,30,31,31,30,31,30,31};

struct date
{
private:
    int ev,ho,nap;

    int napokhonapban(int y,int m)
    {
        if(m==2)
        {
            if(szokoev(ev))
            {
                return honapszam[m-1]+1;
            }
            return honapszam[m-1];
        }else
        {
            return honapszam[m-1];
        }
    }

public:
    date(int y, int m, int d)
    {
        ev=y;
        ho=m;
        nap=d;
        if(isvaliddate()==false)
        {
            simple_error("Bad date!");
        }
    }

    date()
    {
        ev=2000;
        ho=1;
        nap=1;
    }

     bool isvaliddate()
    {
        if(ev>2200 || ev<1800 || ho>12 || ho<1 || nap>31 || nap<1)
        {
            return false;
        }else
        {
            if(nap<29)
            {
                return true;
            }else
            {
                if(napokhonapban(ev,ho)<nap)
                {
                    return false;
                }else
                {
                    return true;
                }
            }
        }
    }

    static bool szokoev(int y)
    {
        if(y%400==0 || (y%4==0 && y%100!=0))
        {
            return true;
        }else
        {
            return false;
        }
    }

    void addev(int y)
    {
        ev+=y;
        if(isvaliddate()==false)
        {
            simple_error("Bad date!");
        }
    }

    void addho(int m)
    {
        ho+=m;
        ev=ev+((int)ho/12);
        ho%=12;
        if(ho==0)
        {
            ho=12;
        }
        for(int i=0;i<4;i++)
        {
            if(isvaliddate())
            {
                break;
            }else if(i==4)
            {
                simple_error("Bad date!");
            }else
            {
                nap=nap-1;
            }
        }
        if(!isvaliddate())
        {
            simple_error("Bad date!");
        }
    }

    void addnap(int n)
    {
        while (n > (napokhonapban(ev,ho))-nap) {
        n-=napokhonapban(ev,ho)-day()+1;
        nap=1;
        ho++;
        if (ho>12) {
        ev++;
        ho=1;
        }
       }
       nap=nap+n;
       if(isvaliddate()==false)
       {
           simple_error("Bad date!");
       }
    }

    int year() const
    {
        return ev;
    }

    int month() const
    {
        return ho;
    }

    int day() const
    {
        return nap;
    }
};

ostream& operator<<(ostream& os, const date& d)
    {
        return os << '(' << d.year()<< ',' << d.month()<< ',' << d.day() << ')'<<endl;
    }

//if(date::szokoev(2004))cout<<"Szokoev"<<endl;
