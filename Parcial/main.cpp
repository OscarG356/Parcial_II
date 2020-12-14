#include <iostream>
#include "bala.h"
#include "canon.h"
#include <math.h>

#define G 9.81
#define pi 3.141617

using namespace std;

void print(int,int,float,float,int);
void DisparoOfensivo(int, int, int, int);
void DisparoDefensivo(int, int, int, int);

int main()
{    
    bool simulacion=true;
    while(simulacion){

        Canon *defensivo = new Canon(100); //canon defensivo
        Canon *ofensivo = new Canon(20); //canon ofensivo

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
            DisparoOfensivo(defensivo->getD(),defensivo->getHi(),0,ofensivo->getHi());
            system("pause");
            system("cls");
        }
            break;
        case 2:{
            DisparoDefensivo(ofensivo->getD(),ofensivo->getHi(),defensivo->getD(),defensivo->getHi());
            system("pause");
            system("cls");
        }
            break;

        }
    }

    return 0;
}

void print(int VI,int t,float x,float y,int angle)
{
    cout << "--------------------------------------------------------"<<endl;
    cout << "Impacto con un angulo de " << angle << " grados" << endl;
    cout << "Impacto con velocidad incial " << VI << endl;
    cout << "Impacto con posicion x: " << x << endl;
    cout << "Impacto con posicion y: " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;
}

void DisparoOfensivo(int Xd,int Yd,int Xo, int Yo)
{

    Bala *disparo = new Bala(Xo,Yo,false); //disparo

    int VIo;
    cout << "Ingrese Vo desde la cual quiere probar: ";
    cin >> VIo;

    int flag = 0;
    float x,y;
    float Vx,Vy;
    int VI0 = 0;
    int t = 0;
    int angle = 0;
    for(VI0 = VIo;VI0==1000; VI0 += 5){
        for(angle = 0; angle < 90; angle++){
            Vx = VI0*cos(angle*pi/180);
            Vy = VI0*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vx*t;
                y = Yo + Vy*t -(0.5*G*t*t);
                float Rang=disparo->getRang();
                if(disparo->impacto(x,y,Xd,Yd,Rang)){
                    if(y<0) y = 0;
                    print(VI0,t,x,y,angle);
                    flag += 1;
                    VI0 += 50;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void DisparoDefensivo(int Xo,int Yo,int Xd, int Yd)
{

    Bala *disparo = new Bala(Xd,Yd,true); //disparo

    int VIo;
    cout << "Ingrese Vo desde la cual quiere probar: ";
    cin >> VIo;

    int flag = 0;
    float x,y;
    float Vx,Vy;
    int VI0 = 0;
    int t = 0;
    int angle = 0;
    for(VI0 = VIo;VI0==1000; VI0 += 5){
        for(angle = 0; angle < 90; angle++){
            Vx = VI0*cos(angle+90*pi/180);
            Vy = VI0*sin(angle+90*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vx*t;
                y = Yo + Vy*t -(0.5*G*t*t);
                float Rang=disparo->getRang();
                if(disparo->impacto(x,y,Xo,Yo,Rang)){
                    if(y<0) y = 0;
                    print(VI0,t,x,y,angle);
                    flag += 1;
                    VI0 += 50;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

