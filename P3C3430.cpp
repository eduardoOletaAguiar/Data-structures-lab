#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<malloc.h>

struct libro{
	char nom[15];
	char aut[15];
	int npag;
	struct libro *sig;
};

typedef struct libro pila;
typedef pila *NODOPTR;

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
    *(pnom+x)='\0';
}


main(){
	int opc=0;
	NODOPTR nuevo=NULL;
	NODOPTR inicio=NULL;
	NODOPTR actual=NULL;
	NODOPTR ant=NULL;
	NODOPTR iniciopa=NULL;
	NODOPTR actualpa=NULL;
	
	do{
		system("cls");
		printf("Que quieres hacer?\n(1)Agregar\n(2)Eliminar\n(3)Consultar\n(4)Modificar\n(5)Salir\nOpcion: ");
		scanf("%i", &opc);
		switch(opc){
			case 1:
				system("cls");
				nuevo=(pila *)malloc(sizeof(pila));
				printf("Nombre del libro: ");
				valitext(10, nuevo->nom);
				printf("\nNombre del autor: ");
				valitext(10, nuevo->aut);
				printf("\nNumero de paginas: ");
				nuevo->npag=valinum(4);
				nuevo->sig=NULL;
				if(inicio==NULL){
					inicio=nuevo;
				} else{
					nuevo->sig = inicio;
					inicio=nuevo;
				}
				break;
			case 2:
				char nom2[15];
				int yesno;
				system("cls");
				
				printf("Actual\t\t   Nombre\tAutor\tnum de paginas\tSiguiente");
				while(actual!=NULL){
					printf("\n%p\t%s\t%s\t%i\t%p", actual, actual->nom, actual->aut, actual->npag, actual->sig);
					actual=actual->sig;
				}
				printf("\nCual quieres eliminar?");
				valitext(10, nom2);
		
				actual=inicio;
				while(actual!=NULL){
						if (strcmp(actual->nom,nom2)==0){
							break;
						}
						if (actual==NULL){
							iniciopa=inicio;
							actual=actual->sig;
							inicio=actual;
							iniciopa->sig=NULL;
						} else{
							actualpa=actual;
							actual=actual->sig;
							inicio =actual;
							actualpa->sig=iniciopa;
							iniciopa=actualpa;
						}
						
				}
				
				if (strcmp(actual->nom,nom2)==0){
					system("cls");
					printf("\nActual:%p\tNombre:%s\tAutor:%s\tNumero de paginas%i\tSiguiente:%p\n", actual, actual->nom, actual->aut, actual->npag, actual->sig);
					printf("\n\nSeguro que quieres eliminarlo? (1=si)\n");
					yesno = valinum(1);
					if(yesno==1){
						inicio=inicio->sig;
						actual=inicio;
					}
				} else {
					system("cls");
					printf("No se encontro");
				}
				
				
				while(actualpa!=NULL){
							if (actualpa==NULL){
								inicio=iniciopa;
								actualpa=actualpa->sig;
								iniciopa=actualpa;
								inicio->sig=NULL;
							} else{
								actual=actualpa;
								actualpa=actualpa->sig;
								iniciopa =actualpa;
								actual->sig=inicio;
								inicio=actual;
							}
							
				}
				getch();
				break;
			case 3:
				if (inicio!=NULL){
					system("cls");
					
					actual=inicio;
					while(actual!=NULL){
						printf("\nActual:%p\tNombre:%s\tAutor:%s\tNumero de paginas%i\tSiguiente:%p\n", actual, actual->nom, actual->aut, actual->npag, actual->sig);
						
						if (actual==NULL){
							iniciopa=inicio;
							actual=actual->sig;
							inicio=actual;
							iniciopa->sig=NULL;
						} else{
							actualpa=actual;
							actual=actual->sig;
							inicio =actual;
							actualpa->sig=iniciopa;
							iniciopa=actualpa;
						}
						
					}

					while(actualpa!=NULL){
						if (actualpa==NULL){
							inicio=iniciopa;
							actualpa=actualpa->sig;
							iniciopa=actualpa;
							inicio->sig=NULL;
						} else{
							actual=actualpa;
							actualpa=actualpa->sig;
							iniciopa =actualpa;
							actual->sig=inicio;
							inicio=actual;
						}
						
					}
				} else printf("No hay una pila aun");
				
				getch();
				break;
			case 4:
				char nom3[15];
				int yesno2;
				system("cls");
				
				printf("Actual\t\t   Nombre\tAutor\tnum de paginas\tSiguiente");
				while(actual!=NULL){
					printf("\n%p\t%s\t%s\t%i\t%p", actual, actual->nom, actual->aut, actual->npag, actual->sig);
					actual=actual->sig;
				}
				printf("\nCual quieres modificar?");
				valitext(10, nom2);
		
				actual=inicio;
				while(actual!=NULL){
						if (strcmp(actual->nom,nom2)==0){
							break;
						}
						if (actual==NULL){
							iniciopa=inicio;
							actual=actual->sig;
							inicio=actual;
							iniciopa->sig=NULL;
						} else{
							actualpa=actual;
							actual=actual->sig;
							inicio =actual;
							actualpa->sig=iniciopa;
							iniciopa=actualpa;
						}
						
				}
				
				if (strcmp(actual->nom,nom2)==0){
					system("cls");
					printf("\nActual:%p\tNombre:%s\tAutor:%s\tNumero de paginas%i\tSiguiente:%p\n", actual, actual->nom, actual->aut, actual->npag, actual->sig);
					printf("\n\nSeguro que quieres modificarlo? (1=si)\n");
					yesno = valinum(1);
					if(yesno==1){
						system("cls");
						printf("Nuevo nombre del libro: ");
						valitext(10, actual->nom);
						printf("\nNuevo nombre del autor: ");
						valitext(10, actual->aut);
						printf("\nNuevo numero de paginas: ");
						actual->npag=valinum(4);
					}
				} else {
					system("cls");
					printf("No se encontro");
				}
				
				
				while(actualpa!=NULL){
							if (actualpa==NULL){
								inicio=iniciopa;
								actualpa=actualpa->sig;
								iniciopa=actualpa;
								inicio->sig=NULL;
							} else{
								actual=actualpa;
								actualpa=actualpa->sig;
								iniciopa =actualpa;
								actual->sig=inicio;
								inicio=actual;
							}
							
						}
				getch();
				break;
			default:
				system("cls");
				printf("No seleccionaste la opcion correcta");
				break;
		}
	} while (opc !=5);
	
	system("cls");
	printf("El programa ha finalizado");
	actual=inicio;
	
	while(actual!=NULL){
		inicio=inicio->sig;
		free(actual);
		actual=inicio;
	}
}
