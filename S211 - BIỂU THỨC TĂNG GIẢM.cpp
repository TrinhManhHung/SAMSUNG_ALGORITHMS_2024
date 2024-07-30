// BIỂU THỨC TĂNG GIẢM

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t = 1;
    int test; cin >> test;
    while(t <= test){
        string s; cin >> s;
        s = s + "I";
        int d = 1;
        stack<int> st;
        st.push(1);
        cout << "Test " << t << ": ";
        for(int i =0; i <s.size(); i++){
            if(s[i] == 'I'){
                while(!st.empty()){
                    cout << st.top();
                    st.pop();
                }
            }
            d++;
            st.push(d);
        }
        cout << endl;
        t++;
    }
    return 0;
}