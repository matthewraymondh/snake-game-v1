#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include <time.h>

struct tnode
{
    int NilaiX,NilaiY;      /*Menyimpan Koordinat MAKANAN yang DIMAKAN oleh LAKON*/
    tnode *next;
};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay()
{
    float a=1;
    do
    {
       a=a+0.1;
    }
    while(a<1700000);
}
using namespace std;

/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void kotak(int b1, int k1, int b2, int k2)
{
    for(int x=k1; x<=k2; x++)
    {
        gotoxy(x,b1);printf("%c",196);
        gotoxy(x,b2);printf("%c",196);
    }
    for(int x=b1; x<=b2; x++)
    {
        gotoxy(k1,x);printf("%c",179);
        gotoxy(k2,x);printf("%c",179);
    }

    gotoxy(k2,b1);printf("%c",191); /*┐*/
    gotoxy(k1,b2);printf("%c",192); /*└*/
    gotoxy(k1,b1);printf("%c",218); /*┌*/
    gotoxy(k2,b2);printf("%c",217); /*┘*/
}

int acak1()
{
    int x=rand();
    if(x<2)
        return (x%75)+2;
    else
        return (x%75);
}

int acak2()
{
    int x=rand();
    if((x%20) < 5)
        return (x%20)+5;
    else
        return (x%20);

}

int main()
{
    int brs=12;
    int klm=40;
    int tb=1;
    int tk=1;
    float bmusuh=6,kmusuh=2;
    float bbmusuh,bkmusuh;
    float tambahan=0.2;
    int mbrs,mklm;

    char kalimat1[85]={"GAME SERANG HINDAR - IMPLEMENTASI TYPE DATA DINAMIS - DICUSTOM OLEH :RAYMOND"};

    int bbrs,bklm;

    bersihlayar();
    srand(time(0));
    kotak(1,1,3,78);
    kotak(4,1,23,78);
    gotoxy(klm,brs);printf("%c",277);
    gotoxy(kmusuh,bmusuh);printf("%c",219);
    gotoxy((80-strlen(kalimat1))/2,2);cout<<kalimat1;

    mbrs=acak2();
    mklm=acak1();
    gotoxy(mklm,mbrs);cout<<"*";

    char key;
    do
    {
        if (kbhit()) key=getch();

        if(key=='K') klm--;
        if(key=='M') klm++;
        if(key=='H') brs--;
        if(key=='P') brs++;



        if(klm<2) klm=77;
        if(klm>77) klm=2;
        if(brs<5) brs=22;
        if(brs>22) brs=5;

        if((brs==mbrs) && (klm==mklm))
        {
            mbrs=acak2();
            mklm=acak1();
            gotoxy(mklm,mbrs);cout<<"*";
            /*tambahan=tambahan+0.1;*/
        }

        if(bmusuh<brs) bmusuh=bmusuh+tambahan;
        if(bmusuh>brs) bmusuh=bmusuh-tambahan;
        if(kmusuh<klm) kmusuh=kmusuh+tambahan;
        if(kmusuh>klm) kmusuh=kmusuh-tambahan;
        gotoxy(kmusuh,bmusuh);printf("%c",219);
        bbmusuh=bmusuh;
        bkmusuh=kmusuh;

        if((brs==int(bmusuh)) && (klm==int(kmusuh)))
        {
            gotoxy(60,22);cout<<"G A M E   O V E R";
            getch();
            system("cls");
            return 0;
        }

        bbrs=brs;
        bklm=klm;
        gotoxy(klm,brs);printf("%c",178);
        delay();
        gotoxy(bklm,bbrs);printf(" ");
        gotoxy(bkmusuh,bbmusuh);printf(" ");

    }
    while(key!=27);

    return 0;
}
