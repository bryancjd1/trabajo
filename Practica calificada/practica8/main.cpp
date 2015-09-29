#include <iostream>

using namespace std;
int a;
int *ptr;
int arr[10];

int main()
{
    ptr=&arr[0];
    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<10;i++)
    {
        for(int y=0;y<10;y++)
        {
            if(*ptr<arr[y])
            {
                a=*ptr;
                *ptr=arr[y];
                arr[y]=a;
            }
        }
        ptr++;
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
