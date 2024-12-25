#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* createList(int n) {
    if (n <= 0) return NULL;
    Node* head = NULL;
    Node* current = NULL;
    printf("Nhap data cho danh sach:\n");
    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap gia tri cho node %d: ", i + 1);
        scanf("%d", &value);
        Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    return head;
}

int searchList(Node* head, int target) {
    Node* current = head;
    int index = 0;
    
    while (current != NULL) {
        if (current->data == target) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sach trong.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->next != NULL) {
            printf("-> ");
        } else {
            printf("-> NULL\n");
        }
        current = current->next;
    }
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n, target;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Danh sach trong.\n");
        return 0;
    }

    Node* head = createList(n);
    printf("Danh sach vua tao: ");
    printList(head);
    
    printf("Nhap gia tri can tim: ");
    scanf("%d", &target);
    
    int result = searchList(head, target);
    if (result != -1) {
        printf("Tim thay tai vi tri %d\n", result);
    } else {
        printf("Khong tim thay gia tri %d trong danh sach\n", target);
    }
    
    freeList(head);
    return 0;
}
