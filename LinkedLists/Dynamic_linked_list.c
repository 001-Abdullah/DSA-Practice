#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int number;
    struct node *next;
} node;
int main()
{
    node *head = NULL;
    node *tail = NULL;
    printf("(In the following code, enter -1 when done)\n");
    while (1)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            return 1;
        }
        
        printf("Enter the number: ");
        scanf("%d", &temp->number);
        temp->next = NULL;
        if (temp->number == -1)
        {
            free(temp);
            break;
        }
        else if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        
        else
        {
            tail->next = temp;
            temp->next = NULL;
            tail = temp;
        }
    }
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->number);
    }
    node *ptr = head;
    while(ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    
    return 0;
}