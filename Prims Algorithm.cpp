#include<bits/stdc++.h>

using namespace std;



class Prims
{


int k;
int **graph;


public:
Prims(int v)
{

    k=v;
graph= new int*[v];
for(int i = 0; i < v; ++i)
    graph[i] = new int[v];

}
void accept_value()
{

    for(int i=0;i<k;i++)
    {

        for(int j=0;j<k;j++)
        {

            cin>>graph[i][j];
        }
    }
}


int min_prim(int key[],bool visited[])
{
    int index,min_v =INT_MAX;

    for(int i=0;i<k;i++)
    {

        if((visited[i]==false) && (key[i]<min_v))
        {
            min_v=key[i];
            index =i;
        }
    }
    return index;
}

void print_prim(int parent[],int k )
{
    int sum=0;
    printf("Edge   Weight\n");
   for (int i = 1; i < k; i++)
   {


printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
sum+=graph[i][parent[i]];

   }
   cout<<"\n"<<sum;

}


void prims()
{
    int parent[k];
    int key[k];
    bool visited[k];
    for(int i=0;i<k;i++)
    {

        visited[i]=false;
        key[i]=INT_MAX;

    }
    key[0]=0;
    parent[0]=-1;

    for(int i=0;i<k-1;i++)
    {

    int u =min_prim(key,visited);

    visited[u]=true;
    for(int i=0;i<k;i++)
    {

        if(graph[u][i] &&(visited[i]==false) &&graph[u][i]<key[i])
        {

            parent[i]=u;
            key[i]=graph[u][i];
        }
    }
    }
print_prim(parent,k);

}
};

int main()
{
    int n;
    cin>>n;
    Prims p(n);
    p.accept_value();
    p.prims();



}
