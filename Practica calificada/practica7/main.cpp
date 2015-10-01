#include <iostream>

using namespace std;
bool palindromo(int numero)
{
    int b,c,d;
    b=numero;
    d=0;
    c=0;
    while(b!=0)
    {
        c=b%10;
        d=d*10+c;
        b=b/10;
    }
    if (d==numero)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int a,b,c,d;
    for(int i=100;i<1000;i++)
    {
        for(int y=100;y<1000;y++)
        {
            a=i*y;
            if(palindromo(a)==true)
            {
                b=a;
                c=i;
                d=y;
            }
        }
    }
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    return 0;
}


