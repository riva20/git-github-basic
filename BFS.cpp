#include <bits/stdc++.h>
#define ll long long int
using namespace std;
map<ll,ll>mpp;
bool cmp(int a,int b)
{
    return mpp[a]<mpp[b];
}
ll a[1000000];
ll b[1000000];
vector<ll>v[1000000];
ll dis[1000000];
ll vis[1000000];
ll x=0,l;

void BFS(ll node)
{
    queue<ll>q;
    q.push(node);
    vis[node]=1;
    dis[node]=0;
    // b[x++]=node;
    while(!q.empty())
    {
        int cur=q.front();

        q.pop();
        b[x++]=cur;
        if(cur!=a[0])
            l=0;
        for(int i=l; i<v[cur].size(); i++)
        {
            ll child=v[cur][i];
            if(vis[child]==0)
            {
                dis[child]=dis[cur]+1;
                vis[child]=1;
                q.push(child);
            }
        }
    }
}
int main ()
{

    ll n,m;
    cin>>n>>m;
    // ll m=n-1;
    vector<pair<ll,ll>>h;
    ll d=m;
    ll ma=0;
    while(m--)
    {
        ll x,y;
        cin>>x>>y;
        h.push_back(make_pair(x,y));
        v[x].push_back(y);
        v[y].push_back(x);
        mpp[x]++;
        mpp[y]++;

    }
    ll s=0;
    for(int i=1;i<=n;i++)
    {
        if(mpp[i]>ma)
        {
            ma=mpp[i];
            s=i;
        }
    }


    BFS(1);
    ll j=0;

    for(int i=1; i<=n; i++)
    {
        if(i!=s&&v[i].size()>1)
        {
            j=-1;
            break;
        }
    }
    if(j==-1)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        BFS(s);
        for(int i=0; i<d; i++)
        {
            ll o=h[i].second;
            cout<<dis[o];
        }
    }

}

