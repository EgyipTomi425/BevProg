//Program meg�r�s�ban seg�tett: T�th Krist�f
#include "ido.h"

int main()
{
    date today(2029,2,28);
    cout<<today<<endl;
    date tomorrow=today;
    tomorrow.addnap(1);
    cout<<tomorrow<<endl;
    return 0;
}

