
/*
Assigend by:
Re'em Rothenberg #307903682,:61108
Shay Bach #204263842,:61108
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {

    int data;
    struct node* left;
    struct node* right;
    struct node* root;
    struct node* next;

} Node;
void insert(Node** tree)
{

    int num, enter = 1, condition = 1;
    Node* curr;

    while (enter == 1) {

        printf("please enter a value fo the tree\n");
        scanf("%d", &num);

        if (*tree == NULL) {

            *tree = (Node*)malloc(sizeof(Node));

            (*tree)->data = num;

            (*tree)->left = NULL;

            (*tree)->right = NULL;

            (*tree)->root = NULL;
        }

        else {

            curr = *tree;

            while (condition == 1) {

                if (curr->data > num)
                    if (curr->left != NULL)
                        curr = curr->left;

                    else {

                        curr->left = (Node*)malloc(sizeof(Node));

                        curr->left->data = num;

                        curr->left->left = NULL;

                        curr->left->right = NULL;

                        curr->left->root = curr;

                        condition = 0;
                    }

                if (curr->data < num)
                    if (curr->right != NULL)
                        curr = curr->right;

                    else {

                        curr->right = (Node*)malloc(sizeof(Node));

                        curr->right->data = num;

                        curr->right->left = NULL;

                        curr->right->right = NULL;

                        curr->right->root = curr;

                        condition = 0;
                    }
            }
        }
        condition = 1;

        printf("to enter anther value enter '1', to stop enter '0'\n");
        scanf("%d", &enter);
    }

    printf("\n\n");
}
void push(Node* x, Node** ps)
{
    x->next = *ps;
    *ps = x;
}
void pop(Node** ps)
{
    Node* temp;

    temp = *ps;
    *ps = temp->next;
    temp->next = NULL;
}
void inorder_print(Node* tree)
{

    Node* stack = NULL;

    printf("the tree in order is:\n");

    while (tree != NULL) {

        while (tree->left != NULL)
            tree = tree->left;

        printf("%d\t", tree->data);

        while (tree->right == NULL || tree == stack) {

            if (tree == stack)
                pop(&stack);

            tree = tree->root;

            if (tree == NULL)
                break;

            if (tree == stack) {
            }

            else
                printf("%d\t", tree->data);
        }

        if (tree != NULL)
            if (tree->right != NULL) {

                push(tree, &stack);

                tree = tree->right;
            }
    }

    printf("\n\n");
}
void in_tor(Node* tree, Node** tor)
{

    Node* curr;

    if (*tor == NULL) {

        *tor = tree;
        (*tor)->next = NULL;
    }

    else {

        curr = *tor;

        while (curr->next != NULL)
            curr = curr->next;

        curr->next = tree;

        curr->next->next = NULL;
    }
}
void rec(Node* tree, int n, Node** tor)
{

    if (n != 0 && tree != NULL) {

        if (n == 1)
            in_tor(tree, tor);

        rec(tree->left, n - 1, tor);
        rec(tree->right, n - 1, tor);
    }
}
void print(Node* tree)
{

    int n, condition = 1, i = 0, j = 1;
    Node* tor = NULL;
    Node* curr;

    printf("the tree in rank is:\n");

    for (n = 1; i != j; n++) {

        i = 0;
        j = 0;

        curr = tor;
        while (curr != NULL) {
            i++;
            curr = curr->next;
        }

        rec(tree, n, &tor);

        curr = tor;
        while (curr != NULL) {
            j++;
            curr = curr->next;
        }
    }

    while (tor != NULL) {
        printf("%d\t", tor->data);
        tor = tor->next;
    }

    printf("\n");
}
void FREE(Node* tree)
{

    if (tree->left != NULL)
        FREE(tree->left);

    if (tree->right != NULL)
        FREE(tree->right);

    free(tree);
}
void main()
{

    Node* tree = NULL;

    insert(&tree);

    inorder_print(tree);

    print(tree);

    FREE(tree);
}
