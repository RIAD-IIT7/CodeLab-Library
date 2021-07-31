///                             Bismillahi-r-Rahmani-r-Rahim
///                                     RhIeyAaD
///                                 IIT-7th Batch,JU

#include<bits/stdc++.h>
#define pfl1(a)         printf("%lld\n", a)
#define sfl1(a)         scanf("%lld", &a)
#define sfl2(a,b)       scanf("%lld %lld", &a, &b)
#define sfl3(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define ll              long long int
#define MAX             INT_MAX
#define pb(x)           push_back(x)
#define fr(i,n)         for(i=0;i<n;i++)
#define rep(i,n)        for(i=1;i<=n;i++)
#define mem(x,n)        memset(x,n,sizeof(x))
#define maxx(a,b,c)     max(a,max(b,c))
#define ans_int(t,c)    printf("Case %d: %d\n",t,c);
#define ans(t,c)        printf("Case %lld: %lld\n",t,c);
#define ans(t)          printf("Case %lld: ",t);
#define pii             pair<int,int>
#define ff              first
#define ss              second
using namespace std;
ll tree[999999],tr[999999],lazy[999999];

void build(ll in,ll L,ll R)
{
  if(L==R)
  {
      tree[in]=tr[L];
      return;
  }
  ll mid=(L+R)/2;
  build(in*2,L,mid);
  build(in*2+1,mid+1,R);
  //tree[in]=tree[in*2]+tree[in*2+1];
  tree[in]=min(tree[in*2],tree[in*2+1]);
}
void lazy_update (ll in,ll L,ll R,ll x,ll y,ll val)
{
    if(x>y)return;

    if(lazy[in]!=0)
    {
        tree[in]+=lazy[in];
        if(L!=R)
        {
            lazy[in*2]+=lazy[in];
            lazy[in*2+1]+=lazy[in];
        }
        lazy[in]=0;
    }

    if(x>R || y<L)return;
    if(x<=L && y>=R)
    {
        tree[in]+=val;
        if(L!=R)
        {
            lazy[in*2]+=val;
            lazy[in*2+1]+=val;
        }
        return;
    }
    ll mid=(L+R)/2;
    lazy_update(in*2,L,mid,x,y,val);
    lazy_update(in*2+1,mid+1,R,x,y,val);

    tree[in]=tree[in*2]+tree[in*2+1];
}
ll lazy_query(ll in,ll L,ll R,ll x,ll y)
{
    if(x>y)return 0;
    if(lazy[in]!=0)
    {
        tree[in]+=lazy[in];
        if(L!=R)
        {
            lazy[in*2]+=lazy[in];
            lazy[in*2+1]+=lazy[in];
        }
        lazy[in]=0;
    }
    if(x>R || y<L)return 0;
    if(x<=L && y>=R)
        return tree[in];

    ll p,q,mid=(L+R)/2;
    p=lazy_query(in*2,L,mid,x,y);
    q=lazy_query(in*2+1,mid+1,R,x,y);

    return p+q;
}
void update(ll in,ll L,ll R,ll pos,ll val)
{
    if(pos>R||L>pos)return;
    if(L==R&&pos==L)
    {
        tree[in]+=val;
        return;
    }
    ll mid=(L+R)/2;
    update(in*2,L,mid,pos,val);
    update(in*2+1,mid+1,R,pos,val);
    tree[in]=tree[in*2]+tree[in*2+1];
}

ll query(ll L,ll R,ll in,ll i,ll j)
{
    if(j<L||i>R)return MAX;
        //return 0;
    if(L>=i&&j>=R)return tree[in];
    ll p,q,mid=(L+R)/2;
    p=query(L,mid,in*2,i,j);
    q=query(mid+1,R,in*2+1,i,j);
    //return p+q;
    return min(p,q);
}

int main()
{
    ll n,a,b,c=0,d,diff,e,f,g,i,j,k,l,m,in,mod,loc,p,q,r,u,val,w,t,tc,sz,lo,hi,mid,mn=MAX,mx=0,sum=0,ans=0;
    cin>>n;
    rep(i,n)
    cin>>tr[i];
    build(1,1,n);
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        cout<<query(1,n,1,a+1,b+1)<<endl;
    }
//    while(1)
//    {
//        cin>>a>>b>>c;
//        lazy_update(1,1,n,a,b,c);
//        cin>>a>>b;
//        cout<<lazy_query(1,n,1,a,b)<<endl;
//    }
  return 0;
}

/// 5 1 2 3 4 5
