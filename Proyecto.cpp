#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <fstream>

#include "estetica.h"
#include "mantenimiento.h"
#include "juego.h"
#include "reportes.h"

using namespace std;


void tablero(bool simulacion);
void mantenimiento(int tema_pares,bool simulacion);
int escoger_tema(bool simulacion);
void reportes();
int menuPrincipal(bool simulacion);
void leerBin();


int main(int argc, char** argv) 
{
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_MAXIMIZE);
	srand(time(NULL));
	bool simulacion;
	//pantalla1
	reproducirSonido("Pantallas.wav");
	logo();
	datos();
	Beep(200, 200);
	cout<<endl<< endl;
	//pantalla2
	pantalla2();
	Beep(200, 300);
	//pantalla3
	pantalla3 ();
	menuPrincipal(simulacion);

	return 0;

} 


int menuPrincipal(bool simulacion) 
{
    string opciones[] = {"1.- Jugar", "2.- Simulacion", "3.- Reporte", "4.- Mantenimiento", "5.- Salir"};
    int tecla;
    int opcion;
    int escoger;
	system("cls");	
	reproducirSonido("MenuPrincipal.wav");
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
        Beep(200,200);
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
                	simulacion=false;
                    tablero(simulacion);
                   	reproducirSonido("MenuPrincipal.wav"); 
                    break;
                case 1: // Simulacion
                	simulacion=true;

                	tablero(simulacion);
					reproducirSonido("MenuPrincipal.wav"); 	
                    break;
                case 2: // Reporte
                	reportes();
                    break;
                case 3: // Mantenimiento
                	reproducirSonido("Mantenimiento.wav");
                	escoger= escoger_tema(simulacion);
					mantenimiento(escoger,simulacion);
                    break;
                case 4: // Salir
                	margen();
                    reproducirSonido("Despedida.wav");
                    despedida();
                    textcolor(11);
                	gotoxy(49,14);
                    cout<<"Nos vemos...";
                    gotoxy(40,15);
                    cout<<"Presione cualquier tecla para salir";
                    getch();
                    
                    break;
            }
            if (opcion == 4)
			{ 
                return 0;
            }
        }        
    }while (true);
       
}


void tablero(bool simulacion)
{
	int opc, ren, col,tam;
    palabrasCategoria* palabras;//Vector dinamico tipo palabrasCategoria	
    datosBin guardar;
    reproducirSonido("Opciones.wav");
    string alias= aliascorrecto(simulacion);
    
    int tema_pares=escoger_tema(simulacion);
	do{
	system("cls");
	margen();
	gotoxy(40,11);
	textcolor(9);
	cout<<" Dificultad Facil  | 3 pares de palabras | "; 
	textcolor(13);
	cout<<" [1] ";
	textcolor(9);	
	gotoxy(40,12);
	cout<<" Dificultad Normal | 6 pares de palabras | ";		
	textcolor(13);
	cout<<" [2] ";
	textcolor(9);
	gotoxy(40,13);
	cout<<" Dificultad Diicil | 8 pares de palabras | ";
	textcolor(13);
	cout<<" [3] ";
	textcolor(9);
	gotoxy(45,14);	
	cout<<"Elige la dificultad del juego: ";
	textcolor(14);
	
	if(simulacion==true)
	{
		opc=1+rand()%(3 - 1 + 1);
		gotoxy(43,15);
		Sleep(600);
		cout<<"La maquina ha escogido la dificultad ";
		textcolor(10);
		cout<<opc;
		Sleep(2000);
	}
	else
	{
		cin>>opc;	
		Beep(200,200);	
	}
	
	if( opc < 1 || opc > 3 )
	{
		textcolor(12);
		gotoxy(45,15);
		cout<<"Error, esa dificultad no existe";
		gotoxy(48,16);
		cout<<"Vuelva a intentarlo";
		Beep(500, 800);
		Sleep(1000);
		system("cls");
	}//fin if
			
	}while( opc < 1 || opc > 3 );//Fin do while


	switch(opc){
		case 1:
			tam= 3;
			ren = 3;
			col = 2;
			break;
		case 2:
			tam=6;
			ren = 4;
			col = 3;
			break;
		case 3: 
			tam=8;
			ren = 4;
			col = 4;	
			break;
	}//fin switch

	int palabras_Archivo = contarpalabras(tema_pares);
	palabras= pedir_espacio(palabras_Archivo);
    llenarVector(tema_pares, palabras_Archivo, tam, palabras);
    
	shuffle(palabras,tam*2);
	shuffle(palabras,tam*2);
	shuffle(palabras,tam*2);
	shuffle(palabras,tam*2);
	shuffle(palabras,tam*2);
	
	palabrasCategoria **palabras_M= palabrasVectorAMatriz(tam*2,ren,col,palabras);
	ocultarMatriz(palabras_M,ren,col);
	
	datosJug(ren, col, palabras_M, alias);
	system("cls");

	clock_t contTiempo;
	contTiempo=clock();
	
	destaparPalabras(palabras_M, ren, col, tam,alias,simulacion);		
	
	contTiempo= clock()-contTiempo;
	reproducirSonido("win.wav");
	ganador(contTiempo,alias);
	llenarBin(guardar,alias,tema_pares,ren,col,contTiempo);
	//reportes(guardar);

	liberarMatriz(palabras_M,ren);
    delete[] palabras;	
	
}//Fin funcion


