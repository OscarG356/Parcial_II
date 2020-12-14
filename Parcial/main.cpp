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
void DisparoDefensivo2(int ,int , int , int , int);
void DisparoDefensivo3(int ,int,int, int, int, int);

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
        case 3:{
            DisparoDefensivo2(ofensivo->getHi(),defensivo->getD(),defensivo->getHi(),31,85);
            system("pause");
            system("cls");
        }
            break;
        case 4:{
            DisparoDefensivo3(0,ofensivo->getHi(),defensivo->getD(),defensivo->getHi(),31,85);
            system("pause");
            system("cls");
        }
            break;
        case 0:{
            system("cls");
            cout<<"***Hasta luego***"<<endl;
            simulacion=false;
        }
            break;
        default:{
            cout<<"***Opcion invalida"<<endl;
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
    for(VI0 = VIo;VI0<1000; VI0 += 5){
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
    if(flag < 3){
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
    for(VI0 = VIo;VI0<1000; VI0 += 5){
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

void DisparoDefensivo2(int Yo,int Xd, int Yd, int Angl, int Vo0)
{

    Bala *disparo_d = new Bala(Xd,Yd,true); //disparo

    int VIo;
    cout << "Ingrese Vo desde la cual quiere probar: ";
    cin >> VIo;

    int flag = 0;
    float x,y,x2,y2;
    float Vx,Vy,Vx1,Vy2;
    int VI0 = 0;
    int t = 0;
    int angle = 0;
    Vx1 = Vo0*cos((Angl)*pi/180);
    Vy2 = Vo0*sin((Angl)*pi/180);
    for(VI0 = VIo;VI0<1000; VI0 += 5){
        for(angle = 0; angle < 90; angle++){
            Vx = VI0*cos(angle+90*pi/180);
            Vy = VI0*sin(angle+90*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 = Vx1*(t+2);
                y2 = Yo + Vy2*(t+2) -(0.5*G*(t+2)*(t+2));
                x = Vx*t;
                y = Yo + Vy*t -(0.5*G*t*t);
                float Rang=disparo_d->getRang();
                if(disparo_d->impacto(x,y,x2,y2,Rang)){
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

void DisparoDefensivo3(int Xo,int Yo,int Xd, int Yd, int Angl, int Vo0){

    Bala *disparo_d = new Bala(Xd,Yd,true); //disparo
    Bala *disparo_o = new Bala(Xo,Yo,false);

    int flag = 0;
    bool flag2 = 0;
    float x,y,x2,y2;
    float aux,auy;
    float Vx1,Vy1, Vx2,Vy2;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    Vx2 = Vo0*cos((Angl)*pi/180);
    Vy2 = Vo0*sin((Angl)*pi/180);
    for(V0o = Vo0; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vx1 = V0o*cos((angle+90)*pi/180);
            Vy1 = V0o*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 = Vx2*(t+2);
                y2 = Yo + Vy2*(t+2) -(0.5*G*(t+2)*(t+2));
                x = Xd-Vx1*t;
                y = Yd + Vy1*t -(0.5*G*t*t);
                for(int t2 = t; ;t2++){
                    aux = Xd+Vx1*t2;
                    auy = Yd + Vy1*t2 -(0.5*G*t2*t2);
                    float Rang=disparo_d->getRang();
                    if(disparo_d->impacto(x,y,aux,auy,Rang)){
                        flag2 = 1;
                        break;
                    }
                    if(auy < 0){
                        break;
                    }
                }
                if(flag2){
                    flag2 = 0;
                    break;
                }
                float Rang=disparo_o->getRang();
                if(disparo_d->impacto(Xd,Yd,x2,y2,Rang)){
                    break;
                }
                if(disparo_d->impacto(x2,y2,x,y,Rang)){
                    if(y<0) y = 0;
                    print(V0o,t+2,x2,y2,Angl);
                    cout << "_________________________________"<<endl;
                     print(V0o,t,x,y,angle);
                    flag += 1;
                    V0o += 50;
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
