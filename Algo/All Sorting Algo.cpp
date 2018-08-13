#include<bits/stdc++.h>
#define pfl1(a) printf("%lld\n", a)
#define sfl1(a) scanf("%lld", &a)
#define sfl2(a,b) scanf("%lld %lld", &a, &b)
#define sfl3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define ll long long int
//#define for(i,n) for(i=0;i<n;i++)
using namespace std;
int x[999999];
//char s,s1[999999],s2[999999];
void merge_sort(int l,int h)
{
    if(l==h)return;
    int m=(l+h)/2;
    merge_sort(l,m);
    merge_sort(m+1,h);
    int i,j,k,temp[99999];
    for(i=l,k=l,j=m+1;k<=h;k++)
    {
        if(i>m)temp[k]=x[j++];
        else if(j>h)temp[k]=x[i++];
        else if(x[i]<x[j])temp[k]=x[i++];
        else temp[k]=x[j++];
    }
    for(i=l;i<=h;i++)
        x[i]=temp[i];
}
void insert_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=a[i];
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
//void quick(int l,int h)
//{
//
//}
//void quicksrot(int l,int h)
//{
//    if(l<h)int q=parti(l,h);
//    quick(l,q-1);
//    quick(q+1,h);
//}
void insertion_sort(int n)
{
    for(int i=1;i<n;i++)
    {
        int key=x[i];
        int j=i-1;
        while(j>=0&&key<x[j])
            {
                x[j+1]=x[j];
                j--;
            }
        x[j+1]=key;
    }
}
int main()
{
     int a,b,c,d,e,i,j,k,l,m,n,p,q,r,t,u,v,w,z,sum;
    cout<<"Enter digit numbers:\n";
    cin>>n;
    for(i=0;i<n;i++)
    {
        x[i]=rand();
        cout<<x[i]<<endl;
    }
    cout<<endl;

   // insert_sort(x,n);
  //  merge_sort(0,n-1);
  insertion_sort(n-1);

    for(i=0;i<n;i++)cout<<i+1<<". "<<x[i]<<endl;;

    return 0;
}





