//Jonatan Sánchez Ibarra
//20310417
//2°G2

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std;

void insercion (int numeros[]);
void seleccion (int numeros[]);
void burbuja (int numeros[]);
void peine (int numeros[]);
void bidireccional (int numeros[]);
void shell (int numeros[]);
//void shell_insercion (int t, int gap, int inicio);
void gnome (int numeros[]);
void rapido (int numeros[]);
void mezcla (int numeros[]);

int main()
{
	int i,s;
	int numeros[10];
	
	cout << "Bienvenido" << endl;
	cout << "A continuacion ingrese 10 numeros para ordenar" << endl;
	for (i=0; i<10; i++)
	{
		fflush(stdin);
		cout <<"Ingrese el valor #" << i+1 << " a ordenar: ";
		cin >> numeros[i];
	}
	system("PAUSE");
	
	do
	{
		system("CLS");
		cout << "Los valores a ordenar son:" << endl;
		for (i=0; i<10; i++)
	    {
	    cout << "" << numeros[i];
	    cout <<" ";
		}
		cout << endl;
		
		cout << endl << "Seleccione una opcion de Ordenamiento:" << endl;
		cout << "1.Ordenamiento por insercion" << endl;
		cout << "2.Ordenamiento por seleccion" << endl;
		cout << "3.Ordenamiento de burbuja" << endl;
		cout << "4.Ordenamiento peine" << endl;
		cout << "5.Ordenamiento de burbuja bidireccional" << endl;
		cout << "6.Ordenamiento Shell" << endl;
		cout << "7.Ordenamiento Gnome" << endl;
		cout << "8.Ordenamiento rapido" << endl;
		cout << "9.Ordenamiento por mezcla" << endl;
		cout << "0.Salir" << endl;
		cin >> s;
		switch (s)
		{
			case 1:
				{
					insercion(numeros);
					system("PAUSE");
					break;
				}
			case 2:
				{
					seleccion(numeros);
					system("PAUSE");
					break;
				}
			case 3:
				{
					burbuja(numeros);
					system("PAUSE");
					break;
				}
			case 4:
				{
					peine(numeros);
					system("PAUSE");
					break;
				}
			case 5:
				{
					bidireccional(numeros);
					system("PAUSE");
					break;
				}
			case 6:
				{
					shell(numeros);
					system("PAUSE");
					break;
				}
			case 7:
				{
					system("PAUSE");
					break;
				}
			case 8:
				{
					system("PAUSE");
					break;
				}
			case 9:
				{
					system("PAUSE");
					break;
				}
			case 0:
				{	
				cout << "Adios" << endl;
				system("PAUSE");
				break;
				}
			default:
				{
				cout << "Seleccione una opcion valida" << endl;
				system("PAUSE");
				break;
				}
		}
	} while (s!=0);
	return 0;
}


void insercion(int numeros[])
{
	int i, j;
	int actual;
	int temporal[10];
    
    for (i = 0; i < 10; i++)
    {
    	temporal[i] = numeros[i];
	}
    
	cout << "Tus numeros ordenados son:" << endl;
    for (i = 0; i < 10; i++) 
	{
        actual = temporal[i];
        for (j = i; j > 0 && temporal[j - 1] > actual; j--) 
		{
            temporal[j] = temporal[j - 1];
        }
        temporal[j] = actual;
    }
    for (i=0; i<10; i++)
    {
    cout << "" << temporal[i];
    cout <<" ";
	}
	cout << endl;
}

void seleccion (int numeros[])
{
	int i, j;
	int actual, mas_pequeno, temp;
	int temporal[10];
	int tamano = 10;
    
    for (i = 0; i < 10; i++)
    {
    	temporal[i] = numeros[i];
	}
 
    for (actual = 0; actual < tamano - 1; actual++)
    {
        mas_pequeno = actual;
        for (j = actual; j < tamano; j++)
        {
        	if (temporal[j] < temporal[mas_pequeno])
        	{
        		mas_pequeno = j;
			}
    	}
        temp = temporal[actual];
        temporal[actual] = temporal[mas_pequeno];
        temporal[mas_pequeno] = temp;
    }
    cout << "Tus numeros ordenados son:" << endl;
    for (i=0; i<10; i++)
    {
    cout << "" << temporal[i];
    cout <<" ";
	}
	cout << endl;
}

void burbuja (int numeros[])
{
	int iteracion = 0;
    bool permutation = true;
    int actual;
    int i;
	int temporal[10];
    
    for (i = 0; i < 10; i++)
    {
    	temporal[i] = numeros[i];
	}
	
	while (permutation) {
        permutation = false;
        iteracion++;
        for (actual=0; actual<10-iteracion; actual++) {
            if (temporal[actual]>temporal[actual+1]){
                permutation = true;
                // Intercambiamos los dos elementos
                int temp = temporal[actual];
                temporal[actual] = temporal[actual+1];
                temporal[actual+1] = temp;
            }
        }
    }
    cout << "Tus numeros ordenados son:" << endl;
    for (i=0; i<10; i++)
    {
    cout << "" << temporal[i];
    cout <<" ";
	}
	cout << endl;
}

