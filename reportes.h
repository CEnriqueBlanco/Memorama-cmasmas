#ifndef REPORTES
#define REPORTES
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
struct datosBin{
	char alias[20];
	char fecha[20];
	float tiempo;
	char cat[20];
	int ren;
	int col;
};

int llenarBin(datosBin& guardar, string& nomjug, int tema_pares, int ren, int col, clock_t timeTot)
{
    string date = obtenerFecha();
    string palabra;
	fstream archivo;
	
    archivo.open("DatosBinario.dat", ios::binary|ios::out|ios::app);

    if (!archivo)
    {
        cerr << "No se puede abrir el archivo!" << endl;
        cin.get();
		return 1;
    }
	
    switch (tema_pares)
    {
        case 1:
            palabra = "Colores";
            break;
        case 2:
            palabra = "Paises";
            break;
        case 3:
            palabra = "Animales";
            break;
    }

    strcpy(guardar.alias,nomjug.c_str());
    strcpy(guardar.fecha,date.c_str());
    
    if(timeTot > 60000)
	{
		int minutos = timeTot /60000;
		guardar.tiempo =minutos;
	}
	else
	{
		guardar.tiempo=float(timeTot)/CLOCKS_PER_SEC;	
	}
    strcpy(guardar.cat,palabra.c_str());
    guardar.col = col;
    guardar.ren = ren;
	archivo.write((char*)(&guardar), sizeof(datosBin));
	
    archivo.close();
}



bool compararAlias(datosBin& a, datosBin& b) 
{
    int i = 0;
    while (a.alias[i] != '\0' && b.alias[i] != '\0')
	{
        char charA = tolower(a.alias[i]);
        char charB = tolower(b.alias[i]);

        if (charA != charB)
		{
            return charA < charB;
        }
        
        i++;
    }
    
    return strlen(a.alias) < strlen(b.alias);
}

void ordenAscendente() {
    datosBin leerBin;
    datosBin datosB[100];
    fstream archivo;
    int numD = 0;
    system("cls");
    
    archivo.open("DatosBinario.dat", ios::binary|ios::in);
    if (!archivo)
	{
        cerr << "No se puede abrir el archivo";
        cin.get();
    }
    
    while (archivo.read((char*)(&leerBin), sizeof(datosBin)))
	{
        if (numD < 100)
		{
            datosB[numD] = leerBin;
            numD++;
        }	 
    }

    for (int i=0; i<numD-1; i++)
	{
        for (int j=0; j<numD-i-1; j++)
		{
            if (!compararAlias(datosB[j], datosB[j + 1])) 
			{
                datosBin temp;
                temp = datosB[j];
                datosB[j] = datosB[j + 1];
                datosB[j + 1] = temp;
            }
        }
    }
    
    int pos_y = 4;
    for (int i=0; i<numD; i++)
	{
        textcolor(11);
        gotoxy(2, pos_y);
        cout << "Alias: " << datosB[i].alias;
        pos_y++;
        gotoxy(2, pos_y);
        cout << "Fecha: " << datosB[i].fecha;
        pos_y++;
        gotoxy(2, pos_y);
        cout << "Tiempo: " << datosB[i].tiempo;
        pos_y++;
        gotoxy(2, pos_y);
        cout << "Categora: " << datosB[i].cat;
        pos_y++;
        gotoxy(2, pos_y);
        cout << "Renglon: " << datosB[i].ren;
        pos_y++;
        gotoxy(2, pos_y);
        cout << "Columna: " << datosB[i].col;
		pos_y++;
		gotoxy(2,pos_y);
	    cout << endl; 
	    pos_y++;	
    }
    
    archivo.close();
    getch();
}



#endif
