#include<bits/stdc++.h>
int c=0;
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
node* newN(int x)
{
    node *tm=new node();
    tm->data=x;
    tm->left=NULL;
    tm->right=NULL;

}
node* Ins(int x,node *tt)
{
    if(tt==NULL)
    {
        tt=newN(x);
        return tt;
    }
    else if(tt->data>=x)
    {
        tt->left=Ins(x,tt->left);
    }
    else  tt->right=Ins(x,tt->right);
    return tt;
}
void show(node *root)
{
    if(root==NULL)return ;
    show(root->left);
    cout<<root->data<<' ';
    show(root->right);
}
int HEIGHT(node *root)
{
    if(root->left==NULL && root->right==NULL)
    {
        c++;
        return 0;
    }
    if(root->left != NULL) return 1+HEIGHT(root->left);
    if(root->right != NULL) return 1+HEIGHT(root->right);

}
int main()
{
    int x,n,i;
    node *root=NULL;
    cin>>n;
    while(n--)
    {
        cin>>x;
        root=Ins(x,root);
    }
    show(root);
    n=HEIGHT(root);
    cout<<n/c;
    return 0;
}
