//program 11.3.6.cpp ���ڷ�Χ��forѭ��
	#include <iostream>
	#include <vector>
	using namespace std;
	struct A {	int n;	A(int i):n(i) {	} };
	int main()  {
		int ary[] = {1,2,3,4,5};
		for(int & e: ary)  	//��ary��ÿ��Ԫ�ض�����10
			e*= 10;
		for(int e : ary)	    //���ary������Ԫ��
			cout << e << ",";
		cout << endl;
		vector<A> st(ary,ary+5);
		for(  auto & it: st)  //��st��ÿ��Ԫ�ض�����10
			it.n *= 10;
		for(  A it: st)   //���st������Ԫ��
			cout << it.n << ",";
		return 0;
	}
