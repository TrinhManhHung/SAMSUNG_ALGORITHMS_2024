// DÃY SỐ VÔ HẠN

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
unordered_map<ll, int> mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i =1; i <=50; i++){
        ll tmp = (ll)(pow(2, i-1));
        mp[tmp] = i;
    }
    int t; cin >> t;
    while(t--){
        int n; ll k;
        cin >> n >> k;
        while(mp.find(k) == mp.end()){
            int base = log2(k);
            k -= pow(2, base);
        }
        cout << mp[k] << endl;
    }
    return 0;
}