#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct node{
	int data;
	node *left = NULL;
	node *right = NULL;
};

void insert(struct node *novo, struct node *first){
	if(first==NULL){
		first = novo;
	}else if(novo->data<first->data){
		insert(novo,first->left);
	}else{
		insert(novo,first->right);
	}
}

node* search(int data, struct node *first){
	if((first->data==data)||(first==NULL)){
		return first;
	}else if(first->data>data){
		return search(data,first->left);
	}else{
		return search(data,first->right);
	}
}

void printTree(struct node *first){
	if(first!=NULL){
		printTree(first->right);
		printf("%d \n", first->data);
		printTree(first->left);
	}
}


int main(){
	int n = 100;
	struct node first, cad[n];
	first.data = 0;
	srand(time(NULL));
	for(int i = 0; i<n; i++){
		cad[i].data = rand()%n + 1;
	}
	for(int i = 0; i<n; i++){
		insert(&cad[i], &first);
	}
	printTree(&first);
	return 0;
}
