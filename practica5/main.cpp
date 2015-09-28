#include <iostream>

using namespace std;
float arr[7];
int main()
{
    for(int i=0;i<7;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<7;i++)
    {
        if(arr[0]<arr[i])
        {
            arr[0]=arr[i];
        }
    }
    cout<<"El maximo es "<<arr[0]<<endl;
    for(int i=0;i<7;i++)
    {
        if(arr[0]>arr[i])
        {
            arr[0]=arr[i];
        }
    }
    cout<<"El minimo es "<<arr[0]<<endl;
    return 0;
}
