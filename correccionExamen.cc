#include <iostream>
#include <unistd.h>
using namespace std;
#define SLEEP 70000

bool obsEstaIzq=true;
int opcMenu=-1, anchoRio=20, obs=0, lobo=1, cape=2, uvas=3;
string arrIzq [ ]={"Obse","Lobo","Cape","Uvas"};
string arrDer [ ]={"",    "",    "",    ""};
string quienCruza="";
enum color{blue=1, green, turqueza, rojo, rosa, naranja, negro, gris};

string setColor(color c)

{
    // HANDLE col= ;
    SetConsolTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c)
    // for (int col_code = 0; col_code < 16; col_code++)
    // {
    //     SetConsolTextAttribute(col, col_code)
    //     cout<< col_code << "Color" << endl;
    // }
    // Color r=red;
    // switch (r)
    // {
    // case red: cout<<"Red\n"; break;
    // case green : cout<<"Green\n"; break;
    // case blue : cout<<"Blue\n"; break;
    // default:
    //     break;
    // }
   return "" ;
}

void menu()
{
    cout<<"\n0.Solo\n  1.Lobo\n 2.Caperucita\n 3.Uvas\n 4.Salir\n";
   do
   {
        try
        {
            string str="";
            cout<<">Cruzar: "<< str;
            opcMenu= stoi(str);//stoi esta en la libbreria string y permmite conviertir un valor string a entero
            quienCruza= (obsEstaIzq) ? arrIzq[opcMenu]:arrDer[opcMenu];//actualiza la veriable en true or false
            if (quienCruza.empty())
            {
                throw invalid_argument("No hay personaje");
            }
            
        }
        catch(...)
        {
            quienCruza="";
            opcMenu=-1
            cerr << "Lo siento, opcion no valida :(" << endl;//tambien funciona con cout
        }
        // if(opcMenu > 3); exit(0);
   } while (opcMenu<0);
   //try catch es un controlador de eventualidades, obliga al programa a cerrarse si no se cumple pero con la cpacidad de recuperar

}

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
    string barco="\\_obs_"+quienCruza+"/",rio="";
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
    setColor(blue);
    cout<<setColor(blue)+"Bienvenido"<<endl;

    setColor(red);
    menu();
    cout<<"Esta cruzando: "<<quienCruza;
    navegar();

    cout<<endl;
    return 0;
}