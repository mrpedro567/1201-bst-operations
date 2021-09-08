#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* rChild;
    struct Node* lChild; 
} Node;

int j=0;

void insertNode(struct Node** root, int value){
    struct Node* insert = (struct Node*)calloc(1, sizeof(struct Node));
	
	//Inicializa os valores do novo nó.
    insert->data = value;
    insert->lChild = NULL;
    insert->rChild = NULL;
    
	//Verifica se a arvore está vazia
    if(*root == NULL){
        *root = insert;
    } 
    else{
        struct Node* current = *root;
        struct Node* tmp = *root;
		
        //Percorre a arvore com o tmp, ate achar tmp = NULL
        while(tmp != NULL){
            current = tmp;
            if(current->data > value){
                tmp = current->lChild;
            }
            else{
                tmp = current->rChild;
            }
        }

		//Atribui o nó a um dos filhos de current(Folha da arvore)
        if(value < current->data){
            current->lChild = insert;
        }
        else{
            current->rChild = insert;
        }
    }
}

int searchNode(struct Node* root,int value){
    if (root==NULL){
    	return 0;
    	// valor não encontrado
	}
    else{
        if (value==root->data){
        	return root->data;
		}            
        else if (value<root->data){
            // busca na subárvore lChild
            return searchNode(root->lChild, value);
        }
        else if (value > root->data){
            // busca na subárvore rChild
            return searchNode(root->rChild, value);
    	}
            
	}
}

struct Node* achaMaior(struct Node* root){
    while(root->rChild != NULL){
        root = root->rChild;
    }

    return root;
}

void deleteNode(struct Node** root, int value){
    struct Node* c1; 
    struct Node* c2;
    if(root != NULL){
        c1 = *root;
        c2 = *root; 

        while(c2 != NULL){
            if(c2->data == value){
                break;
            }

            if(c2 ->data > value){
                c1 = c2;
                c2 = c2->lChild;
            }
            else{
                c1 = c2;
                c2 = c2->rChild;
            }
        }

        if(c2 != NULL){
            if(c2->lChild == NULL && c2->rChild==NULL){
                //CASO: Nó não tem filhos

                if(c2 != *root){
                    if(c2 == c1->lChild){
                        c1->lChild = NULL;
                    }
                    else{
                        c1->rChild = NULL;
                    }
                }
                else{
                    *root = NULL;
                }

                free(c2);
            }
            else if(c2->lChild != NULL && c2->rChild != NULL){
                //CASO: Nó tem 2 filhos
                struct Node* sucessor = achaMaior(c2 -> lChild);
                int sucessorData = sucessor->data;

                deleteNode(root, sucessorData);

                c2->data = sucessorData;

            }
            else{
                //Pega a subarvore do Nó a ser Deletado
                Node* subTree = (c2->lChild)? c2->lChild : c2->rChild;

                if(c2 != *root){
                    if(c2 == c1->lChild){
                        c1->lChild = subTree;
                    }
                    else{
                        c1->rChild = subTree;
                    }
                }
                else{
                    *root = subTree;
                }

                free(c2);
            }
        }
    }
}

//Leitura Pre Ordem
void preOrder(struct Node* root){
    struct Node* current = root;

    if(current == NULL){
        return;
    }

    printf("%d", current->data);

    if(current->lChild){
        printf(" ");
    } 
    preOrder(current->lChild);

    if(current->rChild){
        printf(" ");
    } 
    preOrder(current->rChild);
}

//Leitura in-ordem
void inOrder(struct Node* root){
    struct Node* current = root;

    if(current == NULL){
        return;
    }

  

    inOrder(current->lChild);
	if(current->lChild){
        printf(" ");
    } 
    printf("%d", current->data); 
	
	if(current->rChild){
        printf(" ");
    } 
    inOrder(current->rChild);
}


//Leitura Pós Ordem
void postOrder(struct Node* root){
    struct Node* current = root;

    if(current == NULL){
        return;
    }
	
    postOrder(current->lChild);
    
    postOrder(current->rChild);
    if(j==0) {
    	printf("%d", current->data);
    	j++;
	}
    else printf(" %d", current->data);
}

