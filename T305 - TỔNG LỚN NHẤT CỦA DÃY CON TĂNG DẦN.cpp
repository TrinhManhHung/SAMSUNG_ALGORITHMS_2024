// TỔNG LỚN NHẤT CỦA DÃY CON TĂNG DẦN

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n+1];
    for(int i =1; i <=n; i++) cin >> a[i];
    int F[n+1]; //F[i] tong day con dai nhat xet den phan tu thu i
    F[1] = a[1];
    for(int i =2; i <=n; i++){
        F[i] = a[i];
        for(int j =1; j <i; j++){
           if(a[i] > a[j]) F[i] = max(F[i], F[j] + a[i]);
        }
    }
    cout << *max_element(F+1, F+n+1) << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}