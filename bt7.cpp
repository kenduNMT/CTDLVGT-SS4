#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data= value;
    newNode -> next = NULL;
    return newNode;

}
Node* createList(int n){
    if (n <= 0) return NULL;
    Node* head = NULL;
    Node* current = NULL;
    printf("nhap data cho danh sach: \n ");
    for(int i=0; i<n; i++){
        int value;
        printf("Nhap gia tri cho node %d: ", i + 1);
        scanf("%d", &value);
        Node* newNode =createNode(value);
        if(head == NULL){
            head =newNode;
            current= newNode;
        } else{
            current -> next = newNode;
            current = newNode;
        }
    }
    return head;
}

void printList(Node* head){
    Node* current = head;
    while(current != NULL){
        printf("%d ", current->data);
        if(current-> next != NULL){
            printf("->");
        }else{
            printf("-> NULL\n");
        } current= current -> next;
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

Node* reverseList(Node* head) {
    Node *prev = NULL, *current = head, *next = NULL;
    
    while (current != NULL) {
        // Lưu node tiếp theo
        next = current->next;
        
        // Đảo chiều liên kết
        current->next = prev;
        
        // Di chuyển prev và current tiếp một bước
        prev = current;
        current = next;
    }
    
    // prev là node cuối cùng, giờ trở thành head mới
    return prev;
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

        if (n <= 0)
    {
        printf("Danh sach trong.\n");
        return 0;
    }

    Node* head = createList(n);
    printf("Danh sach ban dau: ");
    printList(head);
    
    // Đảo ngược danh sách
    head = reverseList(head);
    printf("Danh sach sau khi dao nguoc: ");
    printList(head);
    
    freeList(head);
    return 0;
}