//program 11.3.6.cpp 基于范围的for循环
	#include <iostream>
	#include <vector>
	using namespace std;
	struct A {	int n;	A(int i):n(i) {	} };
	int main()  {
		int ary[] = {1,2,3,4,5};
		for(int & e: ary)  	//将ary中每个元素都乘以10
			e*= 10;
		for(int e : ary)	    //输出ary中所有元素
			cout << e << ",";
		cout << endl;
		vector<A> st(ary,ary+5);
		for(  auto & it: st)  //将st中每个元素都乘以10
			it.n *= 10;
		for(  A it: st)   //输出st中所有元素
			cout << it.n << ",";
		return 0;
	}
