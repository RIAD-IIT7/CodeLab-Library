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
#define N               1000002 ///10^6->6 zero after 1 **

/// Why Sparse Table??

/// Sparse Table provides RMQ query in O(1)!!

ll st[22][N],x[N],logs[N];
string s,S;
vector<ll>v;
//bitset<N>B;
//map <ll,ll> mp;
void precal_RMQ(ll n)/// 0 based indexing
{
    ll i,j,k;
//    log_n = log2(n); /// 2^log_n = n
//    logs[1]=0;
//    for(i=2;i<=n;i++)logs[i]= logs[i/2]+1; /// 2^logs[n] = n;
    for(i=0;i<n;i++)st[0][i]=x[i];

    for(i=1; (1<<i) <n; i++)
    {
        for(j=0; j+(1<<i)<=n; j++)  /// 1<<i = current_len
        {
            st[i][j]=min(st[i-1][j], st[i-1][j + (1<<i-1)]); /// For RMQ
            //st[i][j]=st[i-1][j] + st[i-1][j + (1<<i-1)]]; /// for Range Sum Queries
        }
    }
}
ll query_min(ll l, ll r)
{
    ll pow = log2(r-l+1);
    return min(st[pow][l], st[pow][r-(1<<pow)+1]);
}
//ll query_sum(ll l,ll r)
//{
//    ll i,j,pow,len,sum=0;
//    pow=log2(r-l+1);
//    for(i=pow;i>=0;i--)
//    {
//        if(1<<i <= r-l+1)
//        {
//            sum+=st[i][l];
//            l+=1<<i;    /// change starting index to next_L
//            //debug(i,1<<i, l,sum)
//        }
//    }
//    return sum;
//}
int main()
{
    ll n,q,l,r,i;
    cin>>n;
    fr(i,n)cin>>x[i];
    precal_RMQ(n);

    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        // l--, r--;
        cout<<query_min(l,r)<<endl;
    }
    return 0;
}

/*
10
1 2 3 4 5 6 7 8 9 0
99
1 2

*/
/// Check for constraint 0 or 1?
/// Division MOD needs BigMod(a,n-2)
/// long long or double? sqrt or division will work fine??
/// sort(begin(v), end(v), [] (int a, int b) { return a > b; });    /// Lambda Function for manual Sort
