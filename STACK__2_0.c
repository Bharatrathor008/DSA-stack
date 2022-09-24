#include <stdio.h>
#include <stdlib.h>
struct STACK
{
    int *stack;
    int max_size;
    int top;
}; // STACK structure for stack items.

// peek function retuns the item of given position.
int peek(struct STACK *ptr, int position)
{
    return (ptr->stack[ptr->top - position + 1]);
}

int isFull(struct STACK *ptr)
{
    if (ptr->top == ptr->max_size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct STACK *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

void push(struct STACK *ptr)
{
    int item;
    if (isFull(ptr))
    {
        printf("\nStack is Overflow!\n");
    }
    else
    {
        printf("\nEnter a value : ");
        scanf("%d", &item);
        ptr->top += 1;
        ptr->stack[ptr->top] = item;
    }
}
void pop(struct STACK *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\nStack is UnderFlow!\n");
        return;
    }
    else
    {
        printf("\n%d Item is Poped out.\n", ptr->stack[ptr->top]);
        ptr->top -= 1;
    }
}

void display(struct STACK *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\nStack is Underflow!\n");
    }
    else
    {
        printf("\n|*===============Element Present in STACK==============*|\n");
        for (int i = ptr->top; i >= 0; i--)
        {
            printf("|\t\t|\t%d\t|\t\t\t|\n", ptr->stack[i]);
        }
        printf("|=======================================================|\n");
    }
}
void operations()
{
    printf("\n\nEnter 1: for PUSH.\n");
    printf("Enter 2: for POP.\n");
    printf("Enter 3: for DISPLAY.\n");
    printf("Enter 4: for PEEK.\n");
    printf("Enter 5: for EXIT.\n");
}
// main function.
int main(void)
{
    int choice, pos;
    struct STACK *s = (struct STACK *)malloc(sizeof(struct STACK));
    printf("Enter the Max_size of Stack : ");
    scanf("%d", &s->max_size);
    // s->max_size = 5;
    s->top = -1;
    s->stack = (int *)malloc(s->max_size * sizeof(int));
    while (1)
    {
        operations();
        printf("Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(s);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            display(s);
            break;
        case 4:
            printf("\nEnter the position : ");
            scanf("%d", &pos);
            if ((s->top - pos + 1) >= 0)
                printf("\n%d element is present at %d position.\n", peek(s, pos), pos);
            else
                printf("\nSorry you have entered a wrong position.\n");
            break;
        case 5:
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("\nSorry, Your have Entered a Wrong Choice!\n");
            break;
        }
    }
    return 0;
}