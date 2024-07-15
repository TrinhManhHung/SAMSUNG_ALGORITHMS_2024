//So chi co ba uoc so
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1000000;
int nt[maxn + 5];
void sang(){
    for(int i=1; i <=maxn; i++) nt[i] = 1;
    nt[0] = nt[1] = 0;
    for(int i =2; i * i <=maxn; i++){
        if(nt[i]){
            for(int j =i*i; j <=maxn; j +=i){
                nt[j] = 0;
            }
        }
    }
}
void solve(){
    ll l, r; cin >> l >> r;
    l = min(l, r); r = max(l, r);
    l = sqrt(l); r = sqrt(r);
    int ans = 0;
    for(int i =l; i <=r; i++){
        if(nt[i]) ans++;
    }
    cout << ans <<endl;
}
int main(){
    sang();
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}