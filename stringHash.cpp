///https://leetcode.com/problems/maximum-deletions-on-a-string/
typedef long long int ll;
const int MOD = 1e9+7;
const ll P = 20;

class Solution {
    vector<int> dp;
    vector<ll> g[5001];

    void PreComputeHash (const string& s) {
        int n = s.length();

        for (int j = 0; j < n; j ++) {
            ll pwr = P;
            ll prefix = 0;
            for (int k = j; k < n; k ++) {
                ll val = (pwr * s[k]) % MOD;
                prefix = (prefix + val) % MOD;

                g[j].push_back (prefix);
                pwr = (pwr * P) % MOD;
            }
        }
    }

    bool IsEqual (int l1, int r1, int l2, int r2) {
        int len = (r2 - l2 + 1);

        return (g[l1][len-1] == g[l2][len-1]);
    }

    int MaxOperation (int ind, const int len) {
        if (ind == len) return 0;
        if (dp[ind] != -1) return dp[ind];

        int& ans = dp[ind];
        ans = 1;    // delete the entire string.

        for (int j = 1; j < len; j ++) {
            int l1 = ind, r1 = l1 + j - 1;
            int l2 = r1 + 1, r2 = l2 + j - 1;

            if (r1 >= len || r2 >= len) break;

            if (IsEqual(l1, r1, l2, r2)) ans = max (ans, 1+MaxOperation (r1+1, len));
        }
        return ans;
    }

public:
    int deleteString(string s) {
        int n = s.length();
        dp.clear();
        dp.resize(n, -1);

        PreComputeHash(s);

        return MaxOperation (0, n);
    }
};
///https://leetcode.com/problems/longest-happy-prefix/submissions/
typedef long long int ll;
const int MOD = 1e9+7;
class Solution {
public:
    string longestPrefix(string s) {

        ll i,j,x=0,y=0,base=26,mul=1;
        ll n=s.size();
        ll ans=0;
        string t="";
        for(i=0;i<n-1;i++)
        {
            x=(x*base+(s[i]-'a'+1));
            x%=MOD;

            y=((s[n-i-1]-'a'+1)*mul+y);
            y%=MOD;

            mul*=base;
            mul%=MOD;
            if(y==x)ans=i+1;
        }
        return s.substr(0,ans);


    }
};
///https://codeforces.com/contest/126/problem/B
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long int
#define mod      1000000007
#define N        2000005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll h[N];
ll p[N];
void hash_fun(string s)
{
    ll n=s.size();
    ll base=31;
    p[0]=1;
    for(ll i=1;i<=n;i++)
    {
        h[i]=(h[i-1]*base%mod+(s[i-1]-'a'+1))%mod;
        p[i]=p[i-1]*base%mod;
    }
}
ll getVal(ll l,ll r)
{
    return (h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    ll e,i,j,l,m,x,y,z,r,n,k;
    string s,t;
    cin>>s;
    n=s.size();
    hash_fun(s);
    for(i=1;i<=n;i++)
    {
        if(getVal(1,i)==getVal(n-i+1,n))
        {
            v.push_back(i);
        }
    }
    l=0;
    r=v.size()-1;
    ll idx=-1;
//    for(i=0;i<v.size();i++)
//    {
//        cout<<v[i]<<" ";
//    }
//    cout<<endl;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        bool f=false;

        for(i=2;i<n-v[mid]+1;i++)
        {
            if(getVal(1,v[mid])==getVal(i,v[mid]+i-1))
            {
                f=true;
            }
        }
        if(f)
        {
            idx=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    //cout<<idx<<endl;
    if(idx==-1)
    {
        cout<<"Just a legend"<<endl;
    }
    else
    {
        cout<<s.substr(0,v[idx])<<endl;
    }
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
