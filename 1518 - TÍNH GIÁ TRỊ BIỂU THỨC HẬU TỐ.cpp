// TÍNH GIÁ TRỊ BIỂU THỨC HẬU TỐ

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
        for(auto x : s){
            if(isdigit(x)){
                st.push(x - '0');
            }
            else{
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                int tmp = cal(op1, op2, x);
                st.push(tmp);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}