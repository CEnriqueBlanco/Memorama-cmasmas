#ifndef FUNCIONESJUEGO
#define FUNCIONESJUEGO
#include <iostream>
#include <iomanip>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct palabrasCategoria{
    string palabra;
	bool tapado;
};


bool alias(string& nombre)
{
	if(nombre.size() < 4 || nombre.size() > 12 )
	{
		system("cls");
		margen();
		gotoxy(40,10);
		cout<<"EL NOMBRE DEBE DE SER DE 4 A 12 CARACTERES";
		gotoxy(49,11);
		cout<<"INGRESA UN NOMBRE VALIDO"<<endl;
		gotoxy(61,12);
		Sleep(1800);
		return false;
	}//if
	
	if(!isalpha(nombre[0]))
	{
		system("cls");
		margen();
		gotoxy(40,10);
		cout<<"EL NOMBRE DEBE DE EMPEZAR POR UNA LETRA";
		gotoxy(49,11);
		cout<<"INGRESA UN NOMBRE VALIDO"<<endl;
		gotoxy(61,12);
		Sleep(1800);
		return false;		
	}//if
	
	
	for(int i=0; i<nombre.size(); i++)
	{
		char c = nombre[i]; 
		
		if(!isalnum(c) && c !='_')
		{
			system("cls");
			margen();
			gotoxy(30,10);
			cout<<"EL NOMRBE NO PUEDE TENER CARACTERES DIFERENTES DEL GUION BAJO";
			gotoxy(49,11);
			cout<<"INGRESA UN NOMBRE VALIDO"<<endl;
			gotoxy(61,12);
			Sleep(1800);
			
			return false;
		}//fin if		
	
	}//fin for	


	return true;	
}

string aliascorrecto(bool simulacion)
{
	string nombre;
	bool correcto=false;
	do
	{
	margen();
	gotoxy(50,10);
	textcolor(13);
	cout<<"Nombre del jugador: "<<endl;

	textcolor(10);
	
	if(simulacion==true)
	{
		int aleatorio = 1 + rand()% (10000 - 1 + 1);
		stringstream aleat;
		aleat <<"Bot"<< aleatorio;
		nombre = aleat.str();
		gotoxy(45,11);
		Sleep(500);
		cout<<"El nombre de la maquina es ";
		textcolor(10);
		cout<<nombre;
		Sleep(2000); 
	}
	else
	{
		gotoxy(54,11);
		fflush(stdin);
		getline(cin,nombre);
			
	}

	correcto = alias(nombre);
	system("cls");			
	}while(!correcto);//Fin del while
	
	return nombre;

}


void matriz(int** tablero, int ren, int col){
	
	for(int i=0; i<ren; i++)
	{
		for(int j=0; j<col; j++)
		{
			cout<<tablero[i][j]<<" ";
		}
		cout<<endl;
	}
}


int* pedir_espacioVector(int tam)
{
    int *ptr;
    ptr = new int [tam];
    
    return ptr;
}//Fin funcion


palabrasCategoria* pedir_espacio(int tam)
{
	palabrasCategoria *ptr;
	ptr= new palabrasCategoria[tam];
	
	return ptr;	
}//Fin funcion 



bool AleatoriosNoRepetidos(int n, int tam, int *vec){
	for(int i=0; i<tam; i++){
		if(n==vec[i]){
			return true;
		}
	}
	return false;
}//Fin funcion

void llenarVector(int tema_pares,int palabras,int tam, palabrasCategoria* &word_struct)
{
	fstream documento;
	string palabra;
	int pickWord;
	int *indicesAleatorios = pedir_espacioVector(tam);
	word_struct = pedir_espacio(tam*2);
	int cont=0;
	srand(time(NULL));

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
	while (cont < tam)
	{
		pickWord = rand ()% palabras;
		if (!AleatoriosNoRepetidos(pickWord, palabras, indicesAleatorios))		
		{
			documento.clear();
			documento.seekg(0);
			for(int i=0; i<=pickWord; i++)
			{
				documento >> palabra;
			}
			indicesAleatorios[cont] = pickWord;
			word_struct[cont].palabra = palabra; 
			word_struct[cont + tam].palabra = palabra;
			documento >> palabra;

			cont++;
		}

	}
		delete []indicesAleatorios;
		documento.close();
}

