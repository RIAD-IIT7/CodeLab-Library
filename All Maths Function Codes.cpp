/*
                                Bismillahi-r-Rahmani-r-Rahim
                                        RhIeyAaD
                                    IIT-7th Batch,JU
*/
#include<bits/stdc++.h>
//#include<iostream>
//#include<stdio.h>
//#include<string>
using namespace std;

#define pf              printf
#define sf              scanf
#define pf(a)           printf("%lld\n", a)
#define sf1(a)          scanf("%lld", &a)
#define sf2(a,b)        scanf("%lld %lld", &a, &b)
#define sf3(a,b,c)      scanf("%lld %lld %lld",&a,&b,&c)
#define line(a)         getline(cin,(a))
#define minn(a,b,c)     min(a,min(b,c))
//int fx[]={+1,-1,+0,+0};
//int fy[]={+0,+0,+1,-1};
//int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
#define ll              long long int
#define MAX             2134567891
#define pb(x)           push_back(x)
#define fr(i,n)         for(i=0;i<n;i++)
#define rep(i,n)        for(i=1;i<=n;i++)
#define mem(x,n)        memset(x,n,sizeof(x))
#define maxx(a,b,c)     max(a,max(b,c))
#define anst(t)         printf("Case %lld: ",t)
#define ans_int(t,c)    printf("Case %d: %d\n",t,c)
#define ans(t,c)        printf("Case %lld: %lld\n",t,c)
#define READ            freopen("F:\Project\\Test_Case.txt","r",stdin)
#define WRITE           freopen("F:\Project\\Test_Case.txt","w",stdout)
#define I_O             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define pii             pair<int,int>
#define m_p             make_pair
#define pb(a)           push_back(a)
#define ff              first
#define ss              second
#define p6              1000007
#define n6              999999
#define PI              2*acos(0.0)
#define hii             printf("hi\n")
#define N               n6

 ll x[N],y[N],phi[N],dp[10][10],fact[N];
 char s[N];
// map <string,int> mp;
// vector<ll>v;
/// if n=a1^c1 * a2^c2 * a3*c3 then number of divisors(NOD) of n is (a1+1)*(a2+1*(a3+1)
/// SOD(N)=(p1^0+p1^1+p1^2...p1^3)×(p2^0+p2^+p2^2..)×...(pk^0+pk^1+pk^2...pk^k)
/// LCMSUM(N) = (n/2)*(sumOf[phi(i)*i]+1) =LCM(1,N)+LCM(2,N)+....+LCM(N,N)
/// sum of coprime numbers(N) = [phi(N)*N] / 2

ll spf[N]; vector<ll>primes;
void sieve() ///with SPF Calculation
{
    for(int i = 2; i < N; i++)
    {
        if (spf[i] == 0) spf[i] = i, primes.push_back(i);

        int sz = primes.size();
        for (int j=0; j<sz && i*primes[j]<N && primes[j]<=spf[i]; j++)
        {
            spf[i * primes[j]] = primes[j];
        }
    }
}

ll nCr(ll n,ll r) /// nCr DP for n*r <= 1e7
{
    ll &ret=dp[n][r];
    if(~ret)return ret;
    if(n==r)return ret=1;
    if(r==1)return ret=n;
    return ret=nCr(n-1,r)+nCr(n-1,r-1);
}
ll ncr(ll n,ll r)   /// time and space saving
{
    if(r>n-r)r=n-r;
    ll i,ans=1;
    fr(i,r)
    ans=ans*(n-i)/(i+1);
    return ans;
}

ll bigmod(ll n,ll p,ll MOD)        /// finds n ^ p % MOD
{
    if(p==0)return 1;
    ll x=bigmod(n,p/2,MOD);
    x=(x*x)%MOD;
    if(p%2)x=(x*n)%MOD;
    return x;
}
ll precal_nCr(ll N, ll r) /// If inputs are larger and MOD required
{
    /// Precal Starts Here
    fact[1] = 1;
    for(ll i=2; i<N; i++)  fact[i] = (i*fact[i-1])%MOD;
    invfact[N-1] = bigmod(fact[N-1], MOD-2, MOD);
    for (ll i=N-2; i>=0; i--)  invfact[i] = (invfact[i+1]*(i+1))%MOD;
    /// Precal Ends Here

    if (r<0 || r>n) return 0;
    return (fact[n]*(invfact[r]*invfact[n-r])%MOD)%MOD;
}

