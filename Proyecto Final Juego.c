//Proyecto Final Juego
//Jonatan Sánchez Ibarra
//20310417
//1°G2

//Bibliotecas
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

//Declaraciones
int aleatorio ();
void menu ();
void victorias(char name[],char name1[],int v,int v1);


//Arreglo de Registro Personaje
typedef struct		// Declaración estructura de registro
{
	char nombre[50];
	int defensa;
	int ataque;
	int inteligencia;
} personaje;		// Nombre del registro
personaje j[3], j2[3];
personaje p[20]={"Astronauta",15,9,5,"Carnicero",6,17,1,"Arquitecto",8,12,4,"Biologo",9,10,3,"Panadero",9,11,1,"Carpintero",5,15,2,"Doctor",10,13,5,"Ingeniero",8,16,5,"Policia",10,18,1,"Bombero",15,7,2,"Chef",5,13,3,"Bailarin",9,10,2,"Granjero",7,12,1,"Electricista",13,8,4,"Mecanico",8,14,4,"Minero",5,16,2,"Pintor",10,9,3,"Fotografo",9,9,3,"Profesor",10,10,5,"Deportista",11,12,2,};


//Main
int main ()
{	int v=0,v1=0,n;
	int i,a,b,b1,d,in,a1,d1,in1;
	char nom[40]={"Hola "},name[40]={},name1[40]={},nom1[40]={"Hola "};
	
	srand(time(NULL));
	system("color 70");
	
	menu();
	printf ("\t**Bienvenido a Guerra de Profesiones**\n\tPor: Jonatan Sanchez Ibarra \n\n");
	
	//Inicio Jugador 1
	printf("Ingrese el nombre del jugador 1: ");
	gets(name);
	strcat (nom, name);
	printf("Ingrese el nombre del jugador 2: ");
	gets(name1);
	strcat (nom1, name1);
	system("cls");
	for(n=0; n<3; n++)
	{
	printf("%s! \nEstamos generando tus profesionistas!\n\n",nom);

	//Selección de los personajes del jugador 1
	for (i=0; i<3; i++)
	{
	j[i]=p[aleatorio()];
	printf("El profesionista #%i de %s es:\n%s ",i+1,name,j[i].nombre);
	printf("\nAtaque: %i",j[i].ataque);
	printf("\nDefensa: %i",j[i].defensa);
	printf("\nInteligencia: %i\n\n",j[i].inteligencia);
	sleep(1);
	}
	
	//Suma de atributos del Jugador 1
	a=j[0].ataque+j[1].ataque+j[2].ataque;
	printf("El ataque de %s es: %i\n",name,a);
	d=j[0].defensa+j[1].defensa+j[2].defensa;
	printf("La defensa de %s es: %i\n",name,d);
	in=j[0].inteligencia+j[1].inteligencia+j[2].inteligencia;
	printf("La inteligencia de %s es: %i\n\n",name,in);
	
	//Suma de Inteligencias del jugador 1
	if(in>=10)
	{	
		printf("Tienes una inteligencia igual o mayor a 10, ganas 5 puntos de ataque\n");
		a=a+5;
		printf("Tu nuevo ataque es de: %i\n",a);
	}
	
	system("\nPAUSE");
	system("cls");
	
	//Inicio Jugador 2
	printf("%s! \nEstamos generando tus profesionistas!\n\n",nom1);

	//Selección de los personajes del jugador 2
	for (i=0; i<3; i++)
	{j2[i]=p[aleatorio()];
	printf("\nEl profesionista #%i de %s es: \n%s ",i+1,name1,j2[i].nombre);
	printf("\nAtaque: %i",j2[i].ataque);
	printf("\nDefensa: %i",j2[i].defensa);
	printf("\nInteligencia: %i\n\n",j2[i].inteligencia);
	}
	
	//Suma de atributos del Jugador 2
	a1=j2[0].ataque+j2[1].ataque+j2[2].ataque;
	printf("El ataque de %s es: %i\n",name1,a1);
	d1=j2[0].defensa+j2[1].defensa+j2[2].defensa;
	printf("La defensa de %s es: %i\n",name1,d1);
	in1=j2[0].inteligencia+j2[1].inteligencia+j2[2].inteligencia;
	printf("La inteligencia de %s es: %i\n\n",name1,in1);
	
	//Suma de inteligencias de Jugador 2
	if(in1>=10)
	{	
		printf("Tienes una inteligencia mayor a 10, ganas 5 puntos de ataque\n");
		a1=a1+5;
		printf("Tu nuevo ataque es de: %i\n",a1);
	}
	
	system("\nPAUSE");
	system("cls");
	
	//Combates
	printf("Combate #%i\n",n+1);
	printf("%s vs %s\n",name,name1);
		b=d1-a;
		b1=d-a1;
		printf("Ataque de %s: %i\n",name,a);
		printf("Defensa de %s: %i\n",name1,d1);
		printf("Vida de %s = %i\n",name1,b);
		
		printf("\nAtaque de %s: %i\n",name1,a1);
		printf("Defensa de %s: %i\n",name,d);
		printf("Vida de %s = %i\n",name,b1);
		system("PAUSE");
		
		//Determinación de Victoria
		if (b1>b)
		{
		printf("\nGana %s \n",name);
		v++;
		}
		if (b1<b)
		{
		printf("\nGana %s \n",name1);
		v1++;
		}
		if(b1==b)
		{
		printf("\nEs un empate\n");
		n--;
		}
		victorias(name,name1,v,v1);
		system("PAUSE");
		system("cls");
	}
	if(v>=2) printf("%s es el campeon de Guerra de Profesionistas!!!\n",name);
	if(v1>=2) printf("%s es el campeon de Guerra de Profesionistas!!!\n",name1);
	system("PAUSE");
	
	
	return 0;
}
	

	