void peine (int numeros[])
{
	int gap = 10;
    bool permutacion = true;
    int actual;
    int i;
	int temporal[10];
	
	for (i = 0; i < 10; i++)
    {
    	temporal[i] = numeros[i];
	}
	
	while (( permutacion) || (gap>1)) {
        permutacion = false;
        gap = gap / 1.3;
        if (gap<1) gap=1;
        for (actual=0;actual<10-gap;actual++) {
            if (temporal[actual]>temporal[actual+gap]){
                permutacion = true;
                // Intercambiamos los dos elementos
                int temp = temporal[actual];
                temporal[actual] = temporal[actual+gap];
                temporal[actual+gap] = temp;
            }
        }
    }
	
	cout << "Tus numeros ordenados son:" << endl;
    for (i=0; i<10; i++)
    {
    cout << "" << temporal[i];
    cout <<" ";
	}
	cout << endl;
}

void bidireccional (int numeros[])
{
	bool permutation;
    int actual=0, direccion=1;
    int comienzo=1, fin=9;
    int i;
	int temporal[10];
    
    for (i = 0; i < 10; i++)
    {
    	temporal[i] = numeros[i];
	}
	
	do {
        permutation=false;
        while (((direccion==1) && (actual<fin)) || ((direccion==-1) && (actual>comienzo))) {
            actual += direccion;
            if (temporal[actual]<temporal[actual-1]) {
                int temp = temporal[actual];
                temporal[actual]=temporal[actual-1];
                temporal[actual-1]=temp;
                permutation=true;
            }
        }
        if (direccion==1) fin--; else comienzo++;
        direccion = -direccion;
    } while (permutation);
	
	cout << "Tus numeros ordenados son:" << endl;
    for (i=0; i<10; i++)
    {
    cout << "" << temporal[i];
    cout <<" ";
	}
	cout << endl;
}

void shell (int numeros[])
{
	int i,inc,aux;
	int temporal[10];
	bool band;
	inc=10;
	for (i = 0; i < 10; i++)
    {
    	temporal[i] = numeros[i];
	}
	
	while (inc>1)
	{
		inc=(inc/2);
		band=true;
		while (band==true)
		{
			band=false;
			i=0;
			while(i+inc<=10)
			{
				if(temporal[i]>temporal[i+inc])
				{
					aux=temporal[i];
					temporal[i]=temporal[i+inc];
					temporal[i+inc]=aux;
					band=true;
				}
				i++;
			}
		}
	}
	cout << "Tus numeros ordenados son:" << endl;
    for (i=0; i<10; i++)
    {
    cout << "" << temporal[i];
    cout <<" ";
	}
	cout << endl;
}
¿
//	int intervalos[5]={6,4,3,2,1};
//	int ngap;
//	int i;
//	int temporal[10];
//    
//    for (i = 0; i < 10; i++)
//    {
//    	temporal[i] = numeros[i];
//	}
//	
//	for (ngap=0; ngap<5; ngap++) {
//        for (i=0; i<intervalos[ngap]; i++)
//            temporal = shell_insercion(temporal, intervalos[ngap], i);
//    }
//	
//	cout << "Tus numeros ordenados son:" << endl;
//    for (i=0; i<10; i++)
//    {
//    cout << "" << temporal[i];
//    cout <<" ";
//	}
//	cout << endl;
//}

//int shell_insercion (int t, int gap, int inicio)
//{
//	int i, j, clase;
//    for (i = gap + inicio; i < 10; i+=gap) {
//        clase = t[i];
//        for (j = i; j >= gap && t[j - gap] > clase; j-=gap) {
//            t[j] = t[j - gap];
//        }
//        t[j] = clase;
//    }
//    return t;
//}

void gnome (int numeros[])
{
	int i;
	int temporal[10];
    
    for (i = 0; i < 10; i++)
    {
    	temporal[i] = numeros[i];
	}
	
	cout << "Tus numeros ordenados son:" << endl;
    for (i=0; i<10; i++)
    {
    cout << "" << temporal[i];
    cout <<" ";
	}
	cout << endl;
}

void rapido (int numeros[])
{
	int i;
	int temporal[10];
    
    for (i = 0; i < 10; i++)
    {
    	temporal[i] = numeros[i];
	}
	
	cout << "Tus numeros ordenados son:" << endl;
    for (i=0; i<10; i++)
    {
    cout << "" << temporal[i];
    cout <<" ";
	}
	cout << endl;
}

void mezcla (int numeros[])
{
	int i;
	int temporal[10];
    
    for (i = 0; i < 10; i++)
    {
    	temporal[i] = numeros[i];
	}
	
	cout << "Tus numeros ordenados son:" << endl;
    for (i=0; i<10; i++)
    {
    cout << "" << temporal[i];
    cout <<" ";
	}
	cout << endl;
}

