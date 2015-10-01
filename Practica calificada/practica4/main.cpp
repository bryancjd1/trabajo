#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    int x;
    int **matriz;
    matriz=new int*[100];
    srand (time(NULL));
    for(int i=0;i<100;i++)
    {
        matriz[i]=new int[100];
    }
    for(int j=0;j<100;j++)
    {
        for(int i=0;i<100;i++)
        {
            *(*(matriz+j)+i)=rand()%100;
        }
    }
    for(int j=0;j<100;j++)
    {
        for(int i=0;i<100;i++)
        {
            cout<<*(*(matriz+j)+i)<<endl;
        }
    }
    cout<<"Ingrese el valor"<<endl;
    cin>>x;
    for(int j=0;j<100;j++)
    {
        for(int i=0;i<100;i++)
        {
            if(*(*(matriz+j)+i)==x)
            {
                cout<<j<<"  "<<i<<endl;
            }
        }
    }
    return 0;
}
