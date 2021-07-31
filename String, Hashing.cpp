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

ll x[N],y[N],z[N],n;
string s,S;
vector<ll>v;
//map <ll,ll> mp;

/// prefix function of string "abcabcd" is [0,0,0,1,2,3,0], and prefix function of string "aabaaab" is [0,1,0,1,2,2,3].

///                             HASHING

/// prefer using double hash if time complexity isn't too tight
unsigned bernstein_hash ( void *key, int len )
{
    unsigned char *p = key;
    unsigned h = 0;
    int i;

    for ( i = 0; i < len; i++ )
        h = 33 * h + p[i];

    return h;
}

/// Rabin-Karp Algorithm for string matching
vector<int> rabin_karp_HASH(string const& s, string const& t) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();
    vector<long long> p_pow(max(S, T));
    vector<long long> h(T + 1, 0);
    long long h_s = 0;
    vector<int> occurences;

    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;

    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    for (int i = 0; i + S - 1 < T; i++)
    {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}

///                         KMP with LPS (Used to find a pattern in a text)
void LPS()
{
    ll i,j,l=pat.size();
    i=0,j=-1;
    lps[i]=j;
    while(i<l)
    {
        while(pat[i]!=pat[j] && j>=0)
            j=lps[j];
        i++,j++;
        lps[i]=j;
    }
}
ll KMP(string txt)
{
    pat=txt; reverse(ALL(pat));
    LPS(pat);
    ll i,j,n,m;
    n=txt.size();
    m=pat.size();
    i=j=0;
    while(i<n)
    {
        while(j>=0 && txt[i]!=pat[j])
            j=lps[j];
        i++,j++;
    }
    return j;
}

string sub_pal(string s) /// Find Prefix Sub_Palindrom in O(n)
{
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    //cout<<a<<endl;
    ll c = 0,pref[99]={0};
    for (int i = 1; i < (int)a.size(); i++)
    {
        cout<<"C "<<c<<endl;
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}

string Manacher(string s)   /// returns longest subpalindrome in a string
{
        string T="#";// Transform S to T
        for(int i=0;i<s.size();i++)
            T+=s.substr(i,1)+"#";

        int P[T.size()+5]={0}; // Array to record longest palindrome
        int center=0,boundary=0,maxLen=0,resCenter=0;
        for(int i=1;i<T.size()-1;i++)
        {
            int iMirror=2*center-i; // calc mirror i = center-(i-center)
            if(i<boundary)
                P[i]=min(boundary-i,P[iMirror]);
            while(i-1-P[i]>=0 && i+1+P[i]<=T.size()-1 && T[i+1+P[i]]==T[i-1-P[i]]) // Attempt to expand palindrome centered at i
                P[i]++;
            if(i+P[i]>boundary)
            { // update center and boundary
                center = i;
                boundary = i+P[i];
            }
            if(P[i]>maxLen)
            { // update result
                maxLen = P[i];
                resCenter = i;
            }
        }
        return s.substr((resCenter - maxLen)/2, maxLen);
}

vector<int>z_algo(string s)  /// finds all occurrences of a pattern in a text in linear time
{
    int i,l,r,n;
    n=s.length();
    vector<int> z(n);
    for (i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ///Checking character and ++1
            ++z[i];

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}



int main()
{
    //IO;
    //while(1)
    //READ;WRITE;
{
    ll a=0,b=0,c=0,d,e,f,g,i,j,k,l,m,p,q,r,u,w,t,tc,in,mod,loc,diff,val,sz,lo,hi,mid,mn=MAX,mx=0,sum=0,ans=0;

}
    return 0;
}

/*

*/
/// Check for constraint 0 or 1?
/// long long or double? sqrt or division will work fine??
