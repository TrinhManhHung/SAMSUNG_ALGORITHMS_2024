// SỬA LẠI DÃY NGOẶC

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int cnt = 0;
        stack<int> st;
        for(int i =0; i <s.size(); i++){
            if(s[i] == ')'){
                if(!st.empty()) st.pop();
                else cnt++;
            }
            else if(s[i] == '('){
                st.push(i);
            }
        }
        int res = cnt / 2 + st.size() / 2 + (cnt % 2 + st.size() % 2);
        cout << res << endl;
    }
    return 0;
}