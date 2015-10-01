#include <iostream>
using namespace std;

int main() {
    int a=0, b = 1, c = 1, d=0;


    while(d<4000000)
    {
        d = b + c;
        b = c;
        c = d;
        if(d%2==0)
        {
        a=a+d;
        }
    }
    cout<<a<<endl;
    return 0;
}
