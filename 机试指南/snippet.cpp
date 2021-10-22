//https://www.nowcoder.com/practice/5759c29a28cb4361bc3605979d5a6130?tpId=40&tPage=1&rp=1&ru=%2Fta%2Fkaoyan&qru=%2Fta%2Fkaoyan%2Fquestion-ranking&tab=answerKey 
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

const int N=100010;

stack<double> num;
stack<char> sign;
string input;

int pronum(int k){
    int i=k;
    double t=input[i++]-48;
    while(input[i]>=48 && input[i]<=57){
        t=t*10+input[i++]-48;
    }
    //cout<<t<<" 1 "<<endl;
    num.push(t);
    return i;
}

double cal(double x,double y,char z){
    if(z=='+') return x+y;
    return x-y;
}

int main()
{
    while(getline(cin, input)){
        if(input=="0") break;
        int i=0;
        double res=0;
        while(i<input.size()){
            if(input[i]>=48 && input[i]<=57){
                i=pronum(i);
                continue;
            }
            if(input[i]=='*'){
                i++;
                i=pronum(++i);
                double a=num.top(),b;
                num.pop();
                b=num.top();
                num.pop();
                num.push(a*b);
                //cout<<a<<","<<b<<endl;
                continue;
            }
            if(input[i]=='/'){
                i++;
                i=pronum(++i);
                double a=num.top(),b;
                num.pop();
                b=num.top();
                num.pop();
                num.push(b/a);
                continue;
            }
            if(input[i]=='+' || input[i]=='-'){
                sign.push(input[i++]);
            }
            if(input[i]==' ') i++;
        }
        while(!sign.empty()){
            double x=num.top();
            num.pop();
            char s=sign.top();
            sign.pop();
            if(s=='+') res+=x;
            if(s=='-') res-=x;
        }
        res+=num.top();
        num.pop();
        printf("%.2lf\n",res);
    }
    return 0;
}
