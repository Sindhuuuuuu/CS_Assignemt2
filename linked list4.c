/*
C program to delete a node in a linked list at a given position
*/

#include <stdio.h>
#include <stdlib.h>
  
struct Node
{
    int data;
    struct Node *next;
};
  
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
  
void deleteNode(struct Node **head_ref, int position)
{
   if (*head_ref == NULL)
   return;
  
   struct Node* temp = *head_ref;
  
    if (position == 0)
    {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }
 
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;

    if (temp == NULL || temp->next == NULL)
         return;

    struct Node *next = temp->next->next;
    free(temp->next);  
    temp->next = next; 
}
  
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
  
  int main()
{
    struct Node* head = NULL;
  
    push(&head, 12);
    push(&head, 19);
    push(&head, 32);
    push(&head, 23);
    push(&head, 28);
  
    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 3);
    puts("\nLinked List after Deletion at position 4: ");
    printList(head);
    return 0;
}