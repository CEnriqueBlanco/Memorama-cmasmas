#ifndef ESTETICA
#define ESTETICA
#include <iostream>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <string>
using namespace std;


void reproducirSonido(const char* cancion)
{
    typedef BOOL (*PlaySoundA_ptr) (LPCWSTR, HMODULE, DWORD);
    PlaySoundA_ptr fn_PlaySound = 0;
    HMODULE Lib = LoadLibraryW(L"winmm.dll");  
    if (Lib)
    {
        fn_PlaySound = (PlaySoundA_ptr)(GetProcAddress(Lib, "PlaySoundA"));

        if (fn_PlaySound)
        {
            fn_PlaySound(LPCWSTR(cancion), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);  // Pasamos cancion como LPCWSTR
        }

        FreeLibrary(Lib);
    }
}

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwpos;
	dwpos.X = x;
	dwpos.Y = y;
	SetConsoleCursorPosition(hcon,dwpos);
}

void textcolor(int n){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n); 
}

string obtenerHora()
{
    time_t now = time(0);
    struct tm* time = localtime(&now);
    char hora[10];
    strftime(hora,10,"%H:%M:%S",time);
    return hora;
}

string obtenerFecha()
{
    time_t now = time(0);
    struct tm* time = localtime(&now);
    char dia[10];
    strftime(dia,12,"%d/%m/%Y",time);
    return dia;
}

void margenJuego(int tam)
{
	char ren = 205, col = 186, esqsupIzq = 201, esqsupDer = 187, esqinfIzq = 200,
	esqinfDer = 188, unionsoblinea = 203, unionsobdoslineas = 206, unionsoblineabaja = 202,
	unionizqlinea = 204, unionderlinea = 185;
	
	string hora =obtenerHora();
	string fecha = obtenerFecha();


	textcolor(11);
	for(int k=35; k<=85; k++)
	{
		gotoxy(0+k,6);
		cout<<ren;
		gotoxy(0+k,22);
		cout<<ren;
	}

	for (int l=6; l<=22; l++)
	{
		gotoxy(35,0+l);
		cout<<col;
		gotoxy(85,0+l);
		cout<<col;
	}

	gotoxy(35,6);
	cout<<esqsupIzq;
	gotoxy(85,6);
	cout<<esqsupDer;
	gotoxy(35,22);
	cout<<esqinfIzq;
	gotoxy(85,22);
	cout<<esqinfDer;

	switch(tam)
	{
		case 6:
		textcolor(11);
			for(int i=35; i<=85; i++)
			{
				gotoxy(0+i,11);
				cout<<ren;
				gotoxy(0+i,16);
				cout<<ren;
			}//ancho
			
			for(int j=6; j<=22; j++)
			{
				gotoxy(60,0+j);
				cout<<col;
			}//Largo
			//Partes sueltas
			gotoxy(60,6);  cout<<unionsoblinea;
			gotoxy(60,11); cout<<unionsobdoslineas;
			gotoxy(60,16); cout<<unionsobdoslineas;
			gotoxy(60,22); cout<<unionsoblineabaja;
			gotoxy(35,11); cout<<unionizqlinea;
			gotoxy(35,16); cout<<unionizqlinea;
			gotoxy(85,11); cout<<unionderlinea;
			gotoxy(85,16); cout<<unionderlinea;			
			break;
		case 12:
			
			for(int i=35; i<=85; i++)
			{
				gotoxy(0+i,10);
				cout<<ren;
				gotoxy(0+i,14);
				cout<<ren;
				gotoxy(0+i,18);
				cout<<ren;
			}//Ancho
			
			for(int j=6; j<=22; j++)
			{
				gotoxy(51,0+j);
				cout<<col;
				gotoxy(67,0+j);
				cout<<col;
			}//Largo
			//Partes sueltas
			gotoxy(51,6);  cout<<unionsoblinea;
			gotoxy(67,6);  cout<<unionsoblinea;
			gotoxy(51,22); cout<<unionsoblineabaja;
			gotoxy(67,22); cout<<unionsoblineabaja;
			gotoxy(35,10); cout<<unionizqlinea;
			gotoxy(35,14); cout<<unionizqlinea;
			gotoxy(35,18); cout<<unionizqlinea;
			gotoxy(85,10); cout<<unionderlinea;
			gotoxy(85,14); cout<<unionderlinea;
			gotoxy(85,18); cout<<unionderlinea;			
			gotoxy(51,10); cout<<unionsobdoslineas;
			gotoxy(51,14); cout<<unionsobdoslineas;
			gotoxy(51,18); cout<<unionsobdoslineas;
			gotoxy(67,10); cout<<unionsobdoslineas;
			gotoxy(67,14); cout<<unionsobdoslineas;
			gotoxy(67,18); cout<<unionsobdoslineas;			
												
			break;
		case 16:
			
			for(int i=35; i<=85; i++)
			{
				gotoxy(0+i,10);
				cout<<ren;
				gotoxy(0+i,14);
				cout<<ren;
				gotoxy(0+i,18);
				cout<<ren;
			}//Ancho		
			
			for(int j=6; j<=22; j++)			
			{
				gotoxy(47,0+j);
				cout<<col;
				gotoxy(60,0+j);
				cout<<col;
				gotoxy(72,0+j);
				cout<<col;
			}//Largo	
			//Partes sueltas		
			gotoxy(47,6);  cout<<unionsoblinea;
			gotoxy(60,6);  cout<<unionsoblinea;
			gotoxy(72,6);  cout<<unionsoblinea;
			gotoxy(47,22);  cout<<unionsoblineabaja;
			gotoxy(60,22);  cout<<unionsoblineabaja;
			gotoxy(72,22);  cout<<unionsoblineabaja;
			gotoxy(35,10); cout<<unionizqlinea;
			gotoxy(35,14); cout<<unionizqlinea;
			gotoxy(35,18); cout<<unionizqlinea;
			gotoxy(85,10); cout<<unionderlinea;
			gotoxy(85,14); cout<<unionderlinea;
			gotoxy(85,18); cout<<unionderlinea;			
			gotoxy(47,10); cout<<unionsobdoslineas;
			gotoxy(47,14); cout<<unionsobdoslineas;
			gotoxy(47,18); cout<<unionsobdoslineas;
			gotoxy(60,10); cout<<unionsobdoslineas;
			gotoxy(60,14); cout<<unionsobdoslineas;
			gotoxy(60,18); cout<<unionsobdoslineas;
			gotoxy(72,10); cout<<unionsobdoslineas;
			gotoxy(72,14); cout<<unionsobdoslineas;
			gotoxy(72,18); cout<<unionsobdoslineas;				
			
			break;
					
	}

	
}

