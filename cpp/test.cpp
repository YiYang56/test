#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

int main()
{
    unordered_map<string,string> dic;
    for(int i=0;i<100000;i++){
        string a,b;
        dic[b]=a;
    }

    for(int i=0;i<100000;i++){
        string u;
        cin>>u;
        if(dic.find(u)!=dic.end()) cout<<dic[u]<<endl;
        else cout<<"eh"<<endl;
    }

    return 0;
}