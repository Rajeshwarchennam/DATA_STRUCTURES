#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;

};
struct node * newnode(int data)
{
  struct node*temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
void sort(struct node*root)
{
  if (root!=NULL)
  {
    sort(root->left);
    printf("%d\n",root->data);
    sort(root->right);
  }
}
struct node *insert(struct node* node,int a)
{
  if (node==NULL) return newnode(a);
  if (a<node->data)
  {
    node->left=insert(node->left,a);
  }
  if (a>node->data)
  {
    node->right=insert(node->right,a);
  }
  return node;
}

void search(struct node *node,int a)
{
  if (node==NULL)
  {
    printf("no\n");
    return;
  }
  if (node->data==a)
  {
    printf("yes %d exists\n",a);
  }
  if (node->data>a)
  {
    search(node->left,a);
  }
  if (node->data<a)
  {
    search(node->right,a);
  }

}
void empty_bst(struct node *root){
  if(root==NULL){
    return;
  }
  if (root!=NULL){
    empty_bst(root->left);
    empty_bst(root->right);
  }
  free(root);
}
int main()
{
  struct node*root =NULL;
  root=insert(root,3457889  );
  insert(root,1);
  insert(root,156);
  insert(root,167867);
  insert(root,1767878);
  struct node*root1=root;
  empty_bst(root);
  sort(root1);
  search(root,0);
  return 0;

}
