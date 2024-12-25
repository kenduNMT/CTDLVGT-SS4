#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Định nghĩa cấu trúc node
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

// Hàm tạo node mới
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm tạo danh sách liên kết với n phần tử
Node *createList(int n)
{
    if (n <= 0)
        return NULL;

    srand(time(NULL));
    Node *head = NULL;
    Node *current = NULL;

    printf("Nhap %d phan tu cho danh sach:\n", n);
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

// Hàm duyệt và in danh sách
void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        else
        {
            printf(" -> NULL\n");
        }
        current = current->next;
    }
}

// Hàm giải phóng bộ nhớ
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
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Danh sach trong.\n");
        return 0;
    }

    Node *head = createList(n);
    printf("Danh sach: ");
    printList(head);
    freeList(head);

    return 0;
}