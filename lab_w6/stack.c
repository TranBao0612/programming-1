#include <stdio.h>
#include <stdlib.h>

/// @brief Implement stack using linked list

struct Node
{
    int data;
    struct Node* next;
};

struct Stack
{
    struct Node* top; // also be the head of the linked list
};

void push(struct Stack* stack, int data)
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = stack->top;
    stack->top = temp;

    temp = NULL;
}

int pop(struct Stack* stack)
{
    struct Node *temp;

    temp = stack->top;
    stack->top = stack->top->next;

    int ans = temp->data;
    free(temp);
    temp = NULL;

    return ans;
}

// return 1 if the stack is empty otherwise 0
int is_empty(const struct Stack* stack)
{
    if(stack->top == NULL) 
        return 1;
    else
        return 0;
}

int main()
{
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->top = NULL;

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    // test
    struct Node* temp;
    temp = stack->top;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    while (!is_empty(stack))
    {
        printf("%d\n", pop(stack));
    }

    free(stack);
    stack = NULL;

    return 0;
}