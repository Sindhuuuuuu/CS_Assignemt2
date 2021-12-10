#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x) 
        return root;
    else if(x>root->data) 
        return search(root->right, x);
    else 
        return search(root->left,x);
}

struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL) 
        return find_minimum(root->left); 
    return root;
}

struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) 
        root->right = insert(root->right, x);
    else 
        root->left = insert(root->left,x);
    return root;
}

struct node* delete(struct node *root, int x)
{
    
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right = delete(root->right, x);
    else if(x<root->data)
        root->left = delete(root->left, x);
    else
    {
    
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

       
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

     
        else
        {
            struct node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL) 
    {
        inorder(root->left); 
        printf(" %d ", root->data); 
        inorder(root->right);
    }
}

int main()
{
    struct node *root;
    root = new_node(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);

    inorder(root);
    printf("\n");
    root = delete(root, 1);
    root = delete(root, 40);
    root = delete(root, 45);
    root = delete(root, 9);
    inorder(root);
  
    printf("\n");

    return 0;
}