//Free na arvore usando o metodo de Leitura Pos Ordem
void freeTree(struct Node** root){
    struct Node* current = *root;

    if(current == NULL){
        return;
    }
     
    freeTree(&current->lChild);
    freeTree(&current->rChild);
    free(current);
}

int main(){
    struct Node* root = NULL;
    int v;
    int i=0;
    char c[8];

    while(scanf("%s", &c) != EOF){
        if(strcmp(c, "I\0") == 0){
            scanf("%d", &v);

            insertNode(&root, v);
        }
        else if(strcmp(c, "P\0") == 0){
            scanf("%d", &v);
            
            if(searchNode(root, v)){
                printf("%d existe\n", v);
            }
            else{
                printf("%d nao existe\n", v);
            }
        }
        else if(strcmp(c, "PREFIXA\0") == 0){
            preOrder(root);
            printf("\n");
        }
        else if(strcmp(c, "POSFIXA\0") == 0){
        	j=0;
            postOrder(root);
            printf("\n");
        }
        else if(strcmp(c, "INFIXA\0") == 0){
            inOrder(root);
            printf("\n");
        }
        else if(strcmp(c, "R\0") == 0){
            scanf("%d", &v);

            deleteNode(&root, v);
        }
    }

    freeTree(&root);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* rChild;
    struct Node* lChild; 
} Node;

int j=0;

void insertNode(struct Node** root, int value){
    struct Node* insert = (struct Node*)calloc(1, sizeof(struct Node));
	
	//Inicializa os valores do novo nó.
    insert->data = value;
    insert->lChild = NULL;
    insert->rChild = NULL;
    
	//Verifica se a arvore está vazia
    if(*root == NULL){
        *root = insert;
    } 
    else{
        struct Node* current = *root;
        struct Node* tmp = *root;
		
        //Percorre a arvore com o tmp, ate achar tmp = NULL
        while(tmp != NULL){
            current = tmp;
            if(current->data > value){
                tmp = current->lChild;
            }
            else{
                tmp = current->rChild;
            }
        }

		//Atribui o nó a um dos filhos de current(Folha da arvore)
        if(value < current->data){
            current->lChild = insert;
        }
        else{
            current->rChild = insert;
        }
    }
}

int searchNode(struct Node* root,int value){
    if (root==NULL){
    	return 0;
    	// valor não encontrado
	}
    else{
        if (value==root->data){
        	return root->data;
		}            
        else if (value<root->data){
            // busca na subárvore lChild
            return searchNode(root->lChild, value);
        }
        else if (value > root->data){
            // busca na subárvore rChild
            return searchNode(root->rChild, value);
    	}
            
	}
}

struct Node* achaMaior(struct Node* root){
    while(root->rChild != NULL){
        root = root->rChild;
    }

    return root;
}

void deleteNode(struct Node** root, int value){
    struct Node* c1; 
    struct Node* c2;
    if(root != NULL){
        c1 = *root;
        c2 = *root; 

        while(c2 != NULL){
            if(c2->data == value){
                break;
            }

            if(c2 ->data > value){
                c1 = c2;
                c2 = c2->lChild;
            }
            else{
                c1 = c2;
                c2 = c2->rChild;
            }
        }

        if(c2 != NULL){
            if(c2->lChild == NULL && c2->rChild==NULL){
                //CASO: Nó não tem filhos

                if(c2 != *root){
                    if(c2 == c1->lChild){
                        c1->lChild = NULL;
                    }
                    else{
                        c1->rChild = NULL;
                    }
                }
                else{
                    *root = NULL;
                }

                free(c2);
            }
            else if(c2->lChild != NULL && c2->rChild != NULL){
                //CASO: Nó tem 2 filhos
                struct Node* sucessor = achaMaior(c2 -> lChild);
                int sucessorData = sucessor->data;

                deleteNode(root, sucessorData);

                c2->data = sucessorData;

            }
            else{
                //Pega a subarvore do Nó a ser Deletado
                Node* subTree = (c2->lChild)? c2->lChild : c2->rChild;

                if(c2 != *root){
                    if(c2 == c1->lChild){
                        c1->lChild = subTree;
                    }
                    else{
                        c1->rChild = subTree;
                    }
                }
                else{
                    *root = subTree;
                }

                free(c2);
            }
        }
    }
}

