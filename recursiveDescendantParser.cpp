#include <bits/stdc++.h>
using namespace std;

//definitions
//Grammar : S'-> S#
//        : S -> XY | YX
//        : X -> mX | e
//        : Y -> nX | X | e
//first of S : [m,n,e] 
//         X : [m,e]
//         Y : [n,m,e]
void Sbar();
void S();
void X();
void Y();

char buffer[100];

int i=0,error=0;

int main()
{
    printf("Enter the input\n");
    gets(buffer);
    //starting 
    Sbar();
    if(error==0)
    {
        printf("String is Accepted!!!\n");
    }
    else
    {
        printf("String is Rejected!!!\n");
    }
    
    return 0;
}

void Sbar()
{
    cout << "Running the parser"<<endl;
    S();
    if(buffer[i]=='#')
    {
        error=0;
    }
    else
    {
        error=1;
    }
}
void S()
{
    if(buffer[i]=='m')
    {
        X();
        Y();
    }
    else if(buffer[i]=='n')
    {
        Y();
        X();
    }
}

void X()
{
    if(buffer[i]=='m')
    {
        i++;
        X();
    }
}
void Y()
{
    if(buffer[i]=='n')
    {
        i++;
        X();
    }
    else if(buffer[i]=='m')
    {
        X();
    }
    else{
        return;
    }
}
