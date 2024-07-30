#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        stack<char> st;
        for(auto x : s) {
            if(x == ')'){
                while(!st.empty() && st.top() != '('){
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(isalpha(x) || isdigit(x)){
                cout << x;
            }
            else{
                st.push(x);
            }
        }
        cout << endl;
    }
    return 0;
}