//Leitura Pre Ordem
void preOrder(struct Node* root){
    struct Node* current = root;

    if(current == NULL){
        return;
    }

    printf("%d", current->data);

    if(current->lChild){
        printf(" ");
    } 
    preOrder(current->lChild);

    if(current->rChild){
        printf(" ");
    } 
    preOrder(current->rChild);
}

//Leitura in-ordem
void inOrder(struct Node* root){
    struct Node* current = root;

    if(current == NULL){
        return;
    }

  

    inOrder(current->lChild);
	if(current->lChild){
        printf(" ");
    } 
    printf("%d", current->data); 
	
	if(current->rChild){
        printf(" ");
    } 
    inOrder(current->rChild);
}


//Leitura Pós Ordem
void postOrder(struct Node* root){
    struct Node* current = root;

    if(current == NULL){
        return;
    }
	
    postOrder(current->lChild);
    
    postOrder(current->rChild);
    if(j==0) {
    	printf("%d", current->data);
    	j++;
	}
    else printf(" %d", current->data);
}

//Free na arvore usando o metodo de Leitura Pos Ordem
void freeTree(struct Node** root){
    struct Node* current = *root;

    if(current == NULL){
        return;
    }
     
    freeTree(&current->lChild);
    freeTree(&current->rChild);
    free(current);
}

int main(){
    struct Node* root = NULL;
    int v;
    int i=0;
    char c[8];

    while(scanf("%s", &c) != EOF){
        if(strcmp(c, "I\0") == 0){
            scanf("%d", &v);

            insertNode(&root, v);
        }
        else if(strcmp(c, "P\0") == 0){
            scanf("%d", &v);
            
            if(searchNode(root, v)){
                printf("%d existe\n", v);
            }
            else{
                printf("%d nao existe\n", v);
            }
        }
        else if(strcmp(c, "PREFIXA\0") == 0){
            preOrder(root);
            printf("\n");
        }
        else if(strcmp(c, "POSFIXA\0") == 0){
        	j=0;
            postOrder(root);
            printf("\n");
        }
        else if(strcmp(c, "INFIXA\0") == 0){
            inOrder(root);
            printf("\n");
        }
        else if(strcmp(c, "R\0") == 0){
            scanf("%d", &v);

            deleteNode(&root, v);
        }
    }

    freeTree(&root);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* rChild;
    struct Node* lChild; 
} Node;

int j=0;

void insertNode(struct Node** root, int value){
    struct Node* insert = (struct Node*)calloc(1, sizeof(struct Node));
	
	//Inicializa os valores do novo nó.
    insert->data = value;
    insert->lChild = NULL;
    insert->rChild = NULL;
    
	//Verifica se a arvore está vazia
    if(*root == NULL){
        *root = insert;
    } 
    else{
        struct Node* current = *root;
        struct Node* tmp = *root;
		
        //Percorre a arvore com o tmp, ate achar tmp = NULL
        while(tmp != NULL){
            current = tmp;
            if(current->data > value){
                tmp = current->lChild;
            }
            else{
                tmp = current->rChild;
            }
        }

		//Atribui o nó a um dos filhos de current(Folha da arvore)
        if(value < current->data){
            current->lChild = insert;
        }
        else{
            current->rChild = insert;
        }
    }
}

int searchNode(struct Node* root,int value){
    if (root==NULL){
    	return 0;
    	// valor não encontrado
	}
    else{
        if (value==root->data){
        	return root->data;
		}            
        else if (value<root->data){
            // busca na subárvore lChild
            return searchNode(root->lChild, value);
        }
        else if (value > root->data){
            // busca na subárvore rChild
            return searchNode(root->rChild, value);
    	}
            
	}
}

