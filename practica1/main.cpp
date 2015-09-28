#include <iostream>

using namespace std;
int arr[0];
int main()
{
    for(int i=0;i<8;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    for(int i=7;i>=0;i--)
    {
        cout<<arr[i]<<endl;
    }

    return 0;
}
