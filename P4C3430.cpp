#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>

struct Arbol{
	int valor;
	struct Arbol *Izq;
	struct Arbol *Der;
};

void Insertar (struct Arbol **Raiz, int n);

struct Arbol *buscar(struct Arbol*,int n);
void mostrar (struct Arbol *Raiz, int n);
void inorden(struct Arbol *Raiz);
void postorden(struct Arbol *Raiz);
void preorden(struct Arbol *Raiz);
void liberar(struct Arbol *Raiz);

main(){
	int op, num;
	struct Arbol *Raiz=NULL;
	do{
		system("cls");
		printf("1. Insertar\n");
		printf("2. Borrar\n");
		printf("3. Buscar\n");
		printf("4. Mostrar\n");
		printf("5. Inorden\n");
		printf("6. Postorden\n");
		printf("7. Preorden\n");
		printf("8. Salir\n");
		printf("Selecciona la opcion: ");
		scanf("%i",&op);
		switch(op){
			case 1:
				system("cls");
				printf("\nCaptura el numero: ");
				scanf("%i", &num);
				Insertar(&Raiz,num);
				break;
			case 2:
				break;
			case 3:
				system("cls");
				int n;
				printf("\nQue numero quieres saber si existe?: ");
				scanf("%i", &n);
				if (buscar(Raiz , n)==NULL){
					printf("El numero NO existe en la raiz");
				} else {
					printf("El numero SI existe en la raiz");
				}
				getch();
				break;
			case 4:
				printf("Los nodos del arbol son...\n");
				mostrar(Raiz,0);
				getch();
				break;
			case 5:
				system("cls");
                inorden(Raiz);
                getch();
                break;
			case 6:
				system("cls");
                postorden(Raiz);
                getch();
				break;
			case 7:
				system("cls");
                preorden(Raiz);
                getch();
				break;
			default:
				system("cls");
				printf("Oye esa opcion es invalida");
				getch();
				break;
		}
	}while(op!=8);
	system("cls");
	printf("El programa ha finalizado");
	liberar(Raiz);
	
}

void liberar(struct Arbol *Raiz) {
    if(Raiz != NULL) {
        liberar(Raiz->Izq);
        liberar(Raiz->Der);
        free(Raiz);
    }
}

void Insertar (struct Arbol **Raiz, int n){
	if(*Raiz==NULL){
		*Raiz=(struct Arbol *)malloc(sizeof(struct Arbol));
		(*Raiz)->valor=n;
		(*Raiz)->Izq=NULL;
		(*Raiz)->Der=NULL;
	} else if (n<(*Raiz)->valor)
		Insertar(&(*Raiz)->Izq,n);
	else if (n>(*Raiz)->valor)
		Insertar(&(*Raiz)->Der,n);
	else{
		printf("Numero duplicado");
		getch();
	}
}

void mostrar (struct Arbol *Raiz, int n){
	int i;
	if(Raiz!=NULL){
		mostrar(Raiz->Der, n+1);
		for(i=0;i<n;i++){
			printf("   ");
		}
		printf("%i\n" , Raiz -> valor);
		mostrar(Raiz->Izq, n+1);
	}
}

struct Arbol *buscar(struct Arbol *Raiz,int n){
	if(Raiz==NULL){
		return NULL;
	}
	else if(n>Raiz->valor){
		return buscar(Raiz->Der,n);
	}
	else if(n<Raiz->valor){
		return buscar(Raiz->Izq,n);
	}
	else
		return Raiz;
}


void inorden(struct Arbol *Raiz) {
    if(Raiz != NULL) {
        inorden(Raiz->Izq);
        printf("%d ", Raiz->valor);
        inorden(Raiz->Der);
    }
}

void postorden(struct Arbol *Raiz) {
    if(Raiz != NULL) {
        postorden(Raiz->Izq);
        postorden(Raiz->Der);
        printf("%d ", Raiz->valor);
    }
}

void preorden(struct Arbol *Raiz) {
    if(Raiz != NULL) {
    	printf("%d ", Raiz->valor);
        preorden(Raiz->Izq);
        preorden(Raiz->Der);
    }
}

