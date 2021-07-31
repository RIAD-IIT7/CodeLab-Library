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
#define SETP(n)         setprecision(n)<<fixed
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
#define NN              100
#define N               p6

ll x[N],y[N],z[N],n,dp[11][2][2][100];
string s,S;
vector<ll>v;
//map <ll,ll> mp;
ll DP(ll pos,ll strt,ll sml,ll val)
{
    if(pos==n)return val;
    ll lim,i,j,k,&ret=dp[pos][strt][sml][val];
    if(ret!=-1)return ret;
    ret=0;
    lim=sml? 9 : v[pos];
    if(!strt)
    {
        for(i=0;i<=lim;i++)
            ret+=DP(pos+1,0,sml | i<v[pos],(i==0)+val);
    }
    else
    {
        for(i=1;i<=lim;i++)
            ret+=DP(pos+1,0,sml | i<v[pos],val);
        ret+=DP(pos+1,1,1,0);
    }
    return ret;
}
ll solve(ll p)
{
    if(p<0)return 0;
    if(p<9)return 1;
    ll a,b,c=0;
    v.clear();
    mem(dp,-1);
    while(p)
    {
        v.pb(p%10);
        p/=10;
    }
    reverse(ALL(v));
    n=v.size();
    return DP(0,1,0,0)+1;
}
int main()
{
    //IO;
    //while(1)
    //READ;WRITE;
{
    ll a=0,b=0,c=0,d,e,f,g,i,j,k,l,m,p,q,r,u,w,t,tc,in,mod,loc,diff,val,sz,lo,hi,mid,mn=MAX,mx=0,sum=0,ans=0;
    cin>>tc;
    rep(t,tc)
    {
        cin>>a>>b;
        if(a>b)swap(a,b);
        p=solve(a-1);
        q=solve(b);
      //  cout<<"p "<<p<<" q "<<q<<endl;
        T_C(t);
        cout<<q-p<<endl;
    }
}
    return 0;
}

/*
5
0 10
*/
/// Check for constraint 0 or 1?
/// long long or double? sqrt or division will work fine??