//Funciones

void menu ()
{	
	int s;
	printf ("\t**Bienvenido a Guerra de Profesiones**\n\tPor: Jonatan Sanchez Ibarra \n\n");
	printf("\nPresione '1' para jugar o presione '2' para leer las instrucciones y normas. \n");
	scanf("%i",&s);
	system("cls");
	do
	{
		switch (s)
		{
			case 1:
			break;
			
			case 2:
			printf("Normas: \n\n");
			printf("Cada jugador recibe 3 profesionistas con diferentes estadisticas cada ronda.\n\nSe sumara el ataque , la defensa y la inteligencia de los 3, ");
			printf("Si la inteligencia de los 3 sumada da como resultado 10 \no mas, se agregaran 5 puntos extra al ataque del equipo.\n\n");
			printf("Cada ronda peleara cada equipo segun su ataque y defensa.\n\nLa forma de calcular el resultado es restando a la defensa el ataque,");
			printf("de esta manera, el jugador que quede con el \nmenor numero de defensa, perdera la ronda.\n\n");
			printf("Se juega al mejor de 3. El primer jugador en ganar 2 rondas, sera el campeon de 'Guerra de Profesionistas'!!!\n\n");
			system("PAUSE");
			system("cls");
			printf("Presione 1 para jugar o Presione 2 para leer las instrucciones y normas \n");
			scanf("%i",&s);
			break;
			
			default:
				printf("\nPresione 1 para jugar o Presione 2 para leer las instrucciones y normas \n");
				scanf("%i",&s);
				break;
		}
	}
	while(s!=1);
	system("cls");
	fflush(stdin);
}


int aleatorio ()
{	
	sleep(2);
	return rand()%20;	// Genera un valor aleatorio entre 0 y 20
	sleep(2);
}

void victorias(char name[],char name1[],int v,int v1) //Contador de Victorias
{
	printf("%s lleva %i victorias\n",name,v);
	printf("%s lleva %i victorias\n",name1,v1);
}



