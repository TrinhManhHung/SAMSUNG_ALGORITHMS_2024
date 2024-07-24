// TỔNG GIAI THỪA

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    long long res = 1;
    long long sum[n+1]; 
    sum[1] = 1;
    for(int i =2; i <=n; i++){
        sum[i] = sum[i-1] * i;
        res += sum[i];
    }
    cout << res << endl;
}
int main(){
    // int t; cin >> t;
    // while(t--){
        solve();
    //}
    return 0;
}