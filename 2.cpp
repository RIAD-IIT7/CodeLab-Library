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
#define PF(a)           cout<<a<<endl;
#define pf(a)           printf("%lld", a);
#define sf(a)           scanf("%lld", &a);
#define fr(i,n)         for(i=0;i<n;i++)
#define rep(i,n)        for(i=1;i<=n;i++)
#define rev(i,a,n)      for(i=n;i>=a;i--)
#define FOR(i,a,n)      for(i=a;i<=n;i++)
#define ALL(n)          n.begin(),n.end()
#define mem(x,n)        memset(x,n,sizeof(x));
#define TC(t)           printf("Case %lld: ",t);
#define ans(t,c)        printf("Case %lld: %lld\n",t,c);
#define SETP(n)         cout<<setprecision(n)<<fixed;
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
#define hii             printf("hii\n");
#define NN              111
#define MOD             (ll)1e9+7   /// 10^9+7
#define N               (ll)1e6+7   ///10^6->6 zero after 1 **



ll x[N],y[N],z[N],n;
string s,S;
vector<ll>v;
//bitset<N>B;
//map <ll,ll> mp;

int main()
{
    //IO;
    //while(1)
    //READ;WRITE;
{
    ll a=0,b=0,c=0,d,e,f,g,i,j,k,l,m,p,q,r,u,w,t,tc=1;
    ll in,loc,val,sz,lo,hi,mid,mn=MAX,mx=0,sum=0,ans=0;

//cin>>tc;
rep(t,tc)
{


}
}
    return 0;
}

/*

*/
/// Division MOD needs BigMod(a,n-2)
/// long long or double? sqrt or division will work fine??
/// sort(begin(v), end(v), [] (int a, int b) { return a > b; }); /// Lambda Function for manual Sort
/// bool cmp(PAIR a, PAIR b){return a.ff>b.ff;}
/// priority_queue<ll, vector<ll>, greater<ll> > pq;