void datos(int tam,string& nombre,int palabrasDestapadas)
{		
	textcolor(15);
	string hora =obtenerHora();
	string fecha = obtenerFecha();	
	
	gotoxy(48,3); cout<<"ALIAS: ";
	cout<<nombre;
	gotoxy(1,1);  cout<<"FECHA: ";
	cout<< fecha;
	gotoxy(1,2);  cout<<"HORA: ";
	cout<< hora;
	gotoxy(13,10);cout<<"PARES"; 
	gotoxy(10,11);cout<<"ENCONTRADOS";

	gotoxy(12,12);cout<<"[ "<<palabrasDestapadas<<"| "<<tam/2<<"]";		

	

}


void imprimirMatriz(int tam, palabrasCategoria** &word_struct, int ren, int col, string &alias,int palabrasDestapadas)
{
	margen();
	margenJuego(tam);
	datos(tam,alias,palabrasDestapadas);	
	for(int i=0; i<ren; i++)
	{
		for(int j=0; j<col; j++)
		{
			int indice = i+j*ren;
				if(word_struct[i][j].tapado)
				{
					switch(tam)
					{
						case 6:
							gotoxy(46+25*j,9+5*i);
							break;
							
						case 12:
							gotoxy(37+17*j,8+4*i);
							break;
						case 16:
							gotoxy(36+13*j,8+4*i);
							break;		
					}
					//cout << setw(16) << indice+1;
				textcolor(14);
				cout<<indice+1;
				}
				else
				{
						switch(tam)
					{
						case 6:
							gotoxy(44+25*j,9+5*i);
							break;
						case 12:
							gotoxy(37+17*j,8+4*i);
							break;
						case 16:
							gotoxy(36+13*j,8+4*i);
							break;		
					}
				textcolor(10);	
				cout<<word_struct[i][j].palabra;	
					//cout<< setw(16)<< word_struct[i][j].palabra;
				}
		}
		cout << endl;
	}
}

void ocultarMatriz(palabrasCategoria **mat, int ren, int col)
{
	for(int i=0; i<ren; i++)
	{
		for(int j=0; j<col; j++)
		{
			mat[i][j].tapado=true;//true es para tapadas
		}
	}
}

palabrasCategoria** pedir_espacioM(int ren, int col)
{
	palabrasCategoria **matriz;
	matriz=new palabrasCategoria*[ren];
	for(int i=0; i<ren; i++)
	{
		matriz[i]= new palabrasCategoria[col];
	}

	return matriz;
}


palabrasCategoria** palabrasVectorAMatriz(int tam,int ren, int col, palabrasCategoria* word_struct) {
    palabrasCategoria** matriz = pedir_espacioM(ren, col);

    for (int i = 0; i < ren; i++) {
        for (int j = 0; j < col; j++) 
		{
            int indice = i * col + j;
            if (indice < tam) 
			{
                matriz[i][j] = word_struct[indice];
            } 
        }
    }

    return matriz;
}

void liberarMatriz(palabrasCategoria** matriz, int ren)
{
    for (int i = 0; i < ren; i++)
	{
        delete[] matriz[i];
    }
    delete[] matriz;
}

void destaparPalabra(palabrasCategoria** &word_struct, int ren, int col, int x, int y, int& palabrasDestapadas) {
    if (word_struct[x][y].tapado) {
        word_struct[x][y].tapado = false;
        palabrasDestapadas++;
    }
}

void shuffle(palabrasCategoria *vec, int n) {
    srand(time(NULL));
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            palabrasCategoria t = vec[j];
            vec[j] = vec[i];
            vec[i] = t;
        }
    }
}

void datosJug(int ren, int col, palabrasCategoria **mat, string& alias)
{
	char archivo[30]= "DatosJugadores.txt";
	fstream documento;
		string hora =obtenerHora();
	string fecha = obtenerFecha();	
	
	documento.open(archivo,ios::out|ios::app);
	
	documento <<"Dimension: "<< ren << "X" << col << " Alias: "<< alias << endl;
	documento << "Fecha:" << fecha <<" Hora:" << hora << endl;

	for(int i=0; i<ren; i++)
	{
		for(int j=0; j<col;j++)
		{
			documento<<left<<setw(15)<<mat[i][j].palabra;
		}
			documento<<endl;
	}
	documento<<endl<<endl;
	documento.close();
}


