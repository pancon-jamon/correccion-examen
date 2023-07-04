#include <iostream>
#include <unistd.h>
using namespace std;
#define SLEEP 70000

bool obsEstaIzq=true;
int opcMenu=-1, anchoRio=20, obs=0, lobo=1, cape=2, uvas=3;
string arrIzq [ ]={"Obse","Lobo","Cape","Uvas"};
string arrDer [ ]={"",    "",    "",    ""};
string quienCruza="";

string showRio(int lentRio)
{
    string rio="";
    for (int i = 0; i < lentRio-1; i++)
    {
        rio+=" - ";
    }
    return rio;
}

string showPersonajes(const string arr[ ])
{
    string personaje="";
    for (int i = 0; i < 4; i++)
        personaje+=arr[i]+", ";
    return personaje;
}

void navegar()
{
    string barco="\\_obs_?_/",rio="";
    string actorIzq=showPersonajes(arrIzq);
    string actorDer=showPersonajes(arrDer);
    for (int i = 0; i < anchoRio; i++)
    {
        rio+="_ ";
        cout<<"\r"+actorIzq+showRio(i)+barco+showRio(anchoRio-i)+actorDer;
        usleep(SLEEP);
    }
    

}

int main()
{
    cout<<"\x18{2J\x18[H";
    cout<<"Bienvenido"<<endl;

    navegar();

    cout<<endl;
    return 0;
}