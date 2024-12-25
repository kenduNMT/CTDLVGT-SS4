#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Node *createList(int n)
{
    if (n <= 0)
        return NULL;
    Node *head = NULL;
    Node *current = NULL;
    printf("nhap data cho danh sach: \n ");
    for (int i = 0; i < n; i++)
    {
        int value;
        printf("Nhap gia tri cho node %d: ", i + 1);
        scanf("%d", &value);
        Node *newNode = createNode(value);
        if (head == NULL)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }
    return head;
}
Node *addHead(Node *head, int value)
{
    Node *temp = createNode(value);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        if (current->next != NULL)
        {
            printf("->");
        }
        else
        {
            printf("-> NULL\n");
        }
        current = current->next;
    }
}
void freeList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    int n, value;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    Node *head = createList(n);
    printf("Danh sach sau khi nhap: ");
    printList(head);
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    head = addHead(head, value);
    printf("Danh sach sau khi them: ");
    printList(head);
    freeList(head);
    return 0;
}