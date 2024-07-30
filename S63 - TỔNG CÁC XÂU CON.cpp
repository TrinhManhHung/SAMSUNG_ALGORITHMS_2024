// TỔNG CÁC XÂU CON

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    ll F[n+1]; memset(F, 0, sizeof(F));
    for(int i =1; i <s.size(); i++){
        F[i] = F[i-1] * 10 + (s[i] - '0') * i;
    }
    ll res = 0;
    for(int i =1; i <s.size(); i++){
        res += F[i];
    }
    cout << res << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}