void Sieve(long long n)
{
    bool prime[n+5];
    mem(prime,1);
    for (long long p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

void permutation(string s,int i,int n)
{
    if(i==n){cout<<s<<endl;return ;}
    for(int j=i;j<=n;j++)
    {
        swap(s[i],s[j]);
        permutation(s,i+1,n);
    }
}
//ll mod_inverse(ll a,ll mod) /// Mod Inverese(when divisors needs to be mod) is equal to pow(a,MOD-2)
//{
//    return bigmod(a,mod-2,mod);
//}
void mod_inverse(ll m)/// calculate Mod_Inverse(x) for every number a=[1 to m-1]
                      /// sucj that (a*x) %m = 1
{
    inv[1] = 1;
    for(int i = 2; i < m; ++i)
        inv[i] = m - (m/i) * inv[m%i] % m;
}

void allPossibleSubset(int arr[],int n)
{
	for(ll mask = 0; mask < (1 << n); mask++) /// (1<<n) means pow(2,n)
    {
        ll sum_of_this_subset = 0;
        for(int i = 0; i < n; i++)
        {
            if(mask & (1 << i)) /// If i'th bit of mask is set, then take this
            {
                sum_of_this_subset += a[i];
            }
        }
    }
}
/// Find numbers of co-prime of N which are less than N
///  Precomputation of phi[] numbers
void totient()
{
    ll i,j,k;
    for(i=1;i<=N;i++)phi[i]=i;
    for(i=2;i<=N;i++)
    {
        if(phi[i]==i)
        {
            for(j=i;j<=N;j+=i)
            {
                phi[j]= (phi[j]*(i-1))/i;
            }
        }
    }
}
/// Find eulerphi for any numbers with prime pre-calculated
int eulerPhi ( int n ) {
    int res = n;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
            }
            sqrtn = sqrt ( n );
            res /= prime[i];
            res *= prime[i] - 1;
        }
    }
    if ( n != 1 ) {
        res /= n;
        res *= n - 1;
    }
    return res;
}
ll binarySearch(ll lo,ll hi,ll key)
{
    while(lo<=hi)
    {
        ll mid=(lo+hi)/2;
        if(x[mid]==key)
        {
            ll ans=mid;
            lo=mid+1;
        }
        else
            hi=mid-1;
    }
}


/// Division in String
int div(char a[],int x)
{
    int l=strlen(a),y=0;
    for(int i=0;i<l;i++){
        y=(a[i]-48 + y*10)%x;
    }
    return y;
}

/// Decimal to Binary
ll toBinary(ll n)
{
 ll r,b = 0, i = 1;

    while(n) {
        r=n%2;
        b=b+(r*i);
        n=n/2;
        i=i*10;
    }
    return b;
}

/// faster GCD
int gcd(int a,int b)
{
    while(b)
        a %= b, swap(a, b);
    return a;
}
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

/// Inclusion-Exclusion
ll fun()
{
    ll a=0,b,c=0,cnt,i,j,k,m,n;
    cnt=pow(2,m);
    rep(i,cnt-1)
    {
       a=1;
       fr(j,m)
       {
           if(i & 1<<j)
            a=(a*x[j])/__gcd(a,x[j]);
       }
       a=n/a;
       b=__builtin_popcountll(i);
       if(b%2)c+=a;
       else c-=a;
    }
    return n-c;
}

/// Disjoint Set Union DSU
ll find_set(ll ch)
{
    if(par[ch]==ch)return ch;
    return par[ch]=find_set(par[ch]);
}
void union_set(ll a,ll b)
{
    ll pa,pb;
    pa=find_set(a);
    pb=find_set(b);
    if(pa==pb)return ;

    if(sz[pa]<sz[pb])
        swap(pa,pb);
    par[pb]=pa;
    sz[pa]+=sz[pb];

}
/// Segmented Seive
// Returns number of primes between segment [a,b]
int segmentedSieve ( int a, int b ) {
    if ( a == 1 ) a++;
    int sqrtn = sqrt ( b );
    memset ( arr, 0, sizeof arr ); // Make all index of arr 0.

    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        int p = prime[i];
        int j = p * p;
        // If j is smaller than a, then shift it inside of segment [a,b]
        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;
        for ( ; j <= b; j += p ) {
            arr[j-a] = 1; // mark them as not prime
        }
    }
    int res = 0;
    for ( int i = a; i <= b; i++ )
        if ( arr[i-a] == 0 ) res++;

    return res;
}
/// Bitwise Sieve
const int MAX = 100000000;  // 10^8
const int LMT =     10000;  // sqrt(MAX)
int _c[(MAX>>6)+1];
vector<int> primes;
#define IsComp(n)  (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
void prime_sieve() {
    for (int i = 3; i <= LMT; i += 2)
        if (!IsComp(i))
            for (int j = i*i; j <= MAX; j += i+i)
                SetComp(j);

    primes.push_back(2);
    for (int i=3; i <= MAX; i += 2)
        if (!IsComp(i))
            primes.push_back(i);
}
bool is_prime(int n) {
    if (n < 2 || n % 2 == 0) return false;
    return ! IsComp(n);
}
/*
Fermat's Little Theorem:
If n is a prime number, then for every a, 1 < a < n-1,

an-1 ≡ 1 (mod n)
 OR
an-1 % n = 1
*/
double FindAngle(double Ax,double Ay,double Bx,double By,double Cx,double Cy) /// Takes 3/4 Points for 2 diff lines
{
    double a1,a2,b1,b2,u,v,p,ang;
    a1=Ax-Bx;   b1=Ay-By;
    a2=Cx-Bx;   b2=Cy-By;

    p=a1*a2+b1*b2;
    u=sqrt(a1*a1+b1*b1);
    v=sqrt(a2*a2+b2*b2);

    ang = acos(p/(u*v));
    return (ang*180)/acos(0.0);
}

int main()
{
    long long int a,b,x,c,d,m,p,q,r,z,n,sum,l,t,i,j,k;
//    string s="MAN";
//    permutation(s,0,2);

    return 0;
}