void destaparPalabras(palabrasCategoria** palabras_M, int ren, int col, int tam, string& alias, bool simulacion)
{
    int palabrasDestapadas = 0;
    int primerNumero, segundoNumero;
    int uncovered_words = 0; 
   	reproducirSonido("Juego.wav");
    
    while (uncovered_words < tam)
    {
        system("cls");
        imprimirMatriz(tam * 2, palabras_M, ren, col, alias, uncovered_words);
        textcolor(7);
        gotoxy(45, 24);
        cout << "Ingrese el primer numero: ";
		       
        if(simulacion==true)
        {
        	do{
        		primerNumero= 1+ rand()% (ren*col);
			}while(!palabras_M[(primerNumero - 1) % ren][(primerNumero - 1) / ren].tapado);
			Sleep(400);
			cout << primerNumero << endl;
            Sleep(400);
		}
		else
		{
        cin >> primerNumero;			
		}
        


        system("cls");

        if (primerNumero < 1 || primerNumero > ren * col)//Este if verifica si el numero dado esta dentro de los limites
        {
            imprimirMatriz(tam * 2, palabras_M, ren, col, alias, uncovered_words);
            textcolor(12);
            gotoxy(52, 24);
            Beep(500, 200);
            cout << "Celda no valida" << endl;
            Sleep(1000);
            continue;//Esta  regresa al inicio del bucle 
        }

        // Coordenadas del primer numero
        int x1 = (primerNumero - 1) % ren;
        int y1 = (primerNumero - 1) / ren;

			
        if (palabras_M[x1][y1].tapado)//Verifica si estan tapadas las palabras
        {
            destaparPalabra(palabras_M, ren, col, x1, y1, palabrasDestapadas);
            imprimirMatriz(tam * 2, palabras_M, ren, col, alias, uncovered_words);
            textcolor(7);
            gotoxy(45, 24);
            cout << "Ingrese el segundo numero: ";
            if(simulacion==true)
            {
            	do 
				{
            		segundoNumero = 1 + rand() % (ren*col);
                }while(segundoNumero == primerNumero || !palabras_M[(segundoNumero - 1) % ren][(segundoNumero - 1) / ren].tapado);
                Sleep(400);
                cout << segundoNumero << endl;
                Sleep(400);
			}
			else
			{
	            cin >> segundoNumero;			
			}


            //Coords del segundo numero
            int x2 = (segundoNumero - 1) % ren;
            int y2 = (segundoNumero - 1) / ren;
            
			//Verifica si el seg numero es dif del primero y si el segundo num esta dentro de los lim	
            if (segundoNumero != primerNumero && x2 >= 0 && x2 < ren && y2 >= 0 && y2 < col)
            {
                if (palabras_M[x2][y2].tapado)
                {
                    destaparPalabra(palabras_M, ren, col, x2, y2, palabrasDestapadas);
                    imprimirMatriz(tam * 2, palabras_M, ren, col, alias, uncovered_words);

                    // Comprueba si las palabras destapadas no son un par
                    if (palabras_M[x1][y1].palabra != palabras_M[x2][y2].palabra)
                    {
                        gotoxy(40,26);
                        textcolor(12); 
                        cout << "Las palabras destapadas no forman un par" << endl;
                        Beep(500, 600);
                        Sleep(400);
                        palabras_M[x1][y1].tapado = true;
                        palabras_M[x2][y2].tapado = true;
                        palabrasDestapadas -= 2;
                        imprimirMatriz(tam * 2, palabras_M, ren, col, alias, uncovered_words);
                    }
                    else
                    {
                    	 textcolor(11);
			            gotoxy(48,25);
			        	cout << "!!!ENCONTRASTE UN PAR!!!";
			        	Beep(800,600); 
			            Sleep(400);
                        uncovered_words++;
                    }
                }
                //si el seg numero selecciona una palabra ya destapada, vuelve a tapar
                else
                {
                    imprimirMatriz(tam * 2, palabras_M, ren, col, alias, uncovered_words);
                    textcolor(12);
                    gotoxy(45,24);
                    cout << "La palabra ya esta destapada";
                    Beep(500, 800);
                    palabras_M[x1][y1].tapado = true; 
                    Sleep(1000);
                }
            }
            //Verifica si la celda puesta esta dentro del limite
            else
            {
                imprimirMatriz(tam * 2, palabras_M, ren, col, alias, uncovered_words);
                textcolor(12);
                gotoxy(52, 25);
                cout << "celda no valida" << endl;
                Beep(500, 600);
                palabras_M[x1][y1].tapado = true;
                Sleep(400);
            }
        }
        //si el primer numero selecciona una palabra destapada, lo vuelve a pedir
        else
        {
            imprimirMatriz(tam * 2, palabras_M, ren, col, alias, uncovered_words);
            textcolor(12);
            gotoxy(45, 24);
            cout << "La palabra ya esta destapada";
            Beep(500, 600);
            Sleep(400);
        }
    }
    system("cls");

}




#endif
