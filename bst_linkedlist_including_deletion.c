/* Binary search tree with arbitrary length
 ee16btech11003  Chennam Rajeshwar*/
#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node*next;
  struct node*prev;
};
struct bst_node // declaring binary search tree
{
  struct node *head;// to create linked list of given digits of number
  struct bst_node *left;
  struct bst_node *right;
  struct bst_node *parent;
};
struct node* create_node(int n);
void insert_end(struct node** head_ref,struct node **last,int n);
void print (struct node* head_ref);
struct bst_node * newnode(struct node *head);
int len(struct node* head_ref);
int comparision(struct node *head1,struct node *head2);
struct bst_node *insert(struct bst_node* node,struct node*head);
//prints elements in preorder traversal way
void PREORDER(struct bst_node* node);
void empty(struct node **head_ref);
void empty_bst(struct bst_node *root);
//finds if number is there in the bst or not and gives it position
void search(struct bst_node *node,struct node *head,struct node *temp,struct node *temp_last1);
struct bst_node *delete(struct bst_node* root,struct node *head);
void find(struct bst_node *node, struct node *head,struct bst_node **temp);
void succesor(struct bst_node *root, struct node *head);
int main(){
  struct node*temp_head=NULL;
  struct node*temp_last=NULL;
  struct bst_node*root=NULL;
  char digit;
  int condition,a;
  while((digit=fgetc(stdin))!=EOF){
    if (digit=='N'){

      a=0;// used to sanitize preceeding zeros

      empty_bst(root);
      root=NULL;
      condition=0;
    }
    else if(digit=='P'){
      condition=1;
    }
    else if(digit=='S'){
      condition=2;
    }
    else if(digit=='>'){
      condition=3;
    }
    else if(digit=='+'){
      condition=4;
    }
    else if(digit=='-'){
      condition=5;
    }
    else if(condition==0){
      if (digit==' '){
        if(temp_head!=NULL){
          if(root==NULL){
              a=0;//for sanitizing initial zeros
              root=insert(root,temp_head);
          }
          else if(root!=NULL){
            a=0;//for sanitizing initial zeros
            insert(root,temp_head);
          }
          temp_head=NULL;
        }
      }
      else if(digit=='\n'){
        if(temp_head!=NULL){
          if(root==NULL){
              a=0;//for sanitizing initial zeros
              root=insert(root,temp_head);
          }
          else if(root!=NULL){
            a=0;//for sanitizing initial zeros
            insert(root,temp_head);
          }
          temp_head=NULL;
        }
      }
      else{
        if ((digit-'0')!=0){
          a=1;// here starts taking digits by sanitizing initial zeros
        }
       if (a==1){
        insert_end(&temp_head,&temp_last,digit-'0');
       }
      }
    }
    else if (condition==1){
      if (digit=='\n'){
        PREORDER(root);
        printf("\n");
      }
    }
    else if(condition==2){
      if (digit==' '){
        a=0;//for sanitizing initial zeros
        temp_head=NULL;
      }
      else if (digit=='\n'){
        struct node *temp=NULL;
        struct node *temp_last1=NULL;
        search(root,temp_head,temp,temp_last1);
        empty(&temp_head);
        printf("\n");
      }
      else{
        if ((digit-'0')!=0){
          a=1;//for sanitizing initial zeros
        }
       if (a==1){
        insert_end(&temp_head,&temp_last,digit-'0');
      }
      }
    }
    else if(condition==3){
      if (digit==' '){
        a=0;
        temp_head=NULL;
      }
      else if (digit=='\n'){
        if(root==NULL){
          empty(&temp_head);
          printf("-1\n");
        }
        else{
          succesor(root,temp_head);
          empty(&temp_head);
          printf("\n");
        }

      }
      else {
        if ((digit-'0')!=0){
          a=1;//for sanitizing initial zeros
        }
       if (a==1){
        insert_end(&temp_head,&temp_last,digit-'0');
      }
      }
    }
    else if (condition==4){
      if (digit==' '){
        a=0;
        temp_head=NULL;
      }
      else if (digit=='\n'){
        if (root==NULL){
          root=insert(root,temp_head);
        }
        else{
          insert(root,temp_head);
        }
        temp_head=NULL;
      }
      else{
        if ((digit-'0')!=0){
          a=1;//for sanitizing initial zeros
        }
       if (a==1){
        insert_end(&temp_head,&temp_last,digit-'0');
      }
      }
    }
    else if (condition==5){
      if (digit==' '){
        a=0;
        temp_head=NULL;
      }
      else if (digit=='\n'){
        if (root==NULL){
          empty(&temp_head);
          a=0;
        }
        else if (comparision(root->head,temp_head)==-1 && root->right==NULL && root->left==NULL){
          free(root);
          root=NULL;
          empty(&temp_head);
          a=0;
        }
        else{
          root=delete(root,temp_head);
          empty(&temp_head);
          a=0;
        }
      }
      else{
        if ((digit-'0')!=0){
          a=1;//for sanitizing initial zeros
        }
       if (a==1){
        insert_end(&temp_head,&temp_last,digit-'0');
      }
      }
    }
  }
  return 0;
}
struct node* create_node(int n){
  struct node* new_node=(struct node*)malloc(sizeof(struct node));
  new_node->data=n;
  new_node->next=NULL;
  new_node->prev=NULL;
  return new_node;
}
// used tail pointer in the end to reduce time complexity
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
//to print gives linked list
void print (struct node* head_ref){
  struct node*temp=head_ref;
  if (temp==NULL){
    return;
  }
  while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
  }
  printf(" ");
}
// returns a new bst
struct bst_node * newnode(struct node *head)
{
  struct bst_node*temp=(struct bst_node*)malloc(sizeof(struct bst_node));
  temp->head=head;
  temp->left=NULL;
  temp->right=NULL;
  temp->parent=NULL;
  return temp;
}
int len(struct node* head_ref){
  int length=0;
  struct node *temp=head_ref;
  while(temp!=NULL){
    length++;
    temp=temp->next;
  }
  return length;
}
// compares the numbers that are saved in two linked lists digit-wise
int comparision(struct node *head1,struct node *head2){
   //if they have different lengths
  if(len(head1)>len(head2)){
    return 1;
  }
  else if(len(head1)<len(head2)){
    return 0;
  }
  //if they have same lengths of linked lists
  else{
    struct node*temp1=head1;
    struct node*temp2=head2;
    while(temp1!=NULL){
      if((temp1->data)>(temp2->data)){
          return 1;
      }
      else if((temp1->data)<(temp2->data)){
          return 0;
      }
      else{
      temp1=temp1->next;
      temp2=temp2->next;
      }
    }
  }
  //if it reaches here, both numbers are equal
  return -1;
}
//inserts linked list in the binary search tree
struct bst_node *insert(struct bst_node* node,struct node*head)
{
  if (node==NULL) return newnode(head);
  if (comparision(head,node->head)==0)
  {
    struct bst_node* left_child=insert(node->left,head);
    node->left=left_child;
    left_child->parent=node;
  }
  if (comparision(head,node->head)==1)
  {
    struct bst_node* right_child=insert(node->right,head);
    node->right=right_child;
    right_child->parent=node;
  }
  return node;
}
// prints bst in preoreder traversal
void PREORDER(struct bst_node* node)
{
     if (node == NULL){
            return;
    }
     print(node->head);
     PREORDER(node->left);
     PREORDER(node->right);
}
//frees linked list
void empty(struct node **head_ref){
  struct node*temp=*head_ref;
  struct node* next;
  while(temp!=NULL){
    next=temp->next;
    free(temp);
    temp=next;
  }
  *head_ref=NULL;
}
//frees bst
void empty_bst(struct bst_node *root){
  if(root==NULL){
    return;
  }
    empty_bst(root->left);
    empty_bst(root->right);
    empty(&root->head);
    free(root);
}
// finds the path of a number in search tree if it is there in the tree
void search(struct bst_node *node,struct node *head,struct node *temp,struct node *temp_last1)
{
  if (node==NULL)
  {  empty(&temp);
     temp=create_node(-1);
     print(temp);
     empty(&temp);
     return;
  }
  else if (comparision(head,node->head)==-1)
  { print(temp);
    empty(&temp);
    return ;
  }
  else if (comparision(head,node->head)==0)
  { insert_end(&temp,&temp_last1,0);
    search(node->left,head,temp,temp_last1);
  }
  else if (comparision(head,node->head)==1)
  { insert_end(&temp,&temp_last1,1);
    search(node->right,head,temp,temp_last1);
  }
}
//replacing node by its succesor
struct bst_node *delete(struct bst_node* root,struct node *head){
  if (root==NULL){
    return root;
  }
  if (comparision(head,root->head)==0){
    //goes on searching for the node
    root->left=delete(root->left,head);
  }
  else if (comparision(head,root->head)==1){
    root->right=delete(root->right,head);
  }
  else{
    struct bst_node *temp;
    //if node doesnt have left left_child
    if (root->left==NULL){
      temp =root->right;
      if(root->right!= NULL){
      temp->parent=root->parent;
      }
      free(root);
      return temp;
    }
    // if the node doesnt have right right_child
    else if (root->right==NULL){
      temp=root->left;
      if(root->left!= NULL){
      temp->parent=root->parent;
      }
      free(root);
      return temp;
    }
    // if both childs are present find the minimum value in its right subtree and swap it with our node
    //SWAP WITH THE CURRENT NODES SUCCESOR
    temp=root->right;
    while(temp->left!=NULL){
      temp=temp->left;
    }
    root->head=temp->head;
    root->right=delete(root->right,temp->head);
  }
  return root;
}
void find(struct bst_node *node, struct node *head,struct bst_node **temp){
  if (node==NULL){
    *temp=NULL;
    return;
  }
  else if(comparision(head,node->head)==-1){
    *temp=node;
    return;
  }
  else if(comparision(head,node->head)==0){
    find(node->left,head,temp);
  }
  else if (comparision(head,node->head)==1){
    find(node->right,head,temp);
  }
}
void succesor(struct bst_node *root, struct node *head){
  struct bst_node*temp1=NULL;
  struct bst_node*temp=NULL;
  struct bst_node*temp2=NULL;
  find(root,head,&temp);
  int a=0;// its an indicator to tell if the given number is in bst or not
  // if the given number is not in bst add the number to the bst and delete it after finding succesor
  if (temp==NULL){
    insert(root,head);
    a=1;
    find(root,head,&temp);
  }
  if (temp->right != NULL){
    temp1=temp->right;
    while(temp1->left!=NULL){
      temp1=temp1->left;
    }
    print(temp1->head);
    return;
  }
  temp1=temp->parent;
  while(temp1!= NULL && temp==temp1->right){
    temp=temp1;
    temp1=temp1->parent;
  }
  if (a==1){
    root=delete(root,head);// this is to delete the node that we have added to find its succesor
  }
  if (temp1==NULL){
    printf("-1");
    return;
  }
  print(temp1->head);
}
