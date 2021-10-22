//program 11.3.3.cpp 正则表达式
	#include <iostream>
	#include <regex> //使用正则表达式须包含此文件
	using namespace std;
	int main()
	{
		regex reg("b.?p.*k");
		cout << regex_match("bopggk",reg) <<endl;    //输出 1 表示匹配成功
		cout << regex_match("boopgggk",reg) <<endl;  //输出 0 表示匹配失败
		cout << regex_match("b pk",reg) <<endl;      //输出 1 表示匹配成功
		regex reg2("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");
		string correct="123Hello N/A Hello";
		string incorrect="123Hello 12 hello";
		cout << regex_match(correct,reg2) <<endl;    //输出 1 表示匹配成功
		cout << regex_match(incorrect,reg2) << endl; //输出 0 表示匹配失败
	}
