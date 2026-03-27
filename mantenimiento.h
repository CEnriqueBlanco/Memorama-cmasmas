#ifndef MANTENIMIENTO
#define MANTENIMIENTO
#include <iostream>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <fstream>

using namespace std;


int contarpalabras(int tema_pares)
{
	int palabras;
	fstream documento;
	int cont=0;
	string palabra;
	
	switch(tema_pares)
	{
		case 1:
				documento.open("Colores.txt",ios::in);	
				break;
				
		case 2:	
				documento.open("Paises.txt",ios::in);		
				break;
		case 3:
				documento.open("Animales.txt",ios::in);	
				break;		
	}	
	documento.clear();
	documento.seekg( 0 );
	
	while(documento >> palabra)
	{
		cont++;
	}
	documento.close();
	return cont;
}


bool verificarExistencia(int tema_pares,string palabra)
{
    fstream archivo;
    string palabraArchivo;
    
    	switch(tema_pares)
	{
		case 1:
				archivo.open("Colores.txt",ios::in);	
				break;
				
		case 2:	
				archivo.open("Paises.txt",ios::in);		
				break;
		case 3:
				archivo.open("Animales.txt",ios::in);	
				break;		
	}	
    archivo.clear();
    archivo.seekg(0);
    

    while (archivo >> palabraArchivo)
    {
        if (palabraArchivo == palabra)
        {
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}


void agregar_palabra(int tema_pares)
{	
	fstream documento;
	char colores[] = "Colores.txt";
	char paises[] = "Paises.txt";
	char animales[] = "Animales.txt";
	
	int n,pos_y=9;
	string palabra;
	margen();
	gotoxy(33,8);
	cout<<"Cuantas palabras deseas agregar a esta categoria: ";
	cin>>n;
	
	
	switch(tema_pares)
	{
		case 1:
				documento.open(colores,ios::out|ios::app);
				break;
		case 2:	
				documento.open(paises,ios::out|ios::app);
				break;
		case 3:
				documento.open(animales,ios::out|ios::app);
				break;		
	}	

		
	if (!documento)
	{
		gotoxy(10,50);
		textcolor(12);
		cout<<"No se pudo abrir el archivo"<<endl;
		Sleep(1000);
		system("cls");		
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			margen();
			gotoxy(45,pos_y);
			cout<<"Dame la palabra a agregar: ";
			fflush(stdin);
			getline(cin,palabra);
			
			if (verificarExistencia(tema_pares, palabra))
        	{
        		gotoxy(46,10);
        		textcolor(12);
            	cout << "La palabra ya existe en el archivo." << endl;
            	Sleep(1000);
            	system("cls");
        	}
        	else
			{
				documento << palabra << " " << endl;
				pos_y++;	        		
			}

						 
		}
		documento.close();			
	}
	system("cls");
	textcolor(14);	
	gotoxy(40,10);
	cout<<"Informacion guardada con exito";	 	
	if (verificarExistencia(tema_pares, palabra))
    {
    	margen();
    	textcolor(15);
        gotoxy(46,11);
        cout << "volviendo al menu anterior." << endl;
        Sleep(1000);
    }

       			
	system("cls");	
}


void eliminar_palabra(int tema_pares,string& categoria)
{
	fstream archivo,archivo_temp;
	char resp;
	bool band=false;
	string palabra;
	char colores[] = "Colores.txt";
	char paises[] = "Paises.txt";
	char animales[] = "Animales.txt";
	char temporal[] = "Archivo_temporal.txt";
	
	switch(tema_pares)
	{
		case 1:
				archivo.open("Colores.txt",ios::in);	
				break;
				
		case 2:	
				archivo.open("Paises.txt",ios::in);		
				break;
		case 3:
				archivo.open("Animales.txt",ios::in);	
				break;		
	}		
	archivo.clear();
    archivo.seekg(0);
    archivo_temp.open("Archivo_temporal.txt",ios::out); 

	while(archivo >> palabra )
	{
		if(palabra==categoria  )
		{
			band=true;						    		
		}
		else
		{
			archivo_temp << palabra << " " <<endl;
		}

	} 	
	
	if(band==false)
	{
		gotoxy(53,12);
		textcolor(12);
		margen();
		cout<<"Palabra no encontrada"<<endl;	
		Sleep(1500);
		archivo_temp.close();
		system("del temporal");
		system("cls");
	}
	else
	{
		margen();
		gotoxy(45,13);
		textcolor(12);
		cout<<"Desea eliminar la palabra...[s/n]: ";
		fflush(stdin);
		cin.get(resp);
		
		if(resp=='s')			
		{
			margen();			
			gotoxy(45,14);
			cout<<"Esta seguro de eliminarla...[s/n]: ";
			fflush(stdin);
			cin.get(resp);
			if(resp=='s')
			{
				archivo.close();
				archivo_temp.close();
			if(tema_pares == 1)
			{
				system("del Colores.txt");
				system("ren Archivo_temporal.txt Colores.txt");					
			} 
			if(tema_pares == 2 )
			{
				system("del Paises.txt");
				system("ren Archivo_temporal.txt Paises.txt");					
			}
			if(tema_pares == 3 )
			{
				system("del Animales.txt");
				system("ren Archivo_temporal.txt Animales.txt");						
			}
			gotoxy(45,15);
			cout<<"Registro eliminado corretamente..."<<endl;
			Sleep(1000);
			system("cls");
			}
			else
			{
				system("cls");
				margen();
				gotoxy(45,10);
				textcolor(14);
				cout<<"La palabra no se ha eliminado, volviendo al menu";
				Sleep(1500);				
			}
		}	
		else
		{
			margen();
			system("cls");
			gotoxy(45,10);
			textcolor(14);
			cout<<"La palabra no se ha eliminado, volviendo al menu";
			gotoxy(35,11);
			archivo_temp.close();
			
			system("temporal");
			Sleep(1500);
		}				
	}	
}

void leer_categoria(int tema_pares)
{
	fstream documento;
	string palabra;
	int pos_y=2;
		
	switch(tema_pares)
	{
		case 1:
				documento.open("Colores.txt",ios::in);	
				break;
				
		case 2:	
				documento.open("Paises.txt",ios::in);		
				break;
		case 3:
				documento.open("Animales.txt",ios::in);	
				break;		
	}		
	documento.clear();
    documento.seekg(0);	


	if(!documento)
	{
		margen();
		gotoxy(40,10);
		textcolor(12);
		cout<<"No se ha podido leer el archivo";
		Sleep(1000);
		system("cls");		
	}

	else
	{

		system("cls");
		margen();
		gotoxy(35,1);
		cout<<"Imprimiendo la informacion desde el archivo";
		int cont=0;		
		while( documento >> palabra   )
		{
			gotoxy(50,pos_y);
			switch(tema_pares)
			{
				case 1:
						cout<<cont+1<<".- "<<palabra;	
						break;
						
				case 2:	
						cout<<cont+1<<".- "<<palabra;		
						break;
				case 3:
						cout<<cont+1<<".- "<<palabra;
						break;		
			}	
			pos_y++;
			cont++;	
		}
		getch();		
		documento.close();
		cout<<endl;	
	}	
}//Fin funcion





#endif
