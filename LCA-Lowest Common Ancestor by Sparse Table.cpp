/*
                                Bismillahi-r-Rahmani-r-Rahim
                                        RhIeyAaD
                                    IIT-7th Batch,JU
*/
#include<bits/stdc++.h>
using namespace std;

#define debug(args...){ string _s = #args;replace(_s.begin(),_s.end(),',', ' ');stringstream _ss(_s);istream_iterator<string>_it(_ss);err(_it, args);} cout<<endl;
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}

#define ll              long long int
#define MAX             2134567891
#define pf(a)           printf("%lld", a)
#define sf(a)           scanf("%lld", &a)
#define sf2(a,b)        scanf("%lld %lld", &a, &b)
#define fr(i,n)         for(i=0;i<n;i++)
#define rep(i,n)        for(i=1;i<=n;i++)
#define rev(i,a,n)      for(i=n;i>=a;i--)
#define FOR(i,a,n)      for(i=a;i<=n;i++)
#define ALL(n)          n.begin(),n.end()
#define mem(x,n)        memset(x,n,sizeof(x))
#define TC(t)           printf("Case %lld: ",t)
#define ans(t,c)        printf("Case %lld: %lld\n",t,c)
#define SETP(n)         cout<<setprecision(n)<<fixed
#define READ            freopen("F:\\Project\\Test_Case.txt","r",stdin)
#define WRITE           freopen("F:\\Project\\Output_Test.txt","w",stdout)
#define IO              ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define PAIR            pair<ll,ll>
#define MP              make_pair
#define pb              push_back
#define eb              emplace_back
#define ff              first
#define ss              second
#define NL              printf("\n");
#define bug(a)          cout<<#a<<" "<<a<<" ";
#define hlw             printf("hlw\n");
#define NN              111
#define MOD             1000000007///10^9
#define N               1000007 ///10^6->6 zero after 1 **



ll x[N],depth[N],vis[N],nodes[N],n,k,last[N],st[22][N];
string s,S;
vector<ll>v[N];
//bitset<N>B;
//map <ll,ll> mp;
void walk(ll s, ll d)
{
    ll i, in;
    last[s]=k;
    nodes[k]=s;
    depth[k++]=d;

    fr(i,v[s].size())
    {
        in=v[s][i];
        if(vis[in])continue;
        vis[in]=1;
        walk(in,d+1);

        nodes[k]=s;
        depth[k++]=d;
    }
}
void sparse_table(ll n)/// 0 based indexing
{
    ll node_a,node_b,i,j,k;
    for(i=0;i<n;i++)st[0][i]=i; /// storing nodes, not values

    for(i=1; (1<<i) <n; i++)
    {
        for(j=0; j+(1<<i)<=n; j++)  /// 1<<i = current_len
        {
            node_a=st[i-1][j];
            node_b=st[i-1][j + (1<<i-1)];
            st[i][j] = depth[node_a]<=depth[node_b]? node_a:node_b; /// For RMQ
        }
    }
}
ll LCA(ll l,ll r)
{
    l=last[l],r=last[r];
    if(l>r)swap(l,r);
    ll pow = log2(r-l+1);
    ll a,b;
    a=st[pow][l];   b=st[pow][r-(1<<pow)+1];
    return nodes[depth[a]<=depth[b]? a:b];
}
int main()/// Remember strictly, this is a whole 0 based indexing
{
    //IO;
    //while(1)
    //READ;WRITE;
{
    ll a=0,b=0,c=0,d,e,f,g,i,j,l,m,p,q,r,u,w,t,tc=1,in,loc,val,sz,lo,hi,mid,mn=MAX,mx=0,sum=0,ans=0;
//cin>>tc;
rep(t,tc)
{
    mem(vis,0); k=0;
    cin>>n;
    fr(i,n+2)v[i].clear();
    rep(i,n)
    {
        cin>>l;
        fr(j,l)
        {
            cin>>a;
            v[i-1].pb(a-1);
            v[a-1].pb(i-1);
        }
    }

    vis[0]=1;
    walk(0,0);
    sparse_table(2*n-1);
    //fr(i,n*2-1){debug(i,depth[i],nodes[i],last[i])}

    cin>>q;
    cout<<"Case "<<t<<":\n";
    while(q--)
    {
        cin>>a>>b;
        cout<<LCA(a-1,b-1)+1<<endl;
    }
}
}
    return 0;
}

/*
7
0 1
1 3
0 2
2 4
2 5
4 6

*/
/// Check for constraint 0 or 1?
/// Division MOD needs BigMod(a,n-2)
/// long long or double? sqrt or division will work fine??
/// sort(begin(v), end(v), [] (int a, int b) { return a > b; });    /// Lambda Function for manual Sort
