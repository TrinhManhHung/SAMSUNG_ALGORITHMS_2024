// SO SÁNH BIỂU THỨC

#include<bits/stdc++.h>
using namespace std;

string change(string s){
    stack<string> st;
    for(int i = s.size()-1; i >=0; i--){
        if(isalpha(s[i]) || s[i] == '+' || s[i] == ')'){
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
                if(tmp[k] == '+') tmp[k] = '-';
                else if(tmp[k] == '-') tmp[k] = '+';
            }
            st.push(tmp);
            st.push(string(1, s[i]));
        }
    }
    string res = "";
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
        string s1, s2; cin >> s1 >> s2;
        string res1 = change(s1);
        string res2 = change(s2);
        if(res1 == res2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}