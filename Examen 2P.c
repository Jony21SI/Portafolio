// Examen
//Jonatan Sánchez Ibarra
//20310417
//1°G2

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

int main ()
{ 
int cod,cont,s;
float mg,precio;
	system("color 7c");

	printf("Bienvenido, Ingrese el codigo del medicamento ");
	scanf("%i",&cod);
	printf("\nIngrese los miligramos del medicamento ");	
	scanf("%f",&mg);
	printf("\nIngrese el contenido del envase o de la caja ");	
	scanf("%i",&cont);
	printf("\nIngrese el precio del medicamento ");
	scanf("%f",&precio);
do{
	printf("\nSeleccione lo que desea conocer sobre el producto: ");
	printf("\n \t 1.Ver Codigo del medicamento");
	printf("\n \t 2.Ver miligramos del medicamento");
	printf("\n \t 3.Ver Contenido del envase o de la caja");
	printf("\n \t 4.Ver el precio del medicamento");
	printf("\n \t 5.Salir ");
	scanf("%i",&s);
	
	switch (s)
	{	case 1:
		printf("\n  El codigo de su medicamento es: %i ",cod);
		break;
		case 2:
		printf("\n  Los miligramos de su medicamento son: %.2f ",mg);
		break;
		case 3:
		printf("\n  El contenido del envase o de la caja es de: %i ",cont);
		break;
		case 4:
		printf("\n  El precio de su medicamento es: %.2f ",precio);
		break;
		default:
		printf("\n  Seleccione una opcion valida");
		break;
	}
 }
while (s!=5);
printf ("\n \n");
	system("PAUSE");
    return 0;
}
