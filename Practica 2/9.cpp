#include <iostream>

using namespace std;

int main()
{
    int a;
    char nombre[100];
    cout<<"Ingrese su nombre"<<endl;
    cin.getline (nombre,100);
    cout<<"Cuantas letras tiene su nombre"<<endl;
    cin>>a;
    for(int i=0;i<a;i++)
    {
    cout <<nombre[i]<<" "<<i<< endl;
    }
    return 0;
}
