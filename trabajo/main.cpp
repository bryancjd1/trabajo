#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

char a1=' ',a2=' ',a3=' ',b1=' ',b2=' ',b3=' ',c1=' ',c2=' ',c3=' ',turno,jugar;
string lugar=" ";
int win=0,jug,i=0,o,num;

void mapa(){
cout    << "    1     2      3"<< endl
<< "       " <<"|" << "      " <<"|" << "      " << endl
<< "A   " << a1 << "  " <<"|" << "  " << a2 << "   " <<"|" << "  " << a3 << "   " << endl
<< "       " <<"|" << "      " <<"|" << "      " << endl
<< "  " <<"-" <<"-" <<"-" <<"-" <<"-" <<"|" <<"-" <<"-" <<"-" <<"-" <<"-" <<"-" <<"|" <<"-" <<"-" <<"-" <<"-" <<"-" << endl
<< "       " <<"|" << "      " <<"|" << "      " << endl
<< "B   " << b1 << "  " <<"|" << "  " << b2 << "   " <<"|" << "  " << b3 << "   " << endl
<< "       " <<"|" << "      " <<"|" << "      " << endl
<< "  " <<"-" <<"-" <<"-" <<"-" <<"-" <<"|" <<"-" <<"-" <<"-" <<"-" <<"-" <<"-" <<"|" <<"-" <<"-" <<"-" <<"-" <<"-" << endl
<< "       " <<"|" << "      " <<"|" << "      " << endl
<< "C   " << c1 << "  " <<"|" << "  " << c2 << "   " <<"|" << "  " << c3 << "   " << endl
<< "       " <<"|" << "      " <<"|" << "      " << endl << endl;
        }
