// TÍNH GIÁ TRỊ BIỂU THỨC TIỀN TỐ

#include<bits/stdc++.h>
using namespace std;

int cal(int a, int b, char c){
    if(c == '+') return a + b;
    if(c == '/') return a / b;
    if(c == '*') return a * b;
    return a - b;
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<int> st;
        for(int i =s.size()-1; i >=0; i--){
            if(isdigit(s[i])){
                st.push(s[i] - '0');
            }
            else{
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                int tmp = cal(op1, op2, s[i]);
                st.push(tmp);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}