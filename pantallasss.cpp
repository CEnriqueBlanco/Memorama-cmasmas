#include <iostream>
#include <windows.h>
#include <string>
#include <time.h>
#include <conio.h>
#include <mmsystem.h> //musica
#pragma comment(lib, "winmm.lib")

using namespace std;

//prototipos
void textcolor(int n);
void gotoxy(int x,int y);
void logo();
void datos();
//Pantalla 1
void pantalla2();
void margenPantallas();
//pantalla 3
void pantalla3();
int menuPrincipal();

int main() 
{
		
	srand(time(0));
	bool simulacion;
	
	int escoger,palabras,resp;
	reproducirSonido("Opciones.wav");	
	
	
	//Parte del juego
	
	//Posible simulacion
	
	reproducirSonido("Juego.wav");
	
	tablero(simulacion);
	//Parte de mantenimiento
	reproducirSonido("Mantenimiento.wav");
	simulacion=false;
	escoger= escoger_tema(simulacion);
	mantenimiento(escoger,simulacion);
	return 0;
}

//PANTALLA 3


int menuPrincipal() 
{
    string opciones[] = {"1.- Jugar", "2.- Simulacion", "3.- Reporte", "4.- Mantenimiento", "5.- Salir"};
    int tecla;
    int opcion;
	system("cls");
    do 
	{
        margenPantallas();
        pantalla3();
        
        textcolor(14); // Amarillo
        gotoxy(50, 10);
        cout << "ENCUENTRA TU MEDIA PALABRA";

        for (int i = 0; i < 5; i++) 
		{
            gotoxy(50, 12 + i * 2);

            // Cambiar el color de la opción seleccionada
            if (i == opcion) 
			{
                textcolor(12); // Rojo
            }else 
			{
                textcolor(15); // Blanco
            }

            cout << opciones[i];
        }

        tecla = _getch();

        if (tecla == 80)//Flecha abajo 
		{ 
            opcion = (opcion + 1) % 5;
        } else if (tecla == 72)// Flecha arriba
		{
        	opcion = (opcion - 1 + 5) % 5;
        }

        if (tecla == 13)// Enter
		{
            system("cls");
            textcolor(15); // Blanco
            gotoxy(50, 10);
            
            switch (opcion)
			 {
                case 0: // Jugar
                    // Enrique
                    break;
                case 1: // Simulacion
                    // Enrique
                    break;
                case 2: // Reporte
                    // Enrique
                    break;
                case 3: // Mantenimiento
                    // Enrique
                    break;
                case 4: // Salir
                gotoxy(50,14);
                    cout<<"Nos vemos...";
                    break;
            }
            
            if (opcion == 4)
			{ 
                return 0;
            }
        }
        
    }while (true);
}
