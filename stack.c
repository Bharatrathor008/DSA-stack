#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "colors.h"

struct stack
{
    int *arr;
    int max_size;
    int top;
};

void operations()
{
    printf("\n"boxBlue yellow bold"---------CHOOSE-A-VALID-OPERATION-------------"colorReset"\n");
    printf(cyan"Enter E/e : for push.\n");
    printf("Enter R/r : for pop.\n");
    printf("Enter D/d : for Display Stack.\n");
    printf("Enter Q/q : for Exit.\n");
    printf("\n----------------------------------------------\n"colorReset);
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->max_size - 1)
        return 1;
    else
        return 0;
}

void DisplayStack(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf(red bold"Stack is Underflow!.\n"colorReset);
    }
    else
    {
        printf(boxYellow bold red"Element present in Stack"colorReset"\n");
        for (int i = ptr->top; i >= 0; i--)
        {
            printf(bold green"|\t%d\t|\n", ptr->arr[i]);
            if(i==0)
            printf("-----------------"colorReset"\n");
        }
    }
}

void push(struct stack *ptr)
{
    int item;
    // if (ptr->top == ptr->max_size-1)
    if(isFull(ptr))
    {
        printf(red bold"Stack is Overflow!\n"colorReset);
    }
    else
    {
        printf(yellow bold"Enter a value to insert in Stack : "colorReset);
        scanf("%d", &item);
        ptr->top++;
        ptr->arr[ptr->top] = item;
    }
}

void pop(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf(red bold"Stack is Underflow!.\n"colorReset);
    }
    else
    {
        printf(blue bold italic"Element : %d is poped out .\n"colorReset, ptr->arr[ptr->top]);
        ptr->top--;
    }
    DisplayStack(ptr);
}
int main()
{   
    char choice;
    int size;
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    printf(bold voilet"Enter the Size of Stack do you wan't : "colorReset);
    scanf("%d", &size);
    s->max_size = size;
    s->top = -1;
    s->arr = (int *)malloc(s->max_size * sizeof(int));
    while (1)
    {
        operations();
        choice = getch();
        switch (choice)
        {
        case 'E':
        case 'e':
            push(s);
            break;
        case 'R':
        case 'r':
            pop(s);
            break;
        case 'd':
        case 'D':
            DisplayStack(s);
            break;
        case 'q':
        case 'Q':
            exit(EXIT_SUCCESS);
        default:
            printf(underline bold grey"Invalid option!"colorReset);
            break;
        }
    }
    return 0;
}
