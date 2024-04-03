#include<bits/stdc++.h>
using namespace std;
void connectnode(vector<set<int>> & adjlst,int x)
{
    if(adjlst[x].empty())
    {
        cout<<"-1\n";
        return ;
    }
    for(auto it=adjlst[x].begin();it!=adjlst[x].end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{

     int a,b;
     cin>>a>>b;
     vector<<set<int>>adjlst(a);
     for(int i=0;i<b;i++)
     {
        int m,n;
        cin>>m>>n;
        adjlst[m].insert(n);
        adjlst[n].insert(m);

     }
     int p;
     cin>>p;
     for(int i=0;i<p;i++)
     {
        int x;
        cin>>x;
        connectnode(adjlst,x);
     }
    return 0;
}