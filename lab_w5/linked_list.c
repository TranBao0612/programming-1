#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node * next;
};

// insert (add) a Node with data to the end of the list
void push_back(struct Node * head, int data)
{   // This code can be used for either passing *head or **head
    struct Node *ptr, *temp;
    ptr = head;
    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = NULL;

    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;

    /*Since head pointer is passed by value, so we can directly edit it without affecting the original pointer, as follow:
    struct Node *ptr, *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = NULL;

    while(head->next != NULL) {
        head = head->next;
    }
    head->next = temp;
    */

}

struct Node * toLinkedList(int * data_arr, int N)
{
    struct Node * head = malloc(sizeof(struct Node));
    head->data = data_arr[0];
    head->next = NULL;

    for(int i = 1; i<N; i++) {
        push_back(head, data_arr[i]);
    }

    // Assign data to head first (next = Null)
    // for element in array (with n elements)
    // push_back(head, element) -> add every element in arr

    return head;
}

int * getData(struct Node * head) // Check if head is NULL
{
    if(head == NULL) return NULL;

    int *out = NULL;
    int size = 0;
    struct Node *ptr;
    ptr = head;

    do
    {
        size ++;
        out = realloc(out, size * sizeof(int));
        out[size - 1] = ptr->data;
        ptr = ptr->next;
    } while (ptr->next != NULL);

    return out;
}

int main()
{
    int arr[] = {1, 4, 3, 7, 6};
    struct Node * linked_list = toLinkedList(arr, 5);

    int *ans = getData(linked_list);
    for(int i = 0; i<5; i++) {
        printf("%d ", arr[i]);
    }

    return 0; // set break point
}

