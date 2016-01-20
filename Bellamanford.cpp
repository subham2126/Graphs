#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll ,ll>

struct Edge
{
    ll src,dest,weight;

};

using namespace std;

class Bellman_Ford
{
    Edge *e;
    ll k;
    ll edges;
    ll *dist;
public:
    Bellman_Ford(ll n,ll edg)
    {
        k=n;
        edges=edg;
        e=new Edge[edges];
        dist=new ll[k+1];


    }



    void add_vertices()
    {
        ll c;
        for(ll i=0;i<edges;i++)
        {
            cin>>e[i].src>>e[i].dest>>c;
            e[i].weight=-1*c;
        }







    }


bool Bellman(ll src)
{


    for(ll i=0;i<k;i++)
        dist[i+1]=LONG_MAX;
    dist[src]=0;
    for(ll i=0;i<k-1;i++)
    {
        for(ll j=0;j<edges;j++)
        {
            int u = e[j].src;
            int v = e[j].dest;
            int weight = e[j].weight;
            if(dist[u]!=LONG_MAX &&dist[u]+weight <dist[v])
                dist[v]=dist[u]+weight;

        }
    }
    //code for negative cycle detection

    bool flag=true;
    for(ll j=0;j<edges;j++)
        {
            int u = e[j].src;
            int v = e[j].dest;
            int weight = e[j].weight;
            if(dist[u]!=LONG_MAX &&dist[u]+weight < dist[v])
               {
                   flag=false;
                   break;
               }

        }









return flag;
}
};



int main()
{
    freopen("input.txt","r",stdin);
    ll t,v,e;
cin>>t;
while(t--)
{
    cin>>v>>e;
    Bellman_Ford b(v,e);
    b.add_vertices();
    if(b.Bellman(1)==true)
        cout<<"No\n";
    else
        cout<<"Yes\n";

}
}
