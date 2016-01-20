#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll ,ll>

using namespace std;

struct priority_rev
{
    bool operator()(const pll &a ,const pll &b)
    {
    return a.second >b.second;
    }
};
class Prims
{
    vector<pll> *v;
    ll k;
public:
    Prims(ll n)
    {
        k=n;
        v=new vector<pll>[n];
    }



    void add_vertices()
    {
        ll a,b,c;

        cin>>a>>b>>c;
        v[a-1].push_back(make_pair(b-1,c));
    v[b-1].push_back(make_pair(a-1,c));
    }


ll prims(ll src)
{
    priority_queue<pll,vector<pll>,priority_rev> pq;
    int total=0;
    ll dist[k];
    bool visited[k];
    int cnt=0;
    for(ll i=0;i<k;i++)
    {
        dist[i]=LONG_MAX;
        visited[i]=false;
    }



    dist[src]=0;
    visited[src]=true;

    pq.push(make_pair(src,0));

    while(!pq.empty())
    {
        pll abcd =pq.top();

        pq.pop();



        ll here =abcd.first;

        cnt++;
        ll c_dis=abcd.second;
   // cout<<"here"<<abcd.first<< " c_dis"<<abcd.second<<endl;
        for(vector<pll>::iterator it=v[here].begin();it!=v[here].end();it++)
        {
            pll current =*it;
            if(visited[current.first]==false)
            {


           if(dist[current.first] >current.second)
           {
               dist[current.first]=current.second;
               pq.push(make_pair(current.first,dist[current.first]));
           }
        }
        }
         visited[here]=true;

        }


        for(int i=0;i<k;i++)
        {
            cout<<dist[i]<<endl;
           total+=dist[i];
        }



    return total;

}
};

int main()

{

 ll v,e,start;
 //freopen("input.txt","r",stdin);f
    cin>>v>>e;
    Prims d(v);
    for(ll i=0;i<e;i++)
    {
        d.add_vertices();
    }
    cin>>start;
    cout<<d.prims(start-1)<<endl;

}

