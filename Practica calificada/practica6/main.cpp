#include <iostream>

using namespace std;
int x,y;
int main()
{
    for(int i=0;i<1000;i++)
    {
        if(i%3==0)
        {
            x=x+i;
        }
    }
    for(int i=0;i<1000;i++)
    {
        if(i%5==0)
        {
            y=y+i;
        }
    }
    cout<<"La suma es " <<x+y<<endl;
    return 0;
}
