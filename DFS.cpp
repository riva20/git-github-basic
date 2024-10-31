#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int vis[10003];
vector<int>v[10000];
void dfs(int node)
{
    vis[node]=1;
    cout<<node<<" ";
    for(int i=0; i<v[node].size(); i++)
    {
        int child=v[node][i];
        if(vis[child]==0)
        {
            dfs(child);
        }
    }
}
int main ()
{

    ll n,m;
    cin>>n>>m;
    while(m--)
    {
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);

    }
    dfs(1);
}
