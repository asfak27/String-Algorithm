///Knuth–Morris–Pratt (KMP)
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long int
#define mod      1000000007
#define N        200005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>create_lps(string t)
{
    ll n=t.size();
    vector<ll>lps(n);
    ll idx=0;
    for(ll i=1; i<n;)
    {
        if(t[i]==t[idx])
        {
            lps[i]=idx+1;
            idx++;
            i++;
        }
        else
        {
            if(idx!=0)
            {
                idx=lps[idx-1];
            }
            else
            {
                lps[i]=idx;
                i++;
            }
        }
    }
    return lps;
}

void kmp(string s,string t)
{
    vector<ll>v;
    vector<ll>lps=create_lps(t);
    ll i=0;
    ll j=0;
    ll n=s.size();
    ll m=t.size();
    bool f=false;
    while(i<n)
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else{
            if(j!=0)j=lps[j-1];
            else i++;
        }

        if(j==m)
        {
            v.push_back(i-m);
            j=lps[j-1];
            f=true;
        }

    }
    if(v.size()<=0)
    {
        no;
    }
    else{
        cout<<v.size()<<endl;
    }
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    ll e,i,j,l,m,x,y,z,r,n,k;
    string s,t;
    cin>>s>>t;

    kmp(s,t);

}
int main()
{
    fast;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
