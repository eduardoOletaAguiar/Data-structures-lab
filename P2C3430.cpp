#include<stdio.h>
#include <windows.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>
struct elemento{
	char nom[15];
	int tam;
	struct elemento *sig;
};
typedef struct elemento nodo;
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
		printf("Menu\nAgregar(1)\nImprimir(2)\nCancelar(3)\nPrioridad(4)\nMostrar(5)\nSalir(6)\n\nOpcion: ");
		scanf("%i", &opc);
		system("cls");
		switch(opc){
			case 1:
				nuevo=(nodo *)malloc(sizeof(nodo));
				printf("Nombre del archivo: ");
				valitext(10, nuevo->nom);
				printf("\nTamanio del archivo: ");
				nuevo->tam=valinum(4);
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
				
				NODOPTR ant;
				system("cls");
				int yesno;
				char cancelar[15];
				
				printf("Dame el nombre del archivo a cancelar: ");
				valitext(10, cancelar);
				
				actual=inicio;
				while(actual!=NULL){
					if (strcmp(actual->nom,cancelar)==0){
						break;
					}
					ant=actual;
					actual=actual->sig;
				}
				
				if(actual==NULL){
					printf("\nNo se encontro el archivo");
					getch();
				} else {
					system("cls");
					printf("\nActual:%p\tNombre:%s\tTamanio del archivo%i\tSiguiente:%p", actual, actual->nom, actual->tam, actual->sig);
					printf("\n\nSeguro que quieres eliminarlo? (1=si): ");
					scanf("yesno");
					if(yesno==1){
						if (actual==inicio){
							inicio=inicio->sig;
						}else
							ant->sig=actual->sig;
						free(actual);
					}
				}
				break;
			case 4:
				break;
			case 5:
				actual=inicio;
				printf("Actual\t\t   Nombre\tTamanio\t\tSiguiente");
				while(actual!=NULL){
					printf("\n%p\t%s\t%i\t%p", actual, actual->nom, actual->tam, actual->sig);
					actual=actual->sig;
				}
				getch();
				break;
			default:
				printf("Opcion incorrecta");
				break;
		}
	} while(opc!=6);
	printf("El programa ha finalizado");
	actual=inicio;
	
	while(actual!=NULL){
		inicio=inicio->sig;
		free(actual);
		actual=inicio;
	}
}
