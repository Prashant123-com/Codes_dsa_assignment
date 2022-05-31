#include <stdio.h>
#include <stdlib.h>


typedef struct node {
               int data;
struct node* lhs;
               struct node* rhs;
}node;

node* newNode(int data)
{
  node * Node = (node *)malloc(sizeof(node));
    Node->data = data;
    Node->lhs = NULL;


Node->rhs = NULL;
    return (Node);
}

int lhs_hehs(node* node)
{
    int ht = 0;
    while (node) {
        ht++;
        node = node->lhs;
    }

    return ht;
}

int rhs_hehs(node* node)
{



    int ht = 0;
    while (node) {
        ht++;
        node = node->rhs;
    }

    return ht;
}

int TotalNodes(node* root)
{

    if (root == NULL)
        return 0;

    int lh = lhs_hehs(root);

    int rh = rhs_hehs(root);


    if (lh == rh)
        return (1 << lh) - 1;

                       return 1 + TotalNodes(root->lhs) + TotalNodes(root->rhs);
}


int main()
{
    node* root = newNode(1);


    root->lhs = newNode(2);
    root->rhs = newNode(3);


    root->lhs->lhs = newNode(4);
    root->lhs->rhs = newNode(5);
    root->rhs->lhs = newNode(9);



    root->rhs->rhs = newNode(8);
               root->lhs->lhs->lhs = newNode(6);


    root->lhs->lhs->rhs = newNode(7);
              printf("%d",TotalNodes(root));

    return 0;
}
