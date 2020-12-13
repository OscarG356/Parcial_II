#include <iostream>
#include "bala.h"
#include "canon.h"

using namespace std;

void print(int VI,int t,float x,float y,int angle);

int main()
{    
    bool simulacion=true;
    while(simulacion){
        Bala *disparo; //disparo

        Canon *ofensivo = new Canon(20); //canon ofensivo
        Canon *defensivo = new Canon(100); //canon defensivo

        int opc;

        cout<<"*************Bienvenido*************"<<endl;
        cout<<"Que desea hacer?"<<endl;
        cout<<"1) Generar disparos ofensivos que comprometan la integridad del canon defensivo.\n"<<endl;
        cout<<"2) Generar disparos defensivos que comprometan la integridad del canon ofensivo.\n"<<endl;
        cout<<"3) Dado un disparo ofensivo, generar disparos defensivos que impida que el canon \ndefensivo sea destruido sin importar si el canon ofensivo pueda ser destruido.\n"<<endl;
        cout<<"4) Dado un disparo ofensivo, generar disparo defensivos que impidan que los canones \ndefensivo y ofensivo puedan ser destruidos.\n"<<endl;
        cout<<"5) Dado un disparo ofensivo efectivo y un disparo defensivo que comprometa la \nefectividad del ataque ofensivo, generar disparos que neutralicen el ataque defensivo \ny permitan que el ataque ofensivo sea efectivo.\n"<<endl;
        cout<<endl<<"Ingrese su opcion: ";
        cin>>opc;

        switch (opc) {
        case 1:{
            cout<<"Proximamente..."<<endl;
            system("pause");
            system("cls");
        }
            break;

        }
    }

    return 0;
}
