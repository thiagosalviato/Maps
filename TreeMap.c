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


int preOrder(noTreeP treeP);

int insertIn(noTreeP *treeP, int data);

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

int preOrder(noTreeP treeP) {
    if(treeP != NULL) {

        printf("%d ", treeP->data);

        preOrder(treeP->left);

        preOrder(treeP->right);
    }

    return 0;
}

int insertIn(noTreeP *treeP, int data) {
    static noTreeP auxFather = NULL;

    if(*treeP == NULL) {


        *treeP = malloc(sizeof(noTree));

        if(*treeP != NULL) {
            // insert data
            
            (*treeP)->data = data;
            (*treeP)->left = NULL;
            (*treeP)->right = NULL;
            (*treeP)->father = auxFather;
        } else {
            return 2;
        }
    } else {
        // Not empty tree

        auxFather = *treeP;

        if(data < (*treeP)->data)
        {
            // data < current data
            
            insertIn(&((*treeP)->left), data);
        } else if(data > (*treeP)->data) {
            // data > current data
            
            insertIn(&((*treeP)->right), data);
        } else {
            // data = current data
            
            return 1;
        }
    }

    return 0;
}
