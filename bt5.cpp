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

Node *insertAt(Node *head, int value, int position)
{
    Node *newNode = createNode(value);

    if (position == 0)
    {
        newNode->next = head;
        return newNode;
    }

    Node *current = head;
    int currentPos = 0;

    while (current != NULL && currentPos < position - 1)
    {
        current = current->next;
        currentPos++;
    }

    if (current == NULL)
    {
        printf("Vi tri chen khong hop le!\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

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
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int choice, value, position;
    Node *list = NULL;

    do
    {
        printf("\n=== MENU ===\n");
        printf("1. Tao danh sach moi\n");
        printf("2. Them phan tu vao vi tri bat ky\n");
        printf("3. Hien thi danh sach\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (list != NULL)
            {
                freeList(list); // Giải phóng danh sách cũ nếu tồn tại
            }
            printf("Nhap so luong phan tu: ");
            int n;
            scanf("%d", &n);
            list = createList(n);
            printf("Danh sach sau khi tao:\n");
            printList(list);
            break;

        case 2:
            if (list == NULL)
            {
                printf("Vui long tao danh sach truoc!\n");
                break;
            }
            printf("Nhap gia tri can them: ");
            scanf("%d", &value);
            printf("Nhap vi tri can them: ");
            scanf("%d", &position);
            list = insertAt(list, value, position);
            printf("Danh sach sau khi them:\n");
            printList(list);
            break;

        case 3:
            if (list == NULL)
            {
                printf("Danh sach rong!\n");
            }
            else
            {
                printf("Danh sach hien tai:\n");
                printList(list);
            }
            break;

        case 4:
            printf("Tam biet!\n");
            break;

        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 4);

    if (list != NULL)
    {
        freeList(list); // Giải phóng bộ nhớ trước khi kết thúc
    }
    return 0;
}