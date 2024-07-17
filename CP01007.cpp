// SỐ ĐỨNG ĐẦU

// DÃY CON LIÊN TIẾP

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n+1];
    for(int i =1; i <=n; i++) cin >> a[i];
    
    stack<int> st;
    vector<int> res;

    for(int i =n; i >=1; i--){
        while(!st.empty() && a[i] > a[st.top()]){
            st.pop();
        }
        if(st.empty()){ 
            res.push_back(a[i]);
        }
        st.push(i);
    }
    reverse(res.begin(), res.end());
    for(auto x : res) cout << x << " ";
    cout << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}