#include<iostream>
#include<stack>
#include<string>
using namespace std;

class cal{
    public:
    int BasiCal(string s,int length);
};
int cal::BasiCal(string s, int length){
    int res = 0,num = 0;
    char cur_op = '+';//初始为‘+’
    stack<int> sta;//使用栈保存数字
    for(int i = 0;i<length;i++){
        if(s[i] >='0'){
            num = num*10 + s[i]-'0';
        }
        if(s[i]<'0' || i == length-1){
            if(cur_op=='+') sta.push(num);
            if(cur_op=='-') sta.push(-num);//加或者减 则数字进栈
            if(cur_op == '*' || cur_op=='/'){
                int temp = (cur_op == '*')? sta.top()*num:sta.top()/num;//遇到乘或者除，取栈顶数字于之前的num进行乘除运算，将结果压入栈顶
                sta.pop();
                sta.push(temp);
            }
            cur_op = s[i];//😘😘😍
            num = 0;
        }
    }
    while(!sta.empty()){
        res += sta.top();//乘除操作都已经完成，只剩下求和
        sta.pop();
    }
    return res;

}
int main(){
    cal calculator;
    string s = "3+5/2";
    int n = s.size();
    cout<<"the result of:"<<s<<"is: "<<calculator.BasiCal(s,n)<<endl;
    system("pause");
    return 0;
}