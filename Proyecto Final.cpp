//Jonatan Sánchez Ibarra
//20310417
//2°G2
//Proyecto - Reproductor de Musica "Jonylist"

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <windows.h>
#include <time.h>
#include "clases.h"
#define ASCENDENTE 1

using namespace std;

// Main
int main ()
{	
	system ("COLOR 0F"); //Color
	int in, opc, opc2,o,cant,x,op;
	int sal=0;
	lista Lista;
	cuenta Cuenta;
	char nom[30];
	// Pantalla de Bienvenida
	cout << "\t\t\tBIENVENIDO AL Reproductor de Musica -Jonylist-  " << endl;
	cout << "\t\t\tPor Jonatan Sanchez Ibarra" << endl << endl;
	Sleep(5000);
	system ("CLS");
	//Pantalla Ingresar Nombre
	cout << "Ingrese su nombre: ";
	cin >> nom;
	cout << endl;
	//Menu inicial
	do
	{
		sal=0;
		fflush(stdin);
		cout << "Con que cuenta deseas ingresar " << nom <<"?" << endl;
		cout << "1.Cuenta Premium" << endl;
		cout << "2.Cuenta gratuita" << endl;
		cout << "3.Salir del Reproductor" << endl; //Salir
		cin >> in;
		system ("CLS");
		switch (in)
		{
			case 1:
				Cuenta.Premium(); // Se ingresa la contraseña y se compara
				do
				{
					system ("CLS");
					//Menú Premium
					cout << "********** MENU PREMIUM **********" << endl;
					cout << "1.- Crear playlist" << endl;
					cout << "2.- Agregar canciones al reproductor" << endl;
					cout << "3.- Ver Playlist" << endl;
					cout << "4.- Borrar canciones de tu playlist" << endl;
					cout << "5.- Buscar alguna cancion en tu playlist" << endl;
					cout << "6.- Reproducir playlist" << endl;
					cout << "0.- Cerrar Sesion" << endl;
					cout << "Selecciona una opcion: ";
					cin >> opc;
					cout << endl;
					switch (opc)
					{
						case 1: //Crear Playlist
							Lista.Limpiar();
							//Se muestran las canciones
							cout << "A continuacion se muestran las canciones: "<< endl;
							cout << "Numero de cancion, Nombre de la cancion, Artista, Duracion" << endl;
							Sleep(2000);
							Cuenta.Lectura();
							Sleep(300);
							Cuenta.Lecturabanda();
							Sleep(300);
							Cuenta.Lecturaelectronica();
							Sleep(300);
							Cuenta.Lecturareggaeton();
							Sleep(300);
							Cuenta.Lecturarock();
							Sleep(300);
							//Se ingresan las canciones al playlist
							cout<<"Cuantas canciones deseas ingresar a tu playlist: ";
							cin>>cant;
							for (int i=0; i<cant; i++)
							{ 
								cout<<endl<<"Ingresa el numero de la cancion #"<<i+1<<" para tu playlist: ";
								cin>>x;
								Lista.Insertar(x);
							}
							cout<<"\nTus canciones han sido guardadas en tu Playlist"<<endl;
							Sleep(2000);
							//Reproduccion de canciones
							cout<<"Se reproduciran las siguientes canciones: " << endl;	
							Lista.Mostrar(ASCENDENTE);
							Sleep(3000);
							cout << endl;
							Lista.Reproducir(ASCENDENTE);
							Sleep(1000);
							system ("CLS");
							x=0;			
							break;
						case 2: // Agregar canciones a los archivos de texto
							do
							{
								system("CLS");
								cout << "A que playlist deseas agregar canciones?" << endl;
								cout << "1.Pop" << endl;
								cout << "2.Banda" << endl;
								cout << "3.Rock" << endl;
								cout << "4.Reggaeton" << endl;
								cout << "5.Electronica" << endl;
								cout << "6.Regresar" << endl;
								cout << "Selecciona una opcion: " << endl;
								cin >> op;
								switch (op)
								{
									case 1:
										Cuenta.Escribir();
										system("CLS");
										break;
									case 2:									
										Cuenta.Escribirbanda();
										system("CLS");
										break;
									case 3:
										Cuenta.Escribirrock();
										system("CLS");
										break;
									case 4:
										Cuenta.Escribirreggaeton();
										system("CLS");
										break;
									case 5:
										Cuenta.Escribirreggaeton();
										system("CLS");
										break;
									default:
										break;
								}
							}while (op!=6); //Regresa al menú Premium
							break;
						case 3: //Ver Playlist
							if (Lista.ListaVacia())
							cout<<"Tu lista esta vacia"<<endl;
							else 
							{
								cout<<"Las canciones de tu Playlist son: " << endl;	
								Lista.Mostrar(ASCENDENTE);
							}
							system ("PAUSE");
							break;
						case 4: //Borrar Canciones
							cout <<"Tu lista contiene las siguientes canciones:" << endl;
							Lista.Mostrar(ASCENDENTE);
							cout<<"Ingresa el numero de cancion que quieras eliminar: ";
							cin>>x;
							Lista.Borrar(x);
							x=0;
							break;
						case 5: //Se busca una cancion en el playlist
							if (Lista.ListaVacia())
							{
								cout<<"Tu lista esta vacia"<<endl;
								Sleep(3000);
							}
							else 
							{
								cout<<"Ingresa el numero de cancion que quieras buscar: ";
								cin>>x;
								Lista.Buscar(x);
								Sleep(3500);
							}
							x=0;
							break;
						case 6: //Se reproducen las canciones del Playlist
							system("CLS");
							cout<<"Se reproduciran las siguientes canciones: " << endl;	
							Lista.Mostrar(ASCENDENTE);
							Sleep(3000);
							cout << endl;
							Lista.Reproducir(ASCENDENTE);
							Sleep(1000);
							system ("CLS");
							break;
						case 0: //Cerrar Sesión
							cout << "Regresa pronto!" << endl << endl;
							Sleep(3000);
							break;
						default:
							cout << "Elija una opcion valida" << endl;
							Sleep(3000);
							system ("CLS");
							break;
					}	
					system ("CLS");
				} while (opc!=0);
				sal=1;
			while(sal==0)
			{	
			case 2: //Modo Gratuito
				Lista.Limpiar();
				cout << "A continuacion se muestran las canciones: "<< endl;
				cout << "Numero de cancion, Nombre de la cancion, Artista, Duracion" << endl;
				Sleep (3000);
				Cuenta.Lectura();
				Sleep (400);
				Cuenta.Lecturabanda();
				Sleep (400);
				Cuenta.Lecturaelectronica();
				Sleep (400);
				Cuenta.Lecturareggaeton();
				Sleep (400);
				Cuenta.Lecturarock();
				Sleep (400);
				cout << "Tu playlist contendra 5 canciones" << endl;
				for (int i=0; i<5; i++)
				{ 
					cout<<endl<<"Ingresa el numero de la cancion #"<<i+1<<" para tu playlist: ";
					cin>>x;
					Lista.Insertar(x);
				}
				cout<<"Se reproduciran las siguientes canciones: " << endl;	
				Lista.Mostrar(ASCENDENTE);
				Sleep(3000);
				cout << endl;
				Lista.Reproducir(ASCENDENTE);
				Sleep(1000);
				system ("CLS");
				Cuenta.Registro(); //Se pregunta si se desea hacer Premium
				system ("CLS");
				x=0;			
				break;
			case 3:
				cout << "Hasta la Proxima!" << endl;
				Sleep(3000);
				break;
			default:
				cout << "Elija una opcion valida" << endl;
				Sleep(3000);
				system ("CLS");
				break;
			}
		}
	}while (in!=3); 
	system ("CLS"); 
	
	return 0;
}
