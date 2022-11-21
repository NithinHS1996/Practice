#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node* ptr;
}*head;
int count = 0;

int create()
{
    printf("Hello world create\n");
    int i = 1;
    struct node* temp;
    struct node* start;
    while(i < 6)
    {
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = i;
	temp->ptr = NULL;
	if(head == NULL)
	{
	    head = temp;
	    start = head;
	}
	else
	{
	    start->ptr = temp;
	    start = start->ptr;
	}
        printf("Entered value%d\n",start->data);
	i++;
    }
    printf("Creation done\n");
    return 1;
}

int display()
{
    printf("Hello world display\n");
    int i = 0;
    struct node* start = head;
    while(start != NULL)
    {
	printf("value is %d\n", start->data);
	start = start->ptr;
    }
    printf("Display done\n");
    return 1;
}

void displayRecursive(struct node * ptr)
{
    if(ptr != NULL)
    {
	count++;
	printf("value is %d\n", ptr->data);
	displayRecursive(ptr->ptr);
    }
    else
    {
	printf("Count is %d\n", count);
    }
}

int maxRecursive(struct node * ptr)
{
    int max = 0;
    if(ptr->ptr != NULL)
    {
	printf("value is %d\n", ptr->data);
	maxRecursive(ptr->ptr);
    }
    else
    {
	if(max < ptr->data)
	    return ptr->data;
	else
	    return max;
    }
}
 
int main()
{
    printf("Hello world\n");
    create();
    display();
    displayRecursive(head);
    printf("Max value is %d\n",maxRecursive(head));
    return 0;
}