int escoger_tema(bool simulacion)
{
	int palabra=0;
	string escoger;
	string simEscoger[3]={"colores","paises","animales"};

	
	do
	{
		system("cls");
		margen();	
		gotoxy(53,10);
		textcolor(12);
		cout<<"[COLORES]";
		gotoxy(54,12);
		textcolor(14);
		cout<<"[PAISES]";
		gotoxy(53,14);
		textcolor(11);
		cout<<"[ANIMALES]";
		gotoxy(43,16);
		textcolor(8);
		cout<<"Que categoria desea escoger";

		if(simulacion==true)
		{
			int aleatorio= 0 +  rand()% (3-0);	
			escoger=simEscoger[aleatorio];
			gotoxy(37,17);
			textcolor(12);
			Sleep(600);
			cout<<"LA MAQUINA HA ESCOGIDO LA SIGUIENTE CATEGORIA:";
			gotoxy(55,18);
			textcolor(10);
			cout<<escoger;
			Sleep(1500);
		}
		else
		{
			gotoxy(45,17);			
			cout<<"Escriba la categoria: ";
			fflush(stdin);
			textcolor(4);
			getline(cin,escoger);
			Beep(200,200);				
		}



		if(escoger == "colores" || escoger == "Colores" || escoger == "COLORES" )
		{
			palabra = 1;	
		}
		else if (escoger == "paises" || escoger == "Paises" ||escoger == "PAISES") 
		{
			palabra = 2;		
		}
		else if(escoger == "animales" || escoger == "Animales" || escoger == "ANIMALES")	
		{
			palabra=3;
		} 
		else
		{
			palabra=4;
		}
		
		if(palabra < 1 || palabra > 3 )
		{
			system("cls");
			gotoxy(50,12);
			textcolor(12);
			cout<<"Valor incorrecto";
			gotoxy(46,13);
			cout<<"Ingrese un valor valido";
			Beep(600,200);
			Sleep(1300);
		}
		
	}while(palabra < 1 || palabra > 3 );

	
	return palabra;
}