void margen()
{
	char ren = 205, col = 186, esqsupIzq = 201, esqsupDer = 187, esqinfIzq = 200,
	esqinfDer = 188;

	
	
	textcolor(9);
	
	for(int i=0; i<=119; i++)
		{
			gotoxy(0+i,0);
			cout<<ren;
			gotoxy(0+i,29);
			cout<<ren;
		}
	
		for(int j=0; j<=29; j++)
		{
			gotoxy(0,0+j);
			cout<<col;
			gotoxy(119,0+j);
			cout<<col;
		}
		gotoxy(0,0);
		cout<<esqsupIzq;
		gotoxy(119,0);
		cout<<esqsupDer;
		gotoxy(0,29);
		cout<<esqinfIzq;
		gotoxy(119,29);
		cout<<esqinfDer;	
}

void ganador(clock_t tiempo,string& nombre)
{
	bool simulacion;
	char cp = 219; //cuadro pintado	
	margen();
	textcolor(11);
	gotoxy(33,17);cout<<nombre;
	textcolor(15);
	cout<<" completaste el memorama en ";
	textcolor(9);
	if(tiempo > 60000)
	{
		int minutos = tiempo /60000;
		cout<<fixed<<setprecision(0)<<float(minutos)<<" minutos";
	}
	else
	{
		cout<<float(tiempo)/CLOCKS_PER_SEC<< " segundos";		
	}
	
 
    //F
    textcolor(13);
    gotoxy(20,9);cout<<cp<<cp<<cp<<cp<<cp;
    gotoxy(20,10);cout<<cp;
    gotoxy(20,11);cout<<cp;
    gotoxy(20,12);cout<<cp<<cp<<cp;
    gotoxy(20,13);cout<<cp;
    gotoxy(20,14);cout<<cp;
    gotoxy(20,15);cout<<cp;
    //E
    textcolor(12);
    gotoxy(27,9);cout<<cp<<cp<<cp<<cp<<cp;
    gotoxy(27,10);cout<<cp;
    gotoxy(27,11);cout<<cp;
    gotoxy(27,12);cout<<cp<<cp<<cp<<cp<<cp;
    gotoxy(27,13);cout<<cp;
    gotoxy(27,14);cout<<cp;
    gotoxy(27,15);cout<<cp<<cp<<cp<<cp<<cp;
    //L
    textcolor(11);
	gotoxy(34,9);cout<<cp;    
	gotoxy(34,10);cout<<cp;
	gotoxy(34,11);cout<<cp;
	gotoxy(34,12);cout<<cp;
	gotoxy(34,13);cout<<cp;
	gotoxy(34,14);cout<<cp;
	gotoxy(34,15);cout<<cp<<cp<<cp<<cp<<cp;
	//I
	textcolor(15);
	gotoxy(41,9);cout<<cp<<cp<<cp<<cp<<cp;
	gotoxy(43,10);cout<<cp;
	gotoxy(43,11);cout<<cp;
	gotoxy(43,12);cout<<cp;
	gotoxy(43,13);cout<<cp;
	gotoxy(43,14);cout<<cp;
	gotoxy(41,15);cout<<cp<<cp<<cp<<cp<<cp;
	//C
	textcolor(5);
	gotoxy(48,9);cout<<cp<<cp<<cp<<cp<<cp;
	gotoxy(48,10);cout<<cp;
	gotoxy(48,11);cout<<cp;
	gotoxy(48,12);cout<<cp;
	gotoxy(48,13);cout<<cp;
	gotoxy(48,14);cout<<cp;
	gotoxy(48,15);cout<<cp<<cp<<cp<<cp<<cp;
	//I
	textcolor(3);
	gotoxy(55,9);cout<<cp<<cp<<cp<<cp<<cp;
	gotoxy(57,10);cout<<cp;
	gotoxy(57,11);cout<<cp;
	gotoxy(57,12);cout<<cp;
	gotoxy(57,13);cout<<cp;
	gotoxy(57,14);cout<<cp;
	gotoxy(55,15);cout<<cp<<cp<<cp<<cp<<cp;	
	//D
	textcolor(1);
    gotoxy(62,9);cout<<cp<<cp<<cp;   
	gotoxy(62,10);cout<<cp;      gotoxy(65,10);cout<<cp;
	gotoxy(62,11);cout<<cp;		 gotoxy(66,11);cout<<cp;
	gotoxy(62,12);cout<<cp;		 gotoxy(66,12);cout<<cp;
	gotoxy(62,13);cout<<cp;		 gotoxy(66,13);cout<<cp;
	gotoxy(62,14);cout<<cp;		 gotoxy(65,14);cout<<cp;
	gotoxy(62,15);cout<<cp<<cp<<cp;
	//A
	textcolor(11);
	gotoxy(69,9); cout<<cp<<cp<<cp<<cp<<cp;
	gotoxy(69,10); cout<<cp;				gotoxy(73,10);cout<<cp;
	gotoxy(69,11); cout<<cp;				gotoxy(73,11);cout<<cp;
	gotoxy(69,12); cout<<cp<<cp<<cp<<cp<<cp; 
	gotoxy(69,13); cout<<cp;				gotoxy(73,13);cout<<cp;
	gotoxy(69,14); cout<<cp;				gotoxy(73,14);cout<<cp;
	gotoxy(69,15); cout<<cp;				gotoxy(73,15);cout<<cp;

	//D
	textcolor(12);
    gotoxy(76,9);cout<<cp<<cp<<cp;   
	gotoxy(76,10);cout<<cp;      gotoxy(79,10);cout<<cp;
	gotoxy(76,11);cout<<cp;		 gotoxy(80,11);cout<<cp;
	gotoxy(76,12);cout<<cp;		 gotoxy(80,12);cout<<cp;
	gotoxy(76,13);cout<<cp;		 gotoxy(80,13);cout<<cp;
	gotoxy(76,14);cout<<cp;		 gotoxy(79,14);cout<<cp;
	gotoxy(76,15);cout<<cp<<cp<<cp;
    //E
    textcolor(4);
    gotoxy(83,9);cout<<cp<<cp<<cp<<cp<<cp;
    gotoxy(83,10);cout<<cp;
    gotoxy(83,11);cout<<cp;
    gotoxy(83,12);cout<<cp<<cp<<cp<<cp<<cp;
    gotoxy(83,13);cout<<cp;
    gotoxy(83,14);cout<<cp;
    gotoxy(83,15);cout<<cp<<cp<<cp<<cp<<cp;
    textcolor(1);
    gotoxy(90,9); cout<<cp<<cp<<cp<<cp<<cp;
    gotoxy(90,10);cout<<cp;
    gotoxy(90,11);cout<<cp;
    gotoxy(90,12);cout<<cp<<cp<<cp<<cp<<cp;
    gotoxy(94,13);cout<<cp;
    gotoxy(94,14);cout<<cp;
    gotoxy(90,15);cout<<cp<<cp<<cp<<cp<<cp;
    
    gotoxy(33,20);
    textcolor(10);
    cout<<"Presione cualquier tecla para volver al menu principal";
    getch();
    system("cls");
}

