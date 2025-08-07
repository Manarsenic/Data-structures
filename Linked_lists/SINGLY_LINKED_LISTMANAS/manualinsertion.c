#include<stdio.h>
#include<stdlib.h>  
struct node{
    int data;
    struct node *next;
};
struct node* head=NULL;
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;

}
void insertatbeg(int data, int position){
    struct node* newnode = createnode(data);
    if(position == 1){
        newnode->next = head;
        head = newnode;
        return;
    }
    struct node* temp = head;
    for(int i = 1; i < position - 1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("out of bound\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void printlist(){
    struct node* temp = head;
    while (temp !=NULL){
        printf("%d ", temp->data);
        temp = temp->next;

    }

}
int main(){
    int n, data, position;
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        printf("Enter position to insert node %d: ", i + 1);
        scanf("%d", &position);
        insertatbeg(data, position);
    }
    printf("linked list:");
    printlist();
    return 0;
}
