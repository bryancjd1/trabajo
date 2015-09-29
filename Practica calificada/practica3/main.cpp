#include <iostream>

using namespace std;
int main()
{
    int a=1,d=0;
    while(a!=0)
    {
        if((a%10==0)&&(a%11==0)&&(a%12==0)&&(a%13==0)&&(a%14==0)&&(a%15==0)&&(a%16==0)&&(a%17==0)&&(a%18==0)&&(a%19==0)&&(a%20==0))
        {
            d=a;
            a=-1;
        }
        a++;
    }
    cout<<d<<endl;
    return 0;
}
