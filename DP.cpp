/*
                                Bismillahi-r-Rahmani-r-Rahim
                                        RhIeyAaD
                                    IIT-7th Batch,JU
*/
#include<bits/stdc++.h>
using namespace std;

#define pf(a)           printf("%lld\n", a)
#define sf(a)           scanf("%lld", &a)
#define line(a)         getline(cin,(a))
#define ll              long long int
#define MAX             2134567891
#define MID(l,r)        (l+r)>>1
#define fr(i,n)         for(i=0;i<n;i++)
#define rep(i,n)        for(i=1;i<=n;i++)
#define per(i,a,n)      for(i=n;i>=a;i--)
#define FOR(i,a,n)      for(i=a;i<=n;i++)
#define ALL(n)          n.begin(),n.end()
#define mem(x,n)        memset(x,n,sizeof(x))
#define T_C(t)          printf("Case %lld: ",t)
#define TC(t)           printf("Case %lld:\n",t)
#define ans(t,c)        printf("Case %lld: %lld\n",t,c)
#define SETP(n)         cout<<setprecision(n)<<fixed
#define READ            freopen("F:\\Project\\Test_Case.txt","r",stdin)
#define WRITE           freopen("F:\\Project\\Output_Test.txt","w",stdout)
#define IO              ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define PAIR            pair<ll,ll>
#define MP              make_pair
#define pb(a)           push_back(a)
#define ff              first
#define ss              second
#define MOD             1000000007///10^9
#define p6              1000007 ///10^6->6 zero after 1 **
#define hlw             printf("hlw\n");
#define SN              4*p6
#define NN              111
#define N               p6

ll x[N],ar[N],z[N],n;
string s,S;
vector<ll>v;
//map <ll,ll> mp;
///                                 Dynamic Programming
ll BP(ll n,ll r)
{
    ll i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=min(i,r);j++)
        {
            if(j==i||j==0)x[i][j]=1;
            else x[i][j]=x[i-1][j-1]+x[i-1][j];
        }
    }
    return x[n][r];
}

ll LCS(char p[],char q[],int a,int b)
{
    ///All loop will work through 1 to n/m here...
    int i,j,k;
    rep(i,a)
        x[i][0]=0;
    rep(i,b)
        x[0][i]=0;
    rep(i,a)
        rep(j,b)
        {
            if(p[i]==q[j])x[i][j]=x[i-1][j-1]+1;
            else x[i][j]=max(x[i][j-1],x[i-1][j]);
        }
    return x[a][b];
}

ll MatMul(int p[],int n)
{
    int m[n][n],s[n][n];
    int i,j,k,l,q;
    for(i=1;i<n;i++)
        m[i][i]=0;
    for(l=2;l<n;l++)
    {
        for(i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INF;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    return m[1][n-1];
}
ll LIS(ll n)
{
    ll i,a,in=0,st,en,mid,ans=-1;
    ar[1]=INT_MIN;
    rep(i,n)
    {
        a=x[i];
        if(in==0 || a>ar[in])
        {
            cout<<"Appending "<<a<<" in "<<1+in<<endl;
            ar[++in]=a;
        }
        else if(a<x[1])
            ar[1]=a;
        else
        {
            st=1,en=in;
            while(st<=en)
            {
                mid=(st+en)/2;
                if(ar[mid]<a)
                    st=mid+1;
                else en=mid-1;
            }
            ar[st]=a;
            cout<<mid<<" mid\n";
        }
        cout<<"i "<<i<<" a "<<a<<" in "<<in<<endl;
    }
    return in;
}

int main()
{
    //IO;
    while(1)
    //READ;WRITE;
{
    ll a=0,b=0,c=0,d,e,f,g,i,j,k,l,m,p,q,r,u,w,t,tc,in,mod,loc,diff,val,sz,lo,hi,mid,mn=MAX,mx=0,sum=0,ans=0;
    mem(ar,0);
    cin>>n;
    rep(i,n)cin>>x[i];
    cout<<LIS(n)<<endl;
}
    return 0;
}

/*
8
1 2 3 2 1 2 3 4

4
1 1 2 2

5
1 2 1 3 2
*/
/// Check for constraint 0 or 1?
/// long long or double? sqrt or division will work fine??