void margenPantallas()
{
	textcolor(12);
 	for(int pos_Y=1; pos_Y<=41; pos_Y++)
 	{
  	gotoxy(1,pos_Y);
 	cout<<"|";		
	}

	textcolor(11);
 	for(int pos_X=1; pos_X<=166; pos_X++)
 	{
  	gotoxy(pos_X,41);
 	cout<<"_";
	}
	
	textcolor(2);
 	for(int pos_Y=1; pos_Y<=41; pos_Y++)
 	{
  	gotoxy(166,pos_Y);
 	cout<<"|";
	}	
	
	textcolor(6);
	for(int pos_X=1; pos_X<=166; pos_X++)
 	{
  	gotoxy(pos_X,0);
 	cout<<"_";		
	}	
}

void pantalla3()
{
	textcolor(12);
 	for(int pos_Y=1; pos_Y<=41; pos_Y++)
 	{
  	gotoxy(10,pos_Y);
 	cout<<"|";		
	}	
	textcolor(11);
 	for(int pos_X=1; pos_X<=166; pos_X++)
 	{
  	gotoxy(pos_X,35);
 	cout<<"_";
 	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	}	
	
	textcolor(2);
 	for(int pos_Y=1; pos_Y<=41; pos_Y++)
 	{
  	gotoxy(150,pos_Y);
 	cout<<"|";
	}
	
	textcolor(6);
	for(int pos_X=1; pos_X<=166; pos_X++)
 	{
  	gotoxy(pos_X,5);
 	cout<<"_";		
	}
	
	
}
 
 void logo()
 {
 	
 	system("cls");
 	textcolor(1);
 	gotoxy(1,5);
	cout<<"I";
  	gotoxy(2,1);
  	cout<<"I";
	gotoxy(2,5);
  	cout<<"I";
  	gotoxy(2,6);
	cout<<"I";
  	gotoxy(2,7);
  	cout<<"I";
	gotoxy(2,8);
  	cout<<"I";
  	gotoxy(2,9);
	cout<<"I";
  	gotoxy(2,10);
  	cout<<"I";
	gotoxy(2,11);
  	cout<<"I";
  	gotoxy(2,12);
	cout<<"I";
  	gotoxy(2,13);
  	cout<<"I";
	gotoxy(2,14);
  	cout<<"I";
  	gotoxy(2,15);
	cout<<"I";
  	gotoxy(2,16);
  	cout<<"I";
	gotoxy(2,17);
  	cout<<"I";
  	gotoxy(2,18);
	cout<<"I";
  	gotoxy(2,19);
  	cout<<"I";
	gotoxy(2,20);
  	cout<<"I";
  	gotoxy(3,1);
	cout<<"I";
  	gotoxy(3,2);
  	cout<<"I";
	gotoxy(3,6);
  	cout<<"I";
  	gotoxy(3,7);
  	cout<<"I";
  	gotoxy(3,8);
  	cout<<"I";
  	gotoxy(3,9);
  	cout<<"I";
  	gotoxy(3,10);
  	cout<<"I";
  	gotoxy(3,11);
  	cout<<"I";
  	gotoxy(3,12);
  	cout<<"I";
	gotoxy(3,13);
  	cout<<"I";
  	gotoxy(3,14);
  	cout<<"I";
  	gotoxy(3,15);
  	cout<<"I";
  	gotoxy(3,16);
  	cout<<"I";
  	gotoxy(3,17);
  	cout<<"I";
  	gotoxy(3,18);
  	cout<<"I";
  	gotoxy(3,19);
  	cout<<"I";
  	gotoxy(3,20);
  	cout<<"I";
  	gotoxy(3,21);
  	cout<<"I";
  	gotoxy(4,1);
  	cout<<"I";
  	gotoxy(4,2);
  	cout<<"I";
  	gotoxy(4,3);
  	cout<<"I";
  	gotoxy(4,20);
  	cout<<"I";
  	gotoxy(4,21);
  	cout<<"I";
  	gotoxy(4,22);
  	cout<<"I";
  	gotoxy(5,2);
  	cout<<"I";
  	gotoxy(5,3);
  	cout<<"I";
  	gotoxy(5,4);
  	cout<<("I");
  	gotoxy(5,5);
  	cout<<"I";
  	gotoxy(5,6);
  	cout<<"I";
  	gotoxy(5,7);
  	cout<<"I";
  	gotoxy(5,8);
  	cout<<"I";
  	gotoxy(5,9);
  	cout<<"I";
  	gotoxy(5,10);
  	cout<<"I";
  	gotoxy(5,15);
  	cout<<"I";
  	gotoxy(5,16);
  	cout<<"I";
  	gotoxy(5,17);
  	cout<<"I";
  	gotoxy(5,18);
  	cout<<"I";
  	gotoxy(5,19);
  	cout<<"I";
  	gotoxy(5,21);
  	cout<<"I";
  	gotoxy(5,22);
  	cout<<"I";
  	gotoxy(6,3);
  	cout<<"I";
  	gotoxy(6,4);
  	cout<<"I";
  	gotoxy(6,5);
  	cout<<"I";
  	gotoxy(6,6);
  	cout<<"I";
  	gotoxy(6,7);
  	cout<<"I";
  	gotoxy(6,8);
  	cout<<"I";
  	gotoxy(6,9);
  	cout<<"I";
  	gotoxy(6,10);
  	cout<<"I";
  	gotoxy(6,11);
  	cout<<"I";
  	gotoxy(6,12);
  	cout<<"I";
  	gotoxy(6,12);
  	cout<<"I";
  	gotoxy(6,13);
  	cout<<"I";
  	gotoxy(6,14);
  	cout<<"I";
  	gotoxy(6,15);
  	cout<<"I";
  	gotoxy(6,16);
  	cout<<"I";
  	gotoxy(6,17);
  	cout<<"I";
  	gotoxy(6,18);
  	cout<<"I";
  	gotoxy(6,19);
  	cout<<"I";
  	gotoxy(6,20);
  	cout<<"I";
  	gotoxy(6,22);
  	cout<<"I";
  	gotoxy(7,19);
  	cout<<"I";
  	gotoxy(7,20);
  	cout<<"I";
  	gotoxy(8,20);
  	cout<<"I";
  	gotoxy(9,24);
  	cout<<"I";
  	gotoxy(9,25);
  	cout<<"I";
  	gotoxy(9,26);
  	cout<<"I";
  	gotoxy(10,24);
  	cout<<"I";
  	gotoxy(10,25);
  	cout<<"I";
  	gotoxy(10,26);
  	cout<<"I";
  	gotoxy(11,24);
  	cout<<"I";
  	gotoxy(11,25);
  	cout<<"I";
  	gotoxy(12,24);
  	cout<<"I";
  	//Siguen las S
	textcolor(6);
	
  	gotoxy(9,15);
  	cout<<"S";
  	gotoxy(9,16);
  	cout<<"S";
  	gotoxy(9,17);
  	cout<<"S";
  	gotoxy(10,9);
  	cout<<"S";
  	gotoxy(10,10);
  	cout<<"S";
  	gotoxy(10,11);
  	cout<<"S";
  	gotoxy(10,12);
  	cout<<"S";
  	gotoxy(10,13);
  	cout<<"S";
  	gotoxy(10,14);
  	cout<<"S";
  	gotoxy(10,15);
  	cout<<"S";
  	gotoxy(10,16);
  	cout<<"S";
  	gotoxy(11,7);
  	cout<<"S";
  	gotoxy(11,8);
  	cout<<"S";
  	gotoxy(11,9);
  	cout<<"S";
  	gotoxy(11,10);
  	cout<<"S";
  	gotoxy(11,11);
  	cout<<"S";
  	gotoxy(11,12);
  	cout<<"S";
  	gotoxy(11,13);
  	cout<<"S";
  	gotoxy(11,14);
  	cout<<"S";
  	gotoxy(11,15);
  	cout<<"S";
  	//flam2
  	textcolor(15);
  	gotoxy(12,17);
  	cout<<"S";
  	gotoxy(12,18);
  	cout<<"S";
  	gotoxy(12,19);
  	cout<<"S";
  	gotoxy(12,20);
  	cout<<"S";
  	//fin flem2
  	textcolor(6);
  	gotoxy(12,6);
  	cout<<"S";
  	gotoxy(12,7);
  	cout<<"S";
  	gotoxy(12,8);
  	cout<<"S";
  	gotoxy(12,9);
  	cout<<"S";
  	gotoxy(12,10);
  	cout<<"S";
  	
  	textcolor(15);
  	gotoxy(13,17);
  	cout<<"S";
  	gotoxy(13,18);
  	cout<<"S";
  	gotoxy(13,19);
  	cout<<"S";
  	//flem2
  	textcolor(6);
  	gotoxy(13,7);
  	cout<<"S";
  	gotoxy(13,8);
  	cout<<"S";
  	//finfelm2
  	textcolor(15);
  	gotoxy(14,15);
  	cout<<"S";
  	gotoxy(14,16);
  	cout<<"S";
  	gotoxy(14,17);
  	cout<<"S";
  	gotoxy(14,18);
  	cout<<"S";
  	gotoxy(15,10);
  	cout<<"S";
  	gotoxy(15,11);
  	cout<<"S";
  	gotoxy(15,12);
  	cout<<"S";
  	gotoxy(15,13);
  	cout<<"S";
  	gotoxy(15,14);
  	cout<<"S";
  	gotoxy(15,15);
  	cout<<"S";
  	gotoxy(16,9);
  	cout<<"S";
  	gotoxy(16,10);
  	cout<<"S";
  	gotoxy(16,11);
  	cout<<"S";
  	gotoxy(16,12);
  	cout<<"S";
  	gotoxy(16,13);
  	cout<<"S";
  	gotoxy(16,14);
  	cout<<"S";
  	gotoxy(16,15);
  	cout<<"S";
  	gotoxy(17,8);
  	cout<<"S";
  	gotoxy(17,9);
  	cout<<"S";
  	gotoxy(17,10);
  	cout<<"S";
  	//Siguen las C
  	textcolor(4);
  	gotoxy(14,4);
  	cout<<"C";
  	gotoxy(14,3);
  	cout<<"C";
  	gotoxy(15,4);
  	cout<<"C";
  	gotoxy(16,2);
  	cout<<"C";
  	gotoxy(16,3);
  	cout<<"C";
  	gotoxy(16,4);
  	cout<<"C";
  	gotoxy(17,2);
  	cout<<"C";
  	gotoxy(17,3);
  	cout<<"C";
  	gotoxy(18,1);
  	cout<<"C";
  	gotoxy(18,2);
  	cout<<"C";
  	gotoxy(19,1);
  	cout<<"C";
  	gotoxy(19,6);
  	cout<<"C";
  	gotoxy(20,1);
  	cout<<"C";
  	gotoxy(20,6);
  	cout<<"C";
  	gotoxy(20,7);
  	cout<<"C";
  	gotoxy(20,8);
  	cout<<"C";
  	gotoxy(20,9);
  	cout<<"C";
  	gotoxy(20,10);
  	cout<<"C";
  	gotoxy(20,11);
  	cout<<"C";
  	gotoxy(20,12);
  	cout<<"C";
  	gotoxy(20,13);
  	cout<<"C";
  	gotoxy(20,14);
  	cout<<"C";
  	gotoxy(20,15);
  	cout<<"C";
  	gotoxy(20,16);
  	cout<<"C";
  	gotoxy(20,17);
  	cout<<"C";
  	gotoxy(20,18);
  	cout<<"C";
  	gotoxy(20,19);
  	cout<<"C";
  	gotoxy(20,20);
  	cout<<"C";
  	gotoxy(20,21);
  	cout<<"C";
  	gotoxy(20,22);
  	cout<<"C";
  	gotoxy(20,23);
  	cout<<"C";
  	gotoxy(20,24);
  	cout<<"C";
  	gotoxy(20,25);
  	cout<<"C";
  	gotoxy(21,3);
  	cout<<"C";
  	gotoxy(21,7);
  	cout<<"C";
  	gotoxy(21,8);
  	cout<<"C";
  	gotoxy(21,9);
  	cout<<"C";
  	gotoxy(21,10);
  	cout<<"C";
  	gotoxy(21,11);
  	cout<<"C";
  	gotoxy(21,12);
  	cout<<"C";
  	gotoxy(21,13);
  	cout<<"C";
  	gotoxy(21,14);
  	cout<<"C";
  	gotoxy(21,15);
  	cout<<"C";
  	gotoxy(21,16);
  	cout<<"C";
  	gotoxy(21,17);
  	cout<<"C";
  	gotoxy(21,18);
  	cout<<"C";
  	gotoxy(21,19);
  	cout<<"C";
  	gotoxy(21,20);
  	cout<<"C";
  	gotoxy(21,21);
  	cout<<"C";
  	gotoxy(21,22);
  	cout<<"C";
  	gotoxy(21,23);
  	cout<<"C";
  	gotoxy(21,24);
  	cout<<"C";
  	gotoxy(21,25);
  	cout<<"C";
  	gotoxy(21,26);
  	cout<<"C";
  	gotoxy(22,3);
  	cout<<"C";
  	gotoxy(22,4);
  	cout<<"C";
  	gotoxy(22,25);
  	cout<<"C";
  	gotoxy(22,26);
  	cout<<"C";
  	gotoxy(22,27);
  	cout<<"C";
  	gotoxy(23,3);
  	cout<<"C";
  	gotoxy(23,4);
  	cout<<"C";
  	gotoxy(23,5);
  	cout<<"C";
  	gotoxy(23,6);
  	cout<<"C";
  	gotoxy(23,7);
  	cout<<"C";
  	gotoxy(23,8);
  	cout<<"C";
  	gotoxy(23,9);
  	cout<<"C";
  	gotoxy(23,10);
  	cout<<"C";
  	gotoxy(23,11);
  	cout<<"C";
  	gotoxy(23,12);
  	cout<<"C";
  	gotoxy(23,13);
  	cout<<"C";
  	gotoxy(23,14);
  	cout<<"C";
  	gotoxy(23,15);
  	cout<<"C";
  	gotoxy(23,16);
  	cout<<"C";
  	gotoxy(23,17);
  	cout<<"C";
  	gotoxy(23,18);
  	cout<<"C";
  	gotoxy(23,19);
  	cout<<"C";
  	gotoxy(23,20);
  	cout<<"C";
  	gotoxy(23,21);
  	cout<<"C";
  	gotoxy(23,22);
  	cout<<"C";
  	gotoxy(23,23);
  	cout<<"C";
  	gotoxy(23,26);
  	cout<<"C";
  	gotoxy(23,27);
  	cout<<"C";
  	gotoxy(24,4);
  	cout<<"C";
  	gotoxy(24,5);
  	cout<<"C";
  	gotoxy(24,6);
  	cout<<"C";
  	gotoxy(24,7);
  	cout<<"C";
  	gotoxy(24,8);
  	cout<<"C";
  	gotoxy(24,9);
  	cout<<"C";
  	gotoxy(24,10);
  	cout<<"C";
  	gotoxy(24,11);
  	cout<<"C";
  	gotoxy(24,12);
  	cout<<"C";
  	gotoxy(24,13);
  	cout<<"C";
  	gotoxy(24,14);
  	cout<<"C";
  	gotoxy(24,15);
  	cout<<"C";
  	gotoxy(24,16);
  	cout<<"C";
  	gotoxy(24,17);
  	cout<<"C";
  	gotoxy(24,18);
  	cout<<"C";
  	gotoxy(24,19);
  	cout<<"C";
  	gotoxy(24,20);
  	cout<<"C";
  	gotoxy(24,21);
  	cout<<"C";
  	gotoxy(24,22);
  	cout<<"C";
  	gotoxy(24,23);
  	cout<<"C";
  	gotoxy(24,24);
  	cout<<"C";
  	gotoxy(24,27);
  	cout<<"C";
  	gotoxy(25,23);
  	cout<<"C";
  	gotoxy(25,24);
  	cout<<"C";
  	gotoxy(26,24);
  	cout<<"C"; 
	   
 }

