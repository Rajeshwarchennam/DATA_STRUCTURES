#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
  int data;
  struct node*left;
  struct node*right;
  struct node *parent;
};
struct node *newnode(int n){
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->data=n;
  temp->left=NULL;
  temp->right=NULL;
  temp->parent=NULL;
}
struct node*search(struct node *root,int n){
  if (root==NULL || root->data==n){
    return root;
  }
  else if (root->data>n){
    search(root->left,n);
  }
  else{
    search(root->right,n);
  }
}
struct node* insert (struct node *root,int n){
  if (root==NULL){
    return newnode(n);
  }
  if (root->data>n){
    root->left=insert(root->left,n);
  }
  else if(root->data<n){
    root->right=insert(root->right,n);
  }
  return root;
}
void inorder(struct node*root){
  if (root!=NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
}
struct node*left_rotate(struct node *root,int n){
  if (root==NULL){
    return NULL;
  }
  else if (root->data>n){
    root->left=left_rotate(root->left,n);
  }
  else if (root->data<n){
    root->right=left_rotate(root->right,n);
  }
  else{
    if (root->right==NULL){
      return root;
    }
    else{
      struct node*temp;
      temp=root->right;
      temp->parent=root->parent;
      root->parent=temp;
      root->right=temp->left;
      if (temp->left!=NULL){
        temp->left->parent=root;
      }
      temp->left=root;
      return temp;
    }
  }
}
struct node *right_rotate(struct node *root,int n){
  if(root==NULL){
    return NULL;
  }
  else if (root->data>n){
    root->left=right_rotate(root->left,n);
  }
  else if (root->data<n){
    root->right=right_rotate(root->right,n);
  }
  else {
    if (root->left==NULL){
      return root;
    }
    else{
      struct node*temp=root->left;
      temp->parent=root->parent;
      root->parent=temp;
      root->left=temp->right;
      if (temp->right!=NULL){
        temp->right->parent=root;
      }
      temp->right=root;
      return temp;
    }
  }
}
int height(struct node *node){
  if (node==NULL){
    return 0;
  }
  else {
    int l=height(node->left);
    int r=height(node->right);
    if (l>r){
      return l+1;
    }
    else {
      return r+1;
    }
  }
}
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1){
      printf("%d ", root->data);
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
void printlevelorder(struct node*root){
  int h=height(root);
  int i;
  for(i=1;i<=h;i++){
    printGivenLevel(root,i);
    printf("\n");
  }
}
void printGivenLevelspiral(struct node *root,int level, bool l){
  if (root==NULL){
    return;
  }
  if (level==1){
    printf("%d ",root->data);
  }
  else if (level>1){
    if (l){
      printGivenLevelspiral(root->left,level-1,l);
      printGivenLevelspiral(root->right,level-1,l);
    }
    else{
      printGivenLevelspiral(root->right,level-1,l);
      printGivenLevelspiral(root->left,level-1,l);
    }
  }
}
void printspiral(struct node *root){
  int h =height(root);
  int i;
  bool l=false;
  for (i=1;i<=h;i++){
    printGivenLevelspiral(root,i,l);
    l=!l;
  }
}
int count(struct node *root){
  if (root==NULL){
    return 0;
  }
  else {
    int l=count(root->left);
    int r=count(root->right);
    return l+r+1;
  }
}
int max(struct node *root){//max of any tree
  if (root==NULL){
    return 0;
  }
  int a=root->data;
  int b=max(root->left);
  int c=max(root->right);
  if (b>a){
    a=b;
  }
  if (c>a){
    a=c;
  }
  return a;
}
int max_bst(struct node *root){
  if (root==NULL){
    return 0;
  }
  while(root->right!=NULL){
    root=root->right;
  }
  return root->data;
}
void leafnode(struct node *root){
  if (root==NULL){
    return;
  }
  if (root->left==NULL && root->right==NULL){
    printf("%d\n ",root->data);
  }
  if (root->left!=NULL){
    leafnode(root->left);
  }
  if (root->right!=NULL){
    leafnode(root->right);
  }
}
int main(){
  struct node *root=NULL;
  root=insert(root,0);
  insert(root,1);
  insert(root,5);
  insert(root,3);
  insert(root,1);
  insert(root,3);
  insert(root,-1);
  insert(root,-3);
  insert(root,1);
  leafnode(root);
  //left_rotate(root,3);
  //inorder(root);
  //printf("%d\n",max_bst(root));
  return 0;
}
