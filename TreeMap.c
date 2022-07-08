#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct noTree {
    struct noTree *left;
    struct noTree *right;
    struct noTree *father;
    int data;
};
typedef struct noTree noTree;
typedef noTree *noTreeP;


int preOrder(noTreeP arvP);

int insertIn(noTreeP *arvP, int data);

int main() {
    setlocale(LC_ALL, "English");

    noTreeP raizPtr = NULL;
    
    int data;
    int i;

    // Student register: 21174346-5
    printf("Enter student record digits: ");
    for (i = 0; i < 8; i++) {
        scanf("%1d", &data);
        insertIn(&raizPtr, data);
    }

    printf("\nPre order visit: ");
    preOrder(raizPtr);

    return 0;

}

int preOrder(noTreeP arvP) {
    if(arvP != NULL) {

        printf("%d ", arvP->data);

        preOrder(arvP->left);

        preOrder(arvP->right);
    }

    return 0;
}

int insertIn(noTreeP *arvP, int data) {
    static noTreeP auxFather = NULL;

    if(*arvP == NULL) {


        *arvP = malloc(sizeof(noTree));

        if(*arvP != NULL) {
            // insert data
            
            (*arvP)->data = data;
            (*arvP)->left = NULL;
            (*arvP)->right = NULL;
            (*arvP)->father = auxFather;
        } else {
            return 2;
        }
    } else {
        // Not empty tree

        auxFather = *arvP;

        if(data < (*arvP)->data)
        {
            // data < data current
            
            insertIn(&((*arvP)->left), data);
        } else if(data > (*arvP)->data) {
            // data > data current
            
            insertIn(&((*arvP)->right), data);
        } else {
            // data = data current
            
            return 1;
        }
    }

    return 0;
}