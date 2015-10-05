#include <iostream>
#include <string>
using namespace std;
void no_repetitions(string _palabra, int largo)
{
int i=0,j=0;
char b,c;
b=' ';
c=' ';
string palabra = _palabra;
for(i=0;i<largo;i++)
{
    j=i+1;
    while(j<largo)
    {
        b=palabra[j];
        c=palabra[i];
        if(b==c)
            palabra[j]=' ';
        j++;
    }
    if(palabra[i]!=' ')
    {
        cout<<palabra[i];
    }
}
}

int main()
{
    int a;
    cout << "Ingrese el numero de letras de su cadena" << endl;
    cin>>a;
    string s;
    cin>>s;
    no_repetitions(s,a);
    return 0;
}

