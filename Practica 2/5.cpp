#include <iostream>
#include <fstream>
using namespace std;
void archivo(string nombre)
{
 ifstream ficheroEntrada;
 string frase;

 ficheroEntrada.open (nombre.c_str());
 getline(ficheroEntrada, frase);
 ficheroEntrada.close();


 cout << "Frase leida: " << frase << endl;

}


int main () {
    string nombre;
    cout << "Dime el nombre del fichero: ";
    getline(cin,nombre);

    archivo(nombre);
}

