#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* next;
  struct node* prev;
};
struct node* create_node(int n);
void insert_end(struct node** head_ref,struct node **last,int n);
void empty(struct node** head_ref,struct node** last);
int len(struct node** head_ref);
void comparision(struct node **head1,struct node **head2);
int main()
{
  struct node*head1=NULL;
  struct node*last1=NULL;
  struct node*head2=NULL;
  struct node*last2=NULL;
  char digit;
  int selection=1;//selects to which linked list number to be stored
  int a,b;//indicators that helps not to store preceeding zeros
  while((digit=fgetc(stdin))!=EOF){
    if(digit=='\n'){
      if(len(&head1)==0){
        insert_end(&head1,&last1,0);//if the given number is 0
      }
      if(len(&head2)==0){
        insert_end(&head2,&last2,0);//if the given number is 0
      }
      a=0;
      b=0;
      selection=1;
      comparision(&head1,&head2);
      empty(&head1,&last1);//vacates the doubly linked list
      empty(&head2,&last2);
      printf("\n");
    }
    else if(digit==' '){

      selection=2;
    }
    else{
      if (selection==1)
      { //making sure that preceeding zeros are not being stored
        if ((digit-'0')!=0){
          a=1;
        }
       if (a==1){
        insert_end(&head1,&last1,digit-'0');
      }

      }
      if (selection==2)
      { if((digit-'0')!=0){
          b=1;
        }
        if (b==1){
          insert_end(&head2,&last2,digit-'0');
        }
      }

    }
  }
  return(0);
}
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
void comparision(struct node **head1,struct node **head2){
   //if they have different lengths
  if(len(head1)>len(head2)){
    printf("1");
    return;
  }
  else if(len(head1)<len(head2)){
    printf("0");
    return;
  }
  //if they have same lengths of linked lists
  else{
    struct node*temp1=*head1;
    struct node*temp2=*head2;
    while(temp1!=NULL){
      if((temp1->data)>(temp2->data)){
        printf("1");//first number is greater than second
        return;
      }
      else if((temp1->data)<(temp2->data)){
        printf("0");//second number is greater than first
        return;
      }
      else{
        //if above cases arent satisfied,check with the next digits 
      temp1=temp1->next;
      temp2=temp2->next;
      }
    }
  }
  printf("1");//if it reaches here, both numbers are equal
}
