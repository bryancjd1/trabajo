#include <iostream>
using namespace std;

int main() {
    int a=0, b = 1, c = 1, d=0, e=2;


    while(d<4000000)
    {
        d = b + c;
        b = c;
        c = d;
        if(e%2==0)
        {
        a=a+d;
        }
        e++;

    }
    cout<<a<<endl;
    return 0;
}
