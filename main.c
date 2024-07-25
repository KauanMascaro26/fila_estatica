#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>

#define MAXTAM 10

struct fila {
    char item[MAXTAM];
    int ini, fim;
};

struct fila elemento; 

void criar() {
    elemento.ini = 0;
    elemento.fim = 0;
}

void inserir() {
    
    if (elemento.fim == MAXTAM) {
        printf("Fila cheia!");
        getch();
    } else {
        printf("Entre com o elemento: ");
        scanf(" %c", &elemento.item[elemento.fim]);
        elemento.fim++;
    }
}

void remover() {
	int i;
    
    if (elemento.ini == elemento.fim) {
        printf("Fila vazia!");
        getch();
    } else {
        printf("Elemento removido: %c\n", elemento.item[elemento.ini]);
        
        for (i = 0; i < elemento.fim - 1; i++) {
            elemento.item[i] = elemento.item[i + 1];
        }
        elemento.fim--;
    }
}

void mostrar() {
	
	int i;
    if (elemento.ini == elemento.fim) {
        printf("Fila vazia!\n");
    } else {
        printf("Elementos na fila:\n");
        for (i = elemento.ini; i < elemento.fim; i++) {
            printf("Elemento %d: %c\n", i + 1, elemento.item[i]);
        }
    }
    getch();
}

int main() {
	setlocale(LC_ALL,"portuguese");
    int op;
    criar();
    do {
        system("CLS"); 
        printf("\nMenu:\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                inserir();
                break;
            case 2:
                remover();
                break;
            case 3:
                mostrar();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                getch();
        }
    } while (op != 4);

    return 0;
}

