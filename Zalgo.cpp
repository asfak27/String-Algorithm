///Z_Algorithm
/*#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long int
#define mod      1000000007
#define N        200005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>z_algo(string s)
{
    ll len=s.size();
    ll l=0;
    ll r=0;
    vector<ll>z(len);
    for(ll i=1; i<len; i++)
    {
        if(i>r)
        {
            l=i;
            r=i;
            while(r<len and s[r-l]==s[r])
            {
                r++;
            }
            r--;
            z[i]=r-l+1;
        }
        else{
            ll idx=i-l;
            if(z[idx]<=r-i)
            {
                z[i]=z[idx];
            }
            else{
                l=i;
                while(r<len && s[r]==s[r-l])
                {
                    r++;
                }
                r--;
                z[i]=r-l+1;
            }
        }
    }
    return z;
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    map<ll,ll>mp;
    ll e,i,j,l,m,x,y,z,r,n,k;
    string s,t;
    cin>>s;
    vector<ll>v=z_algo(s);
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
*/
///Z_Algorithm ->pattern matching
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long int
#define mod      1000000007
#define N        200005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>z_algo(string s)
{
    ll len=s.size();
    ll l=0;
    ll r=0;
    vector<ll>z(len);
    for(ll i=1; i<len; i++)
    {
        if(i>r)
        {
            l=i;
            r=i;
            while(r<len and s[r-l]==s[r])
            {
                r++;
            }
            r--;
            z[i]=r-l+1;
        }
        else{
            ll idx=i-l;
            if(z[idx]<=r-i)
            {
                z[i]=z[idx];
            }
            else{
                l=i;
                while(r<len && s[r]==s[r-l])
                {
                    r++;
                }
                r--;
                z[i]=r-l+1;
            }
        }
    }
    return z;
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    map<ll,ll>mp;
    ll e,i,j,l,m,x,y,z,r,n,k;
    string s,t;
    cin>>s>>t;
    string ss=t+'$'+s;
    vector<ll>v=z_algo(ss);
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}

