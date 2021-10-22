#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=110;

bool st[N];
int points[N];
int n;

vector<int> temp;
vector<vector<int> > res;

struct Edge
{
    int a,b;
}edges[N];


void dfs(int u)
{
    if(u==n){
        res.push_back(temp);
        return;
    }

    for(int i=0;i<n;i++){
        if(!st[i] && points[i]==0){
            temp.push_back(i);
            st[i]=true;
            for(int j=0;j<n;j++){
                if(edges[j].b==i) points[edges[j].a]--;
            }
            dfs(u+1);
            st[i]=false;
            temp.pop_back();
            for(int j=0;j<n;j++){
                if(edges[j].b==i) points[edges[j].a]++;
            }
        }
    }
}

int main()
{
    cin>>n;
    memset(st,0,sizeof st);
    memset(points,0,sizeof points);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        edges[i].a=a;
        edges[i].b=b;
        points[a]++;
    }

    dfs(0);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<n;j++) cout<<res[i][j]<<" ";
        puts("");
    }

    return 0;
}