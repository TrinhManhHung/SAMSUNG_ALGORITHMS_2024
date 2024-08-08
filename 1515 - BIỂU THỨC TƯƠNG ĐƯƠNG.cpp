// BIỂU THỨC TƯƠNG ĐƯƠNG

#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    stack<string> st;
    for(int i = s.size()-1; i >=0; i--){
        if(isalpha(s[i]) || s[i] == ')' || s[i] == '+'){
            st.push(string(1, s[i]));
        }
        else if(s[i] == '('){
            string tmp = "";
            while(st.top() != ")"){
                tmp += st.top();
                st.pop();
            }
            st.pop();
            st.push(tmp);
        }
        else if(s[i] == '-'){
            string tmp = st.top(); st.pop();
            for(int k =0; k <tmp.size(); k++){
                if(tmp[k] == '-') tmp[k] = '+';
                else if(tmp[k] == '+') tmp[k] = '-';
            }
            st.push(tmp);
            st.push(string(1, s[i]));
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << "\n";
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}