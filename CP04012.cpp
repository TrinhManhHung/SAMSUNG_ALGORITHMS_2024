// GIÁ TRỊ NHỎ NHẤT CỦA XÂU

// ĐẢO DẤU

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int k; cin >> k;
    string s; cin >> s;
    map<char, int> mp;
    for(auto x : s) mp[x]++;
    priority_queue<int> q;
    for(auto x : mp){
    //    cout << x.first << " " << x.second << endl;
        q.push(x.second);
    }
    while(k--){
        int top = q.top(); q.pop();
        top--;
        top = max(0, top);
        q.push(top);
    }
    ll sum = 0;
    while(!q.empty()){
        sum += q.top() * q.top();
        q.pop();
    }
    cout << sum << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}