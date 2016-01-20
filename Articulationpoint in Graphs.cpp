#include<bits/stdc++.h>
#define ll long long
#define fori(z,n) for(int i=z;i<n;i++)
#define forj(z,n) for(int j=z;j<n;j++)
#define fork(z,n) for(int k=z;k<n;k++)
#define l_iter vector<ll>::iterator

using namespace std;
vector<ll> *data;


ll *disc_time;
ll *low;
ll *parent;
bool *is_arti; //true if it an articulation point
ll tim=0;

void ar_point(ll n)
{
    int child=0;
    low[n]=tim;
    disc_time[n]=tim;
    tim++;
    l_iter it;
    for(it=data[n].begin();it!=data[n].end();it++)
    {
        if(parent[n]==*it)
        {
            continue;
        }
        if(disc_time[*it]==-1)
        {
            child++;
            parent[*it]=n;
            ar_point(*it);
            if(low[*it]>disc_time[n] && parent[n]!=-1)
            {
                //cout<<"Hello\n"<<n<<" ";
                //  if greaqter than any child
                is_arti[n]=true;
            }
            else
                low[n]=min(low[n],low[*it]);

        }
        else
        {
            low[n]=min(low[n],disc_time[*it]);  // if already visited
        }
    }
    if(parent[n]==-1 && child>1)
        is_arti[n]=true;
}


void input()
{
    ll n,e,a,b;
    cin>>n>>e;
    data=new vector<ll>[n];

    is_arti=new bool[n];
    disc_time=new ll[n];
    low=new ll [n];
    parent=new ll[n];
    fori(0,n)
    {



    is_arti[i]=false;
    disc_time[i]=-1; // it will indicate if the node is visited or not
    }
    fori(0,e)
    {
        cin>>a>>b;
        data[a].push_back(b);
        data[b].push_back(a);
    }
   parent[0]=-1;
   ar_point(0); // take 0 as root
    fori(0,n)
    {
        if(is_arti[i]==true)
        cout<<i<<" ";
    }


}

int main()
{
    input();


}
