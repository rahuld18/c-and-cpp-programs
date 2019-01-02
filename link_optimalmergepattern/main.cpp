/*#include<iostream>
using namespace std;
struct bstnode{
int data;
bstnode* left;
bstnode* right;                                               binary serarch tree

};

bstnode* Getnewnode(int data)
{
   bstnode* newnode=new bstnode();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;


}
bstnode* inser(bstnode *root,int data)
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
bstnode* rose(bstnode *root)
  {

     if(root==NULL)
     {

     }

        else if(root->left!=NULL)
        {


        cout<<root->left<<endl;
        rose(root->left);}
     else if(root->right)
     {
         cout<<root->right<<endl;
         rose(root->right);
     }



  }
int main()
{
  bstnode* root=NULL;
  root=inser(root,15);
   root=inser(root,10);
   root=inser(root,9);
   root=inser(root,69);
/*
  while(root->right!=NULL || root->left!=NULL)
  {if(root!=NULL)
     cout<<root->data<<endl;

    if(root->left!=NULL)
    {

     root=root->left;
    cout<<root->data<<endl;
    }
    if(root->right!=NULL)
    {
        root=root->right;
       cout<<root->data<<endl;

   }

  }
  *//*
rose(root);

return 0;


}

*//*





optimal merge pattern




#include<iostream>
using namespace std;
int main()
{
int i,k,a[10],c[10],n,l;
cout<<"Enter the no. of elements\t";
cin>>n;cout<<"\nEnter the sorted elments for optimal merge pattern";
for(i=0;i<n;i++)
    {cout<<"\t";cin>>a[i];}
i=0;k=0;
c[k]=a[i]+a[i+1];
i=2;while(i<n)
{k++;
if((c[k-1]+a[i])<=(a[i]+a[i+1]))
    {c[k]=c[k-1]+a[i];}
else{c[k]=a[i]+a[i+1];i=i+2;
while(i<n)

{ k++;if((c[k-1]+a[i])<=(c[k-2]+a[i])){c[k]=c[k-1]+a[i];}else{c[k]=c[k-2]+a[i];}i++;}}i++;}k++;c[k]=c[k-1]+c[k-2];cout<<"\n\nThe optimal sum are as follows......\n\n";for(k=0;k<n-1;k++){cout<<c[k]<<"\t";}l=0;for(k=0;k<n-1;k++){l=l+c[k];}cout<<"\n\n The external path length is ......"<<l;
}

*/

