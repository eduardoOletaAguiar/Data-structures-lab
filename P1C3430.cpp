#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include <conio.h>
 
struct alumnos{
	int mat;
	char nom[10];
	int edad;
	struct alumnos *sig;
};

typedef struct alumnos nodo;
typedef nodo *NODOPTR;

int valinum(int lon){
	char c;
	char numero[10];
	int x=0;
	x=0;
	do{
		c=getch();
		if(c>=48 && c<=57){
			printf("%c",c);
        	numero[x]=c;
        	x++;
    	}
    	else if(c==8 && x>0){
			x--;
        	printf("\b \b");
       }
	}while(c!=13 && x<lon);
	numero[x]='\0';
	return atoi(numero);
}

void valitext(int lon,char *pnom){
	int c=0, x=0;
    do{
		c=getch();
        if(c>=65 && c<=90 || c>=97 && c<=122 || c==32 || c==164 || c==165){
			printf("%c",c);
            *(pnom+x)=c;
            x++;
        }
        if(c==8 && x>0){
			x--;
		    printf("\b \b");
	        *(pnom+x)=' ';
        }
    }while(c!=13 && x<lon);
}

main(){
	int opc=0;
	NODOPTR nuevo=NULL;
	NODOPTR inicio=NULL;
	NODOPTR actual=NULL;
	do{
		system("cls");
		printf("Menu\nAgregar(1)\nBorrar(2)\nConsultar(3)\nModificar(4)\nSalir(5)\n\nOpcion: ");
		scanf("%i", &opc);
		system("cls");
		switch(opc){
			case 1:
				nuevo=(nodo *)malloc(sizeof(nodo));
				printf("Matricula: ");
				nuevo->mat=valinum(4);
				printf("\nNombre: ");
				valitext(10, nuevo->nom);
				printf("\nEdad: ");
				nuevo->edad=valinum(2);
				nuevo->sig=NULL;
				if(inicio==NULL){
					inicio=nuevo;
				} else{
					actual=inicio;
					while(actual->sig!=NULL){
						actual=actual->sig;
					}
					actual->sig=nuevo;
				}
				break;
			case 2:
				break;
			case 3:
				actual=inicio;
				printf("Actual\t\t   Matricula\tNombre\tEdad\tSiguiente");
				while(actual!=NULL){
					printf("\n%p\t%i\t%s\t%i\t%p", actual, actual->mat, actual->nom, actual->edad, actual->sig);
					actual=actual->sig;
				}
				getch();
				break;
			case 4:
				break;
			default:
				printf("Opcion incorrecta");
				break;
		}
	} while(opc!=5);
	printf("El programa ha finalizado");
	actual=inicio;
	while(actual!=NULL){
		inicio=inicio->sig;
		free(actual);
		actual=inicio;
	}
}