int main(){
    cout<<"1. Jugar contra la maquina"<<endl;
    cout<<"2. Jugar contra otra persona"<<endl;
    cin>> o;
    if (o==1){
while (jugar!='n' || 'N') {
    if(i%2==0){ jug=1; turno='X'; }
    if(i%2==1){ jug=2; turno='O'; }
    mapa();
        if ((a1!=' ')&&(a2!=' ')&&(a3!=' ')&&(b1!=' ')&&(b2!=' ')&&(b3!=' ')&&(c1!=' ')&&(c2!=' ')&&(c3!=' ')) win=2;
        if ((a1!=' ')&&(a1==a2)&&(a1==a3)) win=1;
        if ((a1!=' ')&&(a1==b1)&&(a1==c1)) win=1;
        if ((a1!=' ')&&(a1==b2)&&(a1==c3)) win=1;
        if ((b1!=' ')&&(b1==b2)&&(b1==b3)) win=1;
        if ((c1!=' ')&&(c1==c2)&&(c1==c3)) win=1;
        if ((a2!=' ')&&(a2==b2)&&(a2==c2)) win=1;
        if ((a3!=' ')&&(a3==b3)&&(a3==c3)) win=1;
        if ((c1!=' ')&&(c1==b2)&&(c1==a3)) win=1;

        if ((win==2)||(win==1)){
    cout << "¿Desea volver a jugar? [S/N] ";
    cin >> jugar;
while((jugar!='s')&&(jugar!='S')&&(jugar!='n')&&(jugar!='N')){
    cout << "Responda solo con S o N"<<endl;
    cout <<"¿Desea volver a jugar? [S/N]";
    cin >> jugar;
}
switch(jugar){
    case 's':case 'S':
    a1=' ',a2=' ',a3=' ',b1=' ',b2=' ',b3=' ',c1=' ',c2=' ',c3=' ',win=0,i=0,jug=0;
    mapa();
break;
    case 'n':case 'N':
return 0;
break;
}
}
cout << "Turno del jugador " << jug << " ("<< turno << ")"<<endl;
cout <<"De la posicion de su jugada ";
cin >> lugar;
if (lugar==" ");
    else if (((lugar=="a1")||(lugar=="A1"))&&(a1==' ')) a1=turno;
    else if (((lugar=="a2")||(lugar=="A2"))&&(a2==' ')) a2=turno;
    else if (((lugar=="a3")||(lugar=="A3"))&&(a3==' ')) a3=turno;
    else if (((lugar=="b1")||(lugar=="B1"))&&(b1==' ')) b1=turno;
    else if (((lugar=="b2")||(lugar=="B2"))&&(b2==' ')) b2=turno;
    else if (((lugar=="b3")||(lugar=="B3"))&&(b3==' ')) b3=turno;
    else if (((lugar=="c1")||(lugar=="C1"))&&(c1==' ')) c1=turno;
    else if (((lugar=="c2")||(lugar=="C2"))&&(c2==' ')) c2=turno;
    else if (((lugar=="c3")||(lugar=="C3"))&&(c3==' ')) c3=turno;
else {
    cout << "Lugar ocupado"<<endl;
    cout <<"Vuelva a colocar su jugada"<<endl;
    cin>> lugar;
    if (win==2) cout << "Empate" << endl;
        if (win==1) cout << "Gano el jugador " << jug << "(" << turno << ")"<<endl;
i--;
}
i++;
}
}
if (o==2)
{
while (jugar!='n' || 'N') {
    if(i%2==0){ jug=1; turno='X'; }
    if(i%2==1){ jug=2; turno='O'; }
    mapa();
        if ((a1!=' ')&&(a2!=' ')&&(a3!=' ')&&(b1!=' ')&&(b2!=' ')&&(b3!=' ')&&(c1!=' ')&&(c2!=' ')&&(c3!=' ')) win=2;
        if ((a1!=' ')&&(a1==a2)&&(a1==a3)) win=1;
        if ((a1!=' ')&&(a1==b1)&&(a1==c1)) win=1;
        if ((a1!=' ')&&(a1==b2)&&(a1==c3)) win=1;
        if ((b1!=' ')&&(b1==b2)&&(b1==b3)) win=1;
        if ((c1!=' ')&&(c1==c2)&&(c1==c3)) win=1;
        if ((a2!=' ')&&(a2==b2)&&(a2==c2)) win=1;
        if ((a3!=' ')&&(a3==b3)&&(a3==c3)) win=1;
        if ((c1!=' ')&&(c1==b2)&&(c1==a3)) win=1;

        if ((win==2)||(win==1)){
    cout << "¿Desea volver a jugar? [S/N] ";
    cin >> jugar;
    while((jugar!='s')&&(jugar!='S')&&(jugar!='n')&&(jugar!='N')){
        cout << "Responda solo con S o N"<<endl;
        cout <<"¿Desea volver a jugar? [S/N]";
        cin >> jugar;
    }
switch(jugar){
    case 's':case 'S':
    a1=' ',a2=' ',a3=' ',b1=' ',b2=' ',b3=' ',c1=' ',c2=' ',c3=' ',win=0,i=0,jug=0;
    mapa();
break;
    case 'n':case 'N':
return 0;
break;
    }
}
if (jug==1){
    cout << "Turno del jugador " << jug << " ("<< turno << ")"<<endl;
    cout <<"De la posicion de su jugada ";
    cin >> lugar;
    if (lugar==" ");
        else if (((lugar=="a1")||(lugar=="A1"))&&(a1==' ')) a1=turno;
        else if (((lugar=="a2")||(lugar=="A2"))&&(a2==' ')) a2=turno;
        else if (((lugar=="a3")||(lugar=="A3"))&&(a3==' ')) a3=turno;
        else if (((lugar=="b1")||(lugar=="B1"))&&(b1==' ')) b1=turno;
        else if (((lugar=="b2")||(lugar=="B2"))&&(b2==' ')) b2=turno;
        else if (((lugar=="b3")||(lugar=="B3"))&&(b3==' ')) b3=turno;
        else if (((lugar=="c1")||(lugar=="C1"))&&(c1==' ')) c1=turno;
        else if (((lugar=="c2")||(lugar=="C2"))&&(c2==' ')) c2=turno;
        else if (((lugar=="c3")||(lugar=="C3"))&&(c3==' ')) c3=turno;
        else {
            cout << "Lugar ocupado"<<endl;
            cout <<"Vuelva a colocar su jugada"<<endl;
            cin>> lugar;
            if (win==2) cout << "Empate" << endl;
            if (win==1) cout << "Gano el jugador " << jug << "(" << turno << ")"<<endl;
        i--;
        }
        i++;
    }
    if (jug==2)
    {
        cout<<"Jugar contra la maquina"<<endl;
        cout<<"Jugar contra otra persona"<<endl;
        cin>> o;
        int k=0;
        cout << "Turno del jugador " << jug << " ("<< turno << ")"<<endl;
        while(k!=1)
        {
            num = rand()%9;
            if((num==0) && (a1=' ')) a1=turno,k=1;
            if((num==1) && (a2=' ')) a2=turno,k=1;
            if((num==2) && (a3=' ')) a3=turno,k=1;
            if((num==3) && (b1=' ')) b1=turno,k=1;
            if((num==4) && (b2=' ')) b2=turno,k=1;
            if((num==5) && (b3=' ')) b3=turno,k=1;
            if((num==6) && (c1=' ')) c1=turno,k=1;
            if((num==7) && (c2=' ')) c2=turno,k=1;
            if((num==8) && (c3=' ')) c3=turno,k=1;
        }
    i++;
    }
}
}
}

