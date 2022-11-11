#include <stdio.h>
#include <stdlib.h>

struct NODE 
{
    struct NODE* llink;
    int data;
    struct NODE* rlink;
};
struct NODE* head;
struct NODE* tail;

struct NODE* makenode(int value){
    struct NODE *node = (struct NODE*)malloc(sizeof(struct NODE));
    node->llink = NULL;
    node->data = value;
    node->rlink = NULL;
    return node;
}

void print(){
    struct NODE *p;
    p = head;
    while(p->rlink != tail){
        printf("%d-->",p->data);
        p = p->rlink;
    }
    printf("%d",p->data);
}

void init(){
    head = (struct NODE*)malloc(sizeof(struct NODE));
    tail = (struct NODE*)malloc(sizeof(struct NODE));
    head->data = 0;
    tail->data = 0;

    head->rlink = tail;
    head->llink = head;
    tail->rlink = tail;
    tail->llink = head;
}

void push_back(int value){ 
    struct NODE* newnode = makenode(value);
    struct NODE* p;
    p = tail;
    p->llink->rlink = newnode;
    newnode->llink = p->llink;
    p->llink = newnode;
    newnode->rlink = p;
}

int main(){
    init(); 
    push_back(10); 
    push_back(30);
    push_back(50);
    print();  
    printf("\n");	
    return 0;
}