void datos(){
	
	textcolor(12);
 	gotoxy(50,2);
	cout<<"Universidad Autonoma de Aguascalientes";
  	gotoxy(50,4);
  	textcolor(3);
  	cout<<"Carrera: ";
  	gotoxy(50,5);
  	textcolor(13);
  	cout<<"Ingenieria en Sistemas Computacionales";
	gotoxy(50,7);
	textcolor(4);
  	cout<<"Materia: ";
  	gotoxy(50,8);
  	textcolor(11);
	cout<<"Programacion 1";
  	gotoxy(50,10);
  	textcolor(14);
  	cout<<"Proyecto: ";
	gotoxy(50,11);
	textcolor(3);
  	cout<<"Memoria";
  	gotoxy(50,13);
  	textcolor(2);
	cout<<"Equipo";
  	gotoxy(50,14);
  	textcolor(11);
  	cout<<"Carlos Enrique Blanco Ortiz";
	gotoxy(50,15);
	textcolor(9);
  	cout<<"Cinthia Edith Garcia de Luna"<<endl;
  	gotoxy(50,16);
  	textcolor(13);
  	cout<<"Alondra Lizbeth Ibarra Chavez"<<endl;
  	gotoxy(50,17);
  	textcolor(7);
  	cout<<"Diego Lopez Flores";
  	gotoxy(50,19);
  	textcolor(15);
  	cout<<"Maestra: ";
  	gotoxy(50,20);
  	textcolor(10);
  	cout<<"Georgina Salazar Padilla";
  	gotoxy(50,22);
  	textcolor(6);
  	cout<<"Fecha: ";
  	gotoxy(58,22);
  	cout<<"23/Mayo/2023";
  	gotoxy(30,30);
  	cout<<"Presione cualquier tecla para continuar :)";
  	getch();
  	system("cls");
}

