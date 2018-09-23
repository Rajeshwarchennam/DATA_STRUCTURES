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
void insert_end(struct node** head_ref,struct node **last,int n){
  struct node* new_node=create_node(n);
  if (*head_ref== NULL){
    *head_ref=new_node;
    *last=new_node;
    return;
  }
  (*last)->next=new_node;
  new_node->prev=*last;
  *last=new_node;
}
void insert_beginning(struct node **head_ref,struct node **last,int n){
  struct node* new_node=create_node(n);
  if (*head_ref== NULL){
    *head_ref=new_node;
    *last=new_node;
    return;
  }
 (*head_ref)->prev=new_node;
  new_node->next=*head_ref;
  *head_ref=new_node;
}
void print (struct node** head_ref){
  struct node*temp=*head_ref;
  if (temp==NULL){
    return;
  }
  int j=0;
  while(temp!=NULL){
    if (temp->data!=0){
      j=1;
    }
    if (j==1){
    printf("%d",temp->data);
  }
    temp=temp->next;
  }
  if(j==0){
    int k=0;
    printf("%d",k);
  }
  printf("\n");
}
void empty(struct node** head_ref,struct node** last){
  struct node*temp=*head_ref;
  struct node* next;
  while(temp!=NULL){
    next=temp->next;
    free(temp);
    temp=next;
  }
  *head_ref=NULL;
  *last=NULL;
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
int max(int a,int b){
  if (a>b){
    return a;
  }
  else{
    return b;
  }
}
void addition(struct node**head,struct node**last,struct node**head1,struct node**head2,struct node**last1,struct node**last2){
  struct node*temp1=*last1;
  struct node*temp2=*last2;
  int carry=0;
  int t=len(head2);
  for (int i=0;i<t;i++){
    int a=(temp1->data)+(temp2->data)+carry;
    if (i!=(t-1)){
    temp1=temp1->prev;
    temp2=temp2->prev;
    }
    if (a>9){
      carry=1;
      insert_beginning(head,last,a-10);
      //a=a-10;
    }
    else{
      insert_beginning(head,last,a);
      carry=0;
    }

  }
  if (carry==1){
    insert_beginning(head,last,carry);
  }
}
int main()
{
  struct node*head1=NULL;
  struct node*last1=NULL;
  struct node*head2=NULL;
  struct node*last2=NULL;
  struct node*head=NULL;
  struct node*last=NULL;
  char digit;
  int selection=1;
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      int m=max(len(&head1),len(&head2));
      int len_head1=len(&head1);
      int len_head2=len(&head2);
      if (m==len(&head1)){
        for (int i=0;i<(len_head1-len_head2);i++){
          insert_beginning(&head2,&last2,0);
        }

      }
      else{
        for (int i=0;i<(len_head2-len_head1);i++){
          insert_beginning(&head1,&last1,0);
        }

      }
      addition(&head,&last,&head1,&head2,&last1,&last2);
      print(&head);
      empty(&head1,&last1);
      empty(&head2,&last2);
      empty(&head,&last);
      selection=1;

    }
    else if(digit==' '){
      struct node*head2=NULL;
      struct node*last2=NULL;
      selection=2;
    }
    else{
      if (selection==1)
      {
        insert_end(&head1,&last1,digit-'0');
      }
      if (selection==2)
      {
        insert_end(&head2,&last2,digit-'0');
      }
    }
  }
  return(0);


}
