typedef struct Node {
    int data;
    struct Node* next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->next = NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList* p = obj->next;
    int j = 0;

    while(p != NULL && j < index){
        p = p->next;
        j++;
    }

    if(p == NULL || index < 0)return -1;
    
    return p->data;

}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* p = obj;
    MyLinkedList* h = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    h->data = val;
    h->next = p->next;
    p->next = h;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* p = obj;
    MyLinkedList* t = (MyLinkedList*)malloc(sizeof(MyLinkedList));

    t->data = val;
    t->next = NULL;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = t;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* p = obj->next;
    MyLinkedList* q = obj;
    MyLinkedList* n = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    int j = 0;
    n->data = val;

    while(p != NULL && j < index){
        j++;
        p = p->next;
        q = q->next;
    }

    if(p != NULL || j >= index){
        n->next = q->next;
        q->next = n;
    }

}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* p = obj->next;
    MyLinkedList* q = obj;
    int j = 0;

    while(p != NULL && j < index){
        j++;
        p = p->next;
        q = q->next;
    }

    if(p != NULL && index >= 0){
        q->next = p->next;
        free(p);
        p = q->next;
    }

}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* p = obj;
    MyLinkedList* q = obj->next;

    while(q != NULL){
        free(p);
        p = q;
        q = q->next;
    }
    free(p);    
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/