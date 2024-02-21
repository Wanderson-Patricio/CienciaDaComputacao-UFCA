#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

/******************************************Wanderson Faustino Patricio************************************************************/
/******************************************Ciência da Computação******************************************************************/
/******************************************UFCA - 2022.2**************************************************************************/

int sizeOfLista(struct node** head){
    int length = 0;
    struct node* current = *head;
    while(current != NULL){
        length++;
        current = current->next;
    }

    return length;
}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

int isFull(struct node** head){
    if(sizeOfLista(head) == MAX_SIZE){
        return 1;
    }
    return 0;
}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

//Diz se a lista está vazia
int isEmpty(struct node** head){
    if(sizeOfLista(head) == 0){
        return 1;
    }
    return 0;
}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

void inserir(struct node** head, char *nome ,int data) {

    if(isFull(head) == 1){

        printf("A lista está cheia. \n");

    }else{

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        strcpy(newNode->nome, nome);
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;


        if (*head == NULL) {
            *head = newNode;
            return;
        }


        if (data < (*head)->data) {
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
            return;
        }


        struct node* current = *head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }


        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;

    }
}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/


void removeNode(struct node** head, struct node* node) {
    if (*head == NULL || node == NULL) {
        printf("A lista está vazia. \n");
        return;
    }


    if(searchNode(*head, node->nome) == NULL){

        printf("O aluno não está na lista. \n");

    }else{

        if (*head == node) {
            *head = node->next;
        }


        if (node->prev != NULL) {
            node->prev->next = node->next;
        }
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }

        free(node);

    }
}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

