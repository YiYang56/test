#include <iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
using namespace std;



int main()
{
    //vector部分
    vector<int> c(10,3);//长度为10的vector；第一个参数：长度；第二个参数：每个值的初始化
    vector<int> b[10];//vector数组，定义了10个vector
    /*
    size() 元素的个数
    empty() 是否为空，true or false
    以上两个所有容器都可使用
    clear() 清空
    vector尽量减少申请空间的次数，时间复杂度与空间大小无关
    front()/back()
    push_back()/pop_back()
    begin()/end() begin第0个；end最后一个的后面一个
    */

    /*
    vector<int> a;
    //迭代器遍历
    for(int i=0;i<10;i++) a.push_back(i);

    for(int i=0;i<a.size();i++) cout<<a[i]<<" ";

    for(vector<int>::iterator i=a.begin();i!=a.end();i++) cout<<*i<<" ";
    */

    //for(auto x : a) cout<<x<<" ";


    //pair<type,type>部分
    /*
    p.first p.second
    构造pair: p=make_pair(type,type);
    pair<type,pair<type,type> > 三种属性
    */


    //string部分
    /*
    size,empty,clear
    支持直接+
    str.substr(a,b) 返回字串,a为起始位置,b为长度,无b时返回从a到末尾
    a.c_str() 返回a的起始地址
    */

    //queue部分
    /*
    push,front,back,pop 先进先出
    queue<int> q;
    */

    //priority_queue优先队列，默认是大根堆（最大），小根堆的话可插入-x
    /*
    push,top,pop
    priority_queue<int> heap;
    */
    
    //stack栈
    /*
    push,top,pop
    */
    
    //deque双端队列，强化版vector，缺点是速度会慢一些，效率不高
    /*
    size,empty,clear
    front,back
    push_back,pop_back 队尾
    push_front,pop_front 队首
    begin,end
    */

    //set不能有重复元素，multiset可以有
    /*
    insert插入
    find查找（不存在返回end迭代器
    count返回某个数的个数
    erase 输入是一个数，则删除所有值为该数值的节点
        输入是一个迭代器，则删除这个迭代器
    lower_bound/upper_bound l返回大于等于x的最小的迭代器，u返回大与x的最小的迭代器，不存在返回end
    */
    
    //map,multimap
    /*
    insert 输入的是一个pair
    erase 输入的是pair或迭代器
    find
    [] 支持数组操作
    */
    map<string,int> a;
    a["yxc"]=1;
    cout<<a["yxc"]<<endl;//1

    // bitset 压位,存bool变量
    /*
    bitset<10000> s;
    ~&|^
    >> <<
    == !=
    []
    count 返回有多少个1
    any 是否至少有一个1
    none 是否全为0
    set() 把所有位置1
    set(k,v) 把第K为变成v
    reset()  把所有位置0
    flip 把所有位取反
    flip(k) 第k位取反
    */

    return 0;
}

