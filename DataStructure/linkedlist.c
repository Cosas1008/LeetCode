#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node* List;

void printList(List n)
{
    printf("List Start:\n");
    while(n != NULL) {
        printf("- %d -", n->data);
        n = n->next;
    }
    printf("List end\n");
}

// Time-complexity O(N)
void find_mid_reverse_print(List head)
{
    //traverse through list
    int num = 0;
    while(head->next != NULL){
        num++;
    }
    printf("Number of node: %d", num);
}

int main()
{
    char str[100];
    int num;
    printf("Enter the number of list:\n");
    scanf("%d", &num);
    printf("You've entered %d", num);
    List list[num];
    srand(num);
    List head, cur;
    cur = (List)malloc(sizeof(struct Node));
    cur->data = rand() % 100 + 1; 
    head = cur;
    // generate random data into nodes
    for(int i = 0; i < num; i++){
        List nxt = (List)malloc(sizeof(struct Node));
        nxt->data = rand() % 100 + 1;
        cur->next = nxt;
        nxt->next = NULL;
        cur = nxt;
    }
    printList(head);
    return 0;
}