struct Node* achaMaior(struct Node* root){
    while(root->rChild != NULL){
        root = root->rChild;
    }

    return root;
}

void deleteNode(struct Node** root, int value){
    struct Node* c1; 
    struct Node* c2;
    if(root != NULL){
        c1 = *root;
        c2 = *root; 

        while(c2 != NULL){
            if(c2->data == value){
                break;
            }

            if(c2 ->data > value){
                c1 = c2;
                c2 = c2->lChild;
            }
            else{
                c1 = c2;
                c2 = c2->rChild;
            }
        }

        if(c2 != NULL){
            if(c2->lChild == NULL && c2->rChild==NULL){
                //CASO: Nó não tem filhos

                if(c2 != *root){
                    if(c2 == c1->lChild){
                        c1->lChild = NULL;
                    }
                    else{
                        c1->rChild = NULL;
                    }
                }
                else{
                    *root = NULL;
                }

                free(c2);
            }
            else if(c2->lChild != NULL && c2->rChild != NULL){
                //CASO: Nó tem 2 filhos
                struct Node* sucessor = achaMaior(c2 -> lChild);
                int sucessorData = sucessor->data;

                deleteNode(root, sucessorData);

                c2->data = sucessorData;

            }
            else{
                //Pega a subarvore do Nó a ser Deletado
                Node* subTree = (c2->lChild)? c2->lChild : c2->rChild;

                if(c2 != *root){
                    if(c2 == c1->lChild){
                        c1->lChild = subTree;
                    }
                    else{
                        c1->rChild = subTree;
                    }
                }
                else{
                    *root = subTree;
                }

                free(c2);
            }
        }
    }
}

//Leitura Pre Ordem
void preOrder(struct Node* root){
    struct Node* current = root;

    if(current == NULL){
        return;
    }

    printf("%d", current->data);

    if(current->lChild){
        printf(" ");
    } 
    preOrder(current->lChild);

    if(current->rChild){
        printf(" ");
    } 
    preOrder(current->rChild);
}

//Leitura in-ordem
void inOrder(struct Node* root){
    struct Node* current = root;

    if(current == NULL){
        return;
    }

  

    inOrder(current->lChild);
	if(current->lChild){
        printf(" ");
    } 
    printf("%d", current->data); 
	
	if(current->rChild){
        printf(" ");
    } 
    inOrder(current->rChild);
}


//Leitura Pós Ordem
void postOrder(struct Node* root){
    struct Node* current = root;

    if(current == NULL){
        return;
    }
	
    postOrder(current->lChild);
    
    postOrder(current->rChild);
    if(j==0) {
    	printf("%d", current->data);
    	j++;
	}
    else printf(" %d", current->data);
}

//Free na arvore usando o metodo de Leitura Pos Ordem
void freeTree(struct Node** root){
    struct Node* current = *root;

    if(current == NULL){
        return;
    }
     
    freeTree(&current->lChild);
    freeTree(&current->rChild);
    free(current);
}

int main(){
    struct Node* root = NULL;
    int v;
    int i=0;
    char c[8];

    while(scanf("%s", &c) != EOF){
        if(strcmp(c, "I\0") == 0){
            scanf("%d", &v);

            insertNode(&root, v);
        }
        else if(strcmp(c, "P\0") == 0){
            scanf("%d", &v);
            
            if(searchNode(root, v)){
                printf("%d existe\n", v);
            }
            else{
                printf("%d nao existe\n", v);
            }
        }
        else if(strcmp(c, "PREFIXA\0") == 0){
            preOrder(root);
            printf("\n");
        }
        else if(strcmp(c, "POSFIXA\0") == 0){
        	j=0;
            postOrder(root);
            printf("\n");
        }
        else if(strcmp(c, "INFIXA\0") == 0){
            inOrder(root);
            printf("\n");
        }
        else if(strcmp(c, "R\0") == 0){
            scanf("%d", &v);

            deleteNode(&root, v);
        }
    }

    freeTree(&root);

    return 0;
}
