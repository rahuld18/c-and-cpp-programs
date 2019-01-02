#include<iostream>
using namespace std;
struct bstnode{
int data;
bstnode* left;
bstnode* right;

};

bstnode Getnewnode(int data)
{
   bstnode* newnode=new bstnode();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;


}
bstnode inser(bstnode *root,int data)
{
    if(root==NULL)
    {
        root=Getnewnode(data);
    }
    else if(data<=root->data)
    {
        root->left=inser(root->left,data);
    }
    else
        root->right=inser(root->right,data);
    return root;

}
void main()
{
  bstnode* root=NULL;
  inser(root,15);
   inser(root,10);



}
