//THU GỌN DÃY SỐ

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n+1];
    for(int i =1; i <=n; i++) cin >> a[i];
    stack<int> st;
    int cnt = 0;
    for(int i =1; i <=n; i++){
        if(!st.empty() && (a[i] + a[st.top()]) % 2 == 0){
            st.pop();
            cnt += 2;
            continue;
        }
        st.push(i);
    }
    cout << n - cnt << endl;
    return 0;
}