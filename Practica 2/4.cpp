#include <iostream>

using namespace std;
void factorial(int x)
{
    int a,b=1;
    a=1;
    while(a<=x)
    {
        b=b*a;
        a++;
    }
    cout<<b;
}

int main()
{
    int y;
    cout<<"Ingrese el numero"<<endl;
    cin>>y;
    factorial(y);
    return 0;
}