void mantenimiento(int tema_pares, bool simulacion)
{
	fstream archivo;
	string categoria;
	int opc,n=0;
	int tema = tema_pares;
	int palabras = contarpalabras(tema);
	int palabrasRestantes;
	do{
		system("cls");
		margen();
		gotoxy(47,10);
		cout<<"Agregar                       | [1]";
		gotoxy(47,11);
		cout<<"Eliminar                      | [2]";
		gotoxy(47,12);	
		cout<<"Leer                          | [3]";
		gotoxy(47,13);
		cout<<"Regresar al menu principal    | [4]";
		gotoxy(47,14);
		cout<<"Salir                         | [5]" ;
		gotoxy(58,16);
		cout<<"Opcion: ";
		cin>>opc;	
		Beep(200,200);
		system("cls");
		switch(opc){
			case 1: 
					agregar_palabra(tema);
			break;
			
			case 2:
					system("cls");
					margen();
					gotoxy(46,9);
					cout<<"Cuantas palabras deseas eliminar: ";
					cin>>n;
					Beep(200,200);
					palabrasRestantes = contarpalabras(tema);
					if(palabrasRestantes - n < 6)
    				{
        				gotoxy(48,10);
        				cout << "No se pueden eliminar palabras";
        				gotoxy(50,11);
						cout<<"Cantidad minima alcanzada.";
						Beep(200,200);
        				Sleep(1500);
        				break;
    				}
					for(int i=0; i<n; i++)
					{
						margen();
						gotoxy(54,10);
						cout<<"Palabra a eliminar: "<<endl;
						gotoxy(60,11);
						fflush(stdin);
						getline(cin,categoria);
						eliminar_palabra(tema,categoria);	
						
						palabrasRestantes = contarpalabras(tema);					
					}
					break;										
						
			case 3:
					leer_categoria(tema);
					break;
			case 4:	
					menuPrincipal(simulacion);
					break;	
			case 5: 
					cout<<"Saliendo del programa";
					break;		
		}
			
	}while(opc!=5);	
}


void reportes()
{
	int opc;
	bool simulacion;
	reproducirSonido("Reporte.wav");
	do
	{
		
	system("cls");
	margen();
	textcolor(11);
	gotoxy(50,1); cout<<"REPORTES";
	gotoxy(40,2); cout<<"Reporte por categoria                  | [1]";
	gotoxy(40,3); cout<<"Reporte Ascendente por alias           | [2]";
	gotoxy(40,4); cout<<"Reporte descendente por tiempos        | [3]";
	gotoxy(40,5); cout<<"Regresar al menu principal             | [4] ";
	gotoxy(45,6); cout<<"Que opcion desea: ";
	cin>>opc;
	Beep(200,200);
	if(opc<1 || opc>4)
	{
		gotoxy(46,7);
		cout<<"Opcion no valida";
			Beep(600,200);
	}
	
	switch(opc)
	{
		case 1:
			leerBin();
			break;
		case 2:
			ordenAscendente();
			break;
		case 3:
			break;
		case 4:
			
			break;			
	}	
	
	
	}while(opc!=4);
	system("cls");

	
}



void leerBin()
{
	bool simulacion;
	string tema;
    datosBin leerBinario;
    fstream archivo;
    int tema_pares=escoger_tema(simulacion);

        switch (tema_pares)
    {
        case 1:
            tema = "Colores";
            break;
        case 2:
            tema = "Paises";
            break;
        case 3:
            tema = "Animales";
            break;
    }
    
	archivo.open("DatosBinario.dat", ios::binary|ios::in);
	system("cls");
    if (!archivo) {
        cerr << "No se puede abrir el archivo!" << endl;
        cin.get();
        return;
    }
    textcolor(10);
    gotoxy(2,2);
    cout<<"REPORTE DE LA CATEGORIA "<<tema;
   	int pos_y=4; 
    while (archivo.read((char*)(&leerBinario), sizeof(datosBin)))
    {
    	if (leerBinario.cat == tema)
    	{
	    	textcolor(11);
    		gotoxy(2,pos_y);
          	cout << "Alias: " << leerBinario.alias;
          	pos_y++;
          	gotoxy(2,pos_y);
	        cout << "Fecha: " << leerBinario.fecha;
	        pos_y++;
	        gotoxy(2,pos_y);
	        cout<<"Tiempo: ";
	        if(leerBinario.tiempo - (int)leerBinario.tiempo == 0)
			{
				cout<<leerBinario.tiempo<<" minutos";
			}
			else
			{
				cout<<leerBinario.tiempo<<" segundos";
			}
			pos_y++;
	        gotoxy(2,pos_y);
	        cout << "Renglones: " << leerBinario.ren;
	        pos_y++;
	        gotoxy(2,pos_y);
	        cout << "Columnas: " << leerBinario.col;
	        pos_y++;
	        gotoxy(2,pos_y);
	        cout << endl; 
	        pos_y++;
		}

    }
		getch();
		system("cls");
        archivo.close();
}

