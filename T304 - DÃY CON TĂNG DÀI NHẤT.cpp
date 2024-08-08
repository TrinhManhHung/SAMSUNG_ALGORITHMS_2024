// DÃY CON TĂNG DÀI NHẤT

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n+1];
    for(int i =1; i <=n; i++) cin >> a[i];
    int F[n+1]; //F[i] day con tang dai nhat tinh den i
    F[0] = 0; F[1] = 1;
    for(int i =2; i <=n; i++){
        F[i] = 1;
        for(int  j =1; j <i; j++){
            if(a[i] > a[j]){
                F[i] = max(F[i], F[j] + 1); 
            }
        }
    }
    cout << *max_element(F+1, F+n+1) << "\n";
}
int main(){
    solve();
    return 0;
}