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
#define MOD             10000007
#define p6              1000007
#define n6              999999
#define PI              2*acos(0.0)
#define hi              printf("hi\n")
#define N               n6

 ll x[N],y[N];
 char s[N];
// map <string,int> mp;
// vector<ll>v;
long long binarysearch(long long low,long long high,long long key)
{
    if(low>high)return -1;
    long long mid=(low+high)/2;
    if(x[mid]==key)return mid;
    else if(key>x[mid])return binarysearch(mid+1,high,key);
    else return binarysearch(low,mid-1,key);

}
ll nCr(ll n,ll r)
{
    ll &ret=dp[n][r];
    if(~ret)return ret;
    if(n==r)return ret=1;
    if(r==1)return ret=n;
    return ret=nCr(n-1,r)+nCr(n-1,r-1);
}
long long C(int n, int r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
int div(char a[],int x)
{
    int l=strlen(a),y=0;
    for(int i=0;i<l;i++){
        y=(a[i]-48 + y*10)%x;
    }
    return y;
}
long long factorial(long long n)
{
    if(n==1)return 1;
    return n*factorial(n-1);

}
ll binary(ll n)
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
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
long long power(long long a,long long b)
{
    int i;
    long long s=1;
    for(i=1;i<=b;i++)s*=a;
    return s;
}
void Sieve(int n)
{
    bool prime[n+5];
    mem(prime,1);
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
//    for (int p=2; p<=n; p++)
//       if (prime[p])
//          cout << p << " ";
}
ll bigmod(ll n,ll p)
{
    if(p==0)return 1;
    ll x=bigmod(n,p/2);
    x=(x*x)%MOD;
    if(p%2)x=(x*n)%MOD;
    return x;
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
int main()
{
    long long int a,b,x,c,d,m,p,q,r,z,n,sum,l,t,i,j,k;
    string s="MAN";
    permutation(s,0,2);

    return 0;
}
