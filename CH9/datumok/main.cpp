//Program meg�r�s�ban seg�tett: T�th Krist�f
#include "ido.h"

int main()
{
    date today(2021,11,8);
    cout<<today<<endl;
    date tomorrow=today;
    tomorrow.addnap(1);
    cout<<tomorrow<<endl;
    return 0;
}