void pantalla2()
{
	margenPantallas();
	textcolor(3);
	gotoxy(5,2);
	cout<<"____       __  __      ____       __  __      ____       __  __      ______    ____        ______                 ______    __  __\n";
	gotoxy(5,3);
	cout<<"/\\  _`\\    /\\ \\/\\ \\    /\\  _`\\    /\\ \\/\\ \\    /\\  _`\\    /\\ \\/\\ \\    /\\__  _\\  /\\  _`\\     /\\  _  \\               /\\__  _\\  /\\ \\/\\ \\ \n";
	gotoxy(5,4);
	cout<<"\\ \\ \\L\\_\\  \\ \\ `\\\\ \\   \\ \\ \\/\\_\\  \\ \\ \\ \\ \\   \\ \\ \\L\\_\\  \\ \\ `\\\\ \\   \\/_/\\ \\/  \\ \\ \\L\\ \\   \\ \\ \\L\\ \\              \\/_/\\ \\/  \\ \\ \\ \\ \\ \n";
	gotoxy(5,5);
	cout<<" \\ \\  _\\L   \\ \\ , ` \\   \\ \\ \\/_/_  \\ \\ \\ \\ \\   \\ \\  _\\L   \\ \\ , ` \\     \\ \\ \\   \\ \\ ,  /    \\ \\  __ \\                \\ \\ \\   \\ \\ \\ \\ \\ \n";
	gotoxy(5,6);
	cout<<"  \\ \\ \\L\\ \\  \\ \\ \\`\\ \\   \\ \\ \\L\\ \\  \\ \\ \\_\\ \\   \\ \\ \\L\\ \\  \\ \\ \\`\\ \\     \\ \\ \\   \\ \\ \\\\ \\    \\ \\ \\/\\ \\                \\ \\ \\   \\ \\ \\_\\ \\ \n";
	gotoxy(5,7);
	cout<<"   \\ \\____/   \\ \\_\\ \\_\\   \\ \\____/   \\ \\_____\\   \\ \\____/   \\ \\_\\ \\_\\     \\ \\_\\   \\ \\_\\ \\_\\   \\ \\_\\ \\_\\                \\ \\_\\   \\ \\_____\\ \n";
	gotoxy(5,8);
	cout<<"    \\/___/     \\/_/\\/_/    \\/___/     \\/_____/    \\/___/     \\/_/\\/_/      \\/_/    \\/_/\\/_/    \\/_/\\/_/                 \\/_/    \\/_____/ \n";
	    
	cout<<endl<<endl<<endl<<endl<<endl; 
	
	cout<<"                 ____       ____       ______      ______                 ____     ______      __         ______      ____       ____        ______     \n";
	cout<<"     /'\\_/`\\    /\\  _`\\    /\\  _`\\    /\\__  _\\    /\\  _  \\               /\\  _`\\  /\\  _  \\    /\\ \\       /\\  _  \\    /\\  _`\\    /\\  _`\\     /\\  _  \\    \n";
	cout<<"    /\\      \\   \\ \\ \\L\\_\\  \\ \\ \\_/\\ \\  \\/_/\\ \\/    \\ \\ \\L\\ \\              \\ \\ \\L\\ \\ \\ \\L\\ \\   \\ \\ \\      \\ \\ \\L\\ \\   \\ \\ \\L\\ \\  \\ \\ \\L\\ \\   \\ \\ \\L\\ \\   \n";
	cout<<"    \\ \\ \\__\\ \\   \\ \\  _\\L   \\ \\ \\ \\ \\    \\ \\ \\     \\ \\  __ \\              \\ \\ ,__/ \\ \\  __ \\   \\ \\ \\  __  \\ \\  __ \\   \\ \\  _ <'  \\ \\ ,  /    \\ \\  __ \\  \n";
	cout<<"     \\ \\ \\_/\\ \\   \\ \\ \\L\\ \\  \\ \\ \\_\\ \\    \\_\\ \\__   \\ \\ \\/\\ \\              \\ \\ \\/   \\ \\ \\/\\ \\   \\ \\ \\L\\ \\  \\ \\ \\/\\ \\   \\ \\ \\L\\ \\  \\ \\ \\\\ \\    \\ \\ \\/\\ \\ \n";
	cout<<"      \\ \\_\\\\ \\_\\   \\ \\____/   \\ \\____/    /\\____\\   \\ \\_\\ \\_\\              \\ \\_\\    \\ \\_\\ \\_\\   \\ \\____/   \\ \\_\\ \\_\\   \\ \\____/   \\ \\_\\ \\_\\   \\ \\_\\ \\_\\\n";
	cout<<"       \\/_/ \\/_/    \\/___/     \\/___/     \\/____/    \\/_/\\/_/               \\/_/     \\/_/\\/_/    \\/___/     \\/_/\\/_/    \\/___/     \\/_/\\ /    \\/_/\\/_/\n";
	   
	gotoxy(3,30);
	textcolor(12);
	cout<<"\t\t\t\tDicen que las personas tienen el hilo rojo del destino, pues tambien las palabras lo tienen";
	getch();
}

void despedida()
{
	char cp = 219; //cuadro pintado	
	textcolor(10);
	gotoxy(48,4);cout<<cp<<cp<<cp<<cp; gotoxy(56,4); cout<<cp<<cp<<cp<<cp;
	gotoxy(48,5);cout<<cp<<cp<<cp<<cp; gotoxy(56,5); cout<<cp<<cp<<cp<<cp;
	gotoxy(48,6);cout<<cp<<cp<<cp<<cp; gotoxy(56,6); cout<<cp<<cp<<cp<<cp;
	gotoxy(48,7);cout<<cp<<cp<<cp<<cp; gotoxy(56,7); cout<<cp<<cp<<cp<<cp;
	
	gotoxy(52,8);cout<<cp<<cp<<cp<<cp;
	gotoxy(50,9);cout<<cp<<cp<<cp<<cp<<cp<<cp<<cp<<cp;
	gotoxy(50,10);cout<<cp<<cp<<cp<<cp<<cp<<cp<<cp<<cp;
	gotoxy(50,11);cout<<cp<<cp<<cp<<cp<<cp<<cp<<cp<<cp;
	gotoxy(50,12);cout<<cp<<cp; gotoxy(56,12);cout<<cp<<cp;
}

	
#endif
