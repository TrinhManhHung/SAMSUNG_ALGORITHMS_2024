// NỐI DÂY 2

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll)(1e9 + 7)
int main(){
    int t; cin >> t;
    while(t--){
        priority_queue<ll, vector<ll>, greater<ll>> Q;
        int n; cin >> n;
        for(int i =0; i <n; i++){
            ll x; cin >> x;
            Q.push(x);
        }
        ll res = 0;
        while(Q.size() > 1){
            ll day1 = Q.top(); Q.pop();
            ll day2 = Q.top(); Q.pop();
            ll sum = (day1 + day2) % mod;
            res = (res + sum) % mod;
            Q.push(sum);
        }
        cout << res << endl;
    }
    return 0;
}