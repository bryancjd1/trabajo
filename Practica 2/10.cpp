#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    int arreglo[400000],a;
    srand (time(NULL));
    cout<<"Ingrese numero"<<endl;
    cin>>a;
    for(int i=0;i<400000;i++)
    {
        arreglo[i]=rand()%100;
    }
    for(int i=0;i<400000;i++)
    {
        if(arreglo[i]==a)
        {
            cout<<i<<" ";
        }
    }

}