void clearList(struct node** head) {
    struct node* current = *head;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

struct node* searchNode(struct node* head, char *nome) {
    struct node* current = head;
    while (current != NULL) {
        if (strcmp(nome, current->nome) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

void displayList(struct node* head, char *operacao) {
    if(isEmpty(&head) == 1){

        printf("A lista está vazia. \n");

    }else{

        struct node* current = head;
        printf("Em ordem crescente de %s temos: \n", operacao);
        while (current != NULL) {
            printf("Nome: %s \n", current->nome);
            printf("%s: %d \n\n", operacao,current->data);
            current = current->next;
        }

    }
}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

displayData(struct node* head, char* operacao){
    printf("%s: %d \n", operacao, head->data);
}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

void displayNode(struct node* head, char* operacao){
    printf("Nome: %s \n", head->nome);
    printf("%s: %d \n", operacao, head->data);
    printf("\n");
}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

void displayLastNode(struct node* head, char* operacao){
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    displayNode(current, operacao);
}

/*********************************************************************************************************************************/
/*********************************************************************************************************************************/

void inicializar(){
    char aux[50];
    int data;

    struct node* headMedia = NULL;
    struct node* headMatricula = NULL;
    struct node* headSemestre = NULL;

    // Inserindo As médias dos Alunos
    inserir(&headMedia, "Curie", 9);
    inserir(&headMedia, "Laplace", 10);
    inserir(&headMedia, "Lovelace", 8);
    inserir(&headMedia, "Feynman", 7);
    inserir(&headMedia, "Einstein", 6);
    inserir(&headMedia, "Gauss", 5);
    inserir(&headMedia, "Stokes", 4);
    inserir(&headMedia, "Schrodinger", 3);
    inserir(&headMedia, "Riemann", 2);
    inserir(&headMedia, "Hawkins", 1);
    inserir(&headMedia, "Newton", 10);
    inserir(&headMedia, "Darwin", 7);
    inserir(&headMedia, "Tesla", 9);
    inserir(&headMedia, "Galileo", 5);
    inserir(&headMedia, "Edison", 5);
    inserir(&headMedia, "Maxwell", 8);
    inserir(&headMedia, "Hubble", 3);
    inserir(&headMedia, "Turing", 10);
    inserir(&headMedia, "Planck", 8);
    inserir(&headMedia, "Mendel", 0);



    // Inserindo a matrícula dos alunos
    inserir(&headMatricula, "Curie", 2002005006);
    inserir(&headMatricula, "Laplace", 2002005005);
    inserir(&headMatricula, "Lovelace", 2002005008);
    inserir(&headMatricula, "Feynman", 2002005007);
    inserir(&headMatricula, "Einstein", 2002005001);
    inserir(&headMatricula, "Gauss", 2002005003);
    inserir(&headMatricula, "Stokes", 2002005002);
    inserir(&headMatricula, "Schrodinger", 2002005004);
    inserir(&headMatricula, "Riemann", 2002005010);
    inserir(&headMatricula, "Hawkins", 2002005009);
    inserir(&headMatricula, "Newton", 2002005012);
    inserir(&headMatricula, "Darwin", 2002005015);
    inserir(&headMatricula, "Tesla", 2002005020);
    inserir(&headMatricula, "Galileo", 2002005019);
    inserir(&headMatricula, "Edison", 2002005013);
    inserir(&headMatricula, "Maxwell", 2002005014);
    inserir(&headMatricula, "Hubble", 2002005017);
    inserir(&headMatricula, "Turing", 2002005011);
    inserir(&headMatricula, "Planck", 2002005018);
    inserir(&headMatricula, "Mendel", 2002005016);

    // Inserindo o semestre dos alunos
    inserir(&headSemestre, "Curie", 1);
    inserir(&headSemestre, "Laplace", 3);
    inserir(&headSemestre, "Lovelace", 3);
    inserir(&headSemestre, "Feynman", 8);
    inserir(&headSemestre, "Einstein", 2);
    inserir(&headSemestre, "Gauss", 5);
    inserir(&headSemestre, "Stokes", 6);
    inserir(&headSemestre, "Schrodinger", 4);
    inserir(&headSemestre, "Riemann", 8);
    inserir(&headSemestre, "Hawkins", 7);
    inserir(&headSemestre, "Newton", 2);
    inserir(&headSemestre, "Darwin", 8);
    inserir(&headSemestre, "Tesla", 4);
    inserir(&headSemestre, "Galileo", 3);
    inserir(&headSemestre, "Edison", 5);
    inserir(&headSemestre, "Maxwell", 6);
    inserir(&headSemestre, "Hubble", 8);
    inserir(&headSemestre, "Turing", 1);
    inserir(&headSemestre, "Planck", 2);
    inserir(&headSemestre, "Mendel", 1);


    int option;
    do{
        printf("************************************************\n");
        printf("O que quer fazer? \n\n");
        printf("1  - Ver os alunos em ordem crescente de média. \n");
        printf("2  - Ver os alunos em ordem crescente de matrícula. \n");
        printf("3  - Ver os alunos em ordem crescente de semestre. \n");
        printf("4  - Ver o aluno com a maior média. \n");
        printf("5  - Ver o aluno com a maior matrícula. \n");
        printf("6  - Ver o aluno com a menor média. \n");
        printf("7  - Ver o aluno com a menor matrícula. \n");
        printf("8  - Ver os dados de um aluno. \n");
        printf("9  - Adicionar um aluno. \n");
        printf("10 - Remover um aluno.\n");
        printf("11 - Sair. \n");

        scanf("%d", &option);
        system("cls");


        switch(option){
            case 1:  displayList(headMedia, "media");break;
            case 2:  displayList(headMatricula, "matricula");break;
            case 3:  displayList(headSemestre, "semestre");break;
            case 4:{
                displayLastNode(headMedia, "media");
                break;
            }
            case 5:{
                displayLastNode(headMatricula, "media");
                break;
            }
            case 6:{
                displayNode(headMedia, "media");
                break;
            }
            case 7:{
                displayNode(headMatricula, "media");
                break;
            }
            case 8:{
                printf("Quem você deseja pesquisar? \n");
                scanf("%s", aux);

                struct node* tempMedia = searchNode(headMedia, aux);
                struct node* tempMatricula = searchNode(headMatricula, aux);
                struct node* tempSemestre = searchNode(headSemestre, aux);

                if(tempMedia != NULL){

                    printf("Nome: %s \n", aux);
                    displayData(tempMedia, "media");
                    displayData(tempMatricula, "matricula");
                    displayData(tempSemestre, "semestre");

                }else{

                    printf("Esse aluno não está na lista.\n");

                }

                free(tempMedia);
                free(tempMatricula);
                free(tempSemestre);
                break;
            };

            case 9:{
                printf("Qual o sobrenome do aluno a ser adicionado? \n");
                scanf("%s", aux);

                printf("Qual a média de %s ?\n", aux);
                scanf("%d", &data);
                inserir(&headMedia, aux, data);

                printf("Qual a matricula de %s ?\n", aux);
                scanf("%d", &data);
                inserir(&headMatricula, aux, data);

                printf("Qual o semestre de %s ?\n", aux);
                scanf("%d", &data);
                inserir(&headSemestre, aux, data);
                break;
            }

            case 10:{

                printf("Qual o sobrenome do aluno a ser removido? \n");
                scanf("%s", aux);


                if(searchNode(headMedia, aux)){

                    removeNode(&headMedia, searchNode(headMedia, aux));
                    removeNode(&headMatricula, searchNode(headMatricula, aux));
                    removeNode(&headSemestre, searchNode(headSemestre, aux));

                }else{

                    printf("Esse aluno não está na lista.\n");


                }


                break;

            }

            case 11:  printf("Obrigado por usar o nosso programa. :):)\n");break;
        }

        system("pause");
        system("cls");
    }while(option != 11);

    clearList(&headMedia);
    clearList(&headMatricula);
    clearList(&headSemestre);

}
