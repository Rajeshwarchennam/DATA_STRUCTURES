#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;
  struct node* prev;
};
struct node* create_node(int n){
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=n;
  new_node->next=NULL;
  new_node->prev=NULL;
  return new_node;
}
void insert_end(struct node** head_ref,int n){
  struct node* new_node=create_node(n);
  if (*head_ref== NULL){
    *head_ref=new_node;
    return;
  }
  struct node*temp=*head_ref;
  while(temp->next!=NULL)
  {
    temp=temp->next;
  }
  temp->next=new_node;
  new_node->prev=temp;
}
void insert_beginning(struct node **head_ref,int n){
  struct node* new_node=create_node(n);
  new_node->next=*head_ref;
  if (*head_ref== NULL){
    *head_ref=new_node;
    return;
  }
 (*head_ref)->prev=new_node;

  *head_ref=new_node;
}
void print (struct node** head_ref){
  struct node*temp=*head_ref;
  if (temp==NULL){
    return;
  }
  while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
  }

}
int len(struct node** head_ref){
  int length=0;
  struct node *temp=*head_ref;
  while(temp!=NULL){
    length++;
    temp=temp->next;
  }
  return length;
}

void addition(struct node**head1,struct node**head2,struct node**head){
  while((*head1)->next!=NULL){
          (*head1)=(*head1)->next;
  }
  while((*head2)->next!=NULL){
          (*head2)=(*head2)->next;
  }
  int q=len(head1);
  int i=0;
  int r=0;
  for(i=0;i<q;i++){
      if((*head1)->data+(*head2)->data+r<10){
          insert_beginning(head,(*head1)->data+(*head2)->data+r);
          r=0;
      }
      else
          {insert_beginning(head,(*head1)->data+(*head2)->data+r-10);
          r=1;}
      if(i!=q-1){
          (*head1)=(*head1)->prev;
          (*head2)=(*head2)->prev;}
  }
  if(r==1){
      insert_beginning(head,1);
  }

}
void empty(struct node** head_ref){
  struct node*temp=*head_ref;
  struct node* next;
  while(temp!=NULL){
    next=temp->next;
    free(temp);
    temp=next;
  }
  *head_ref=NULL;
}
int main()
{
  struct node*head1=NULL;
  struct node*head2=NULL;
  struct node*head=NULL;
  char digit;
  int selection=1;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      int x=len(&head1);
      int y=len(&head2);
      for(int i=0;i<abs(x-y);i++){
      if(x>y) insert_beginning(&head2,0);
      else {insert_beginning(&head1,0);}
     }
     addition(&head1,&head2,&head);
     print(&head);
     empty(&head);
     empty(&head1);
     empty(&head2);
     selection=1;


    }
    else if(digit==' '){
      selection=2;
    }
    else{
      if (selection==1)
      {
        insert_end(&head1,digit);
      }
      if (selection==2)
      {
        insert_end(&head2,digit);
      }
    }
  }
  return(0);


}
