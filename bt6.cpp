#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc node
struct Node
{
    int data;
    struct Node *next;
};

// Hàm tạo node mới
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hàm xóa phần tử tại vị trí position
struct Node *deleteAtPosition(struct Node *head, int position)
{
    // Nếu danh sách rỗng
    if (head == NULL)
    {
        printf("Danh sach rong!\n");
        return NULL;
    }

    // Nếu xóa vị trí đầu tiên
    if (position == 0)
    {
        struct Node *temp = head->next;
        free(head);
        return temp;
    }

    struct Node *current = head;
    struct Node *prev = NULL;
    int count = 0;

    // Tìm vị trí cần xóa
    while (current != NULL && count < position)
    {
        prev = current;
        current = current->next;
        count++;
    }

    // Nếu vị trí không hợp lệ
    if (current == NULL)
    {
        printf("Vi tri khong hop le\n");
        return head;
    }

    // Xóa node tại vị trí đã tìm thấy
    prev->next = current->next;
    free(current);
    return head;
}

// Hàm in danh sách
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
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

int main()
{
    int choice, position;
    Node *list = NULL;

    do
    {
        printf("\n=== MENU ===\n");
        printf("1. Tao danh sach moi\n");
        printf("2. Xoa phan tu tai vi tri bat ky\n");
        printf("3. Hien thi danh sach\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (list != NULL)
            {
                freeList(list);
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
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &position);
            list = deleteAtPosition(list, position);
            printf("Danh sach sau khi xoa:\n");
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
            break;

        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 4);

    if (list != NULL)
    {
        freeList(list);
    }
    return 0;
}
