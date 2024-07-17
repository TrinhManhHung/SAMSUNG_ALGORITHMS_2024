#include<bits/stdc++.h>
using namespace std;

void solve(){
    map<int, int> mp;
    int n; cin >> n;
    for(int i =0; i <n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    for(auto x : mp){
        if(x.second % 2 == 1){
            cout << x.first << endl;
            break;
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}