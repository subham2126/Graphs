/* Trico ------------------------> NIT Silchar

“All power is within you; you can do anything and everything.
Believe in that, do not believe that you are weak; do not believe that you are half-crazy lunatics,
as most of us do nowadays. You can do any thing and everything, without even the guidance
of any one. Stand up and express the divinity within you.”

 */
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define vl vector<ll>
#define mod 1000000007
#define fori(z,n) for(int i=z;i<n;i++)
#define forj(z,n) for(int j=z;j<n;j++)
#define fork(z,n) for(int k=z;k<n;k++)
#define db(x) cout << (#x) << " = " << x << endl;
#define trico() int t;cin>>t ; while(t--)
#define p_iter vector<pll>::iterator
#define l_iter vector<ll>::iterator
#define forstl(m) for(it=m.begin();it!=m.end();it++)
using namespace std;
static int u=0;
void f_case(){u++;cout<<"Case "<<u<<": ";}

vector<pll> *xy;
bool *visited;
 ll v,e,a,b,cost,src;
ll shortest_path(ll src)
{
    ll dist[v];
    fori(0,v)
    {


    dist[i]=LONG_MAX;
    visited[i]=false;
    }
    dist[src]=0;
    deque<ll> d;
    d.push_back(src);
    vector<pll>::iterator it;
    while(!d.empty())
    {
        ll k=d.front();
        d.pop_front();
        visited[k]=true;
        for(it=xy[k].begin();it!=xy[k].end();it++)
        {
            if(!visited[it->first])
            {


            if(dist[k]+it->second < dist[it->first])
                dist[it->first]=dist[k]+it->second;
            if(it->second)
                d.push_back(it->first);
            else
                d.push_front(it->first);
        }
        }



}
return dist[v-1];
}

int main()
{
 //freopen("input.in", "r", stdin);


 cin>>v>>e;
 xy=new vector<pll>[v];
 visited=new bool[v];
 fori(0,e)
 {
     cin>>a>>b>>cost;
     xy[a].push_back(make_pair(b,cost));
     xy[b].push_back(make_pair(a,cost));

 }
 cin>>src;
 cout<<shortest_path(src);




}
