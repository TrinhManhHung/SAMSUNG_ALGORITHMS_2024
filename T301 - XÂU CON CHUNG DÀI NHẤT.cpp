// XÂU CON CHUNG DÀI NHẤT

#include<bits/stdc++.h>
using namespace std;

void solve(){
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    a = " " + a; b = " " + b;
    int F[n+1][m+1]; //F[i][j] xau con chung dai nhat tinh den ai va bj
    for(int i =0; i <=n; i++) F[i][0] = 0;
    for(int i =0; i <=m; i++) F[0][i] = 0;
    for(int i =1; i <=n; i++){
        for(int j =1; j <=m; j++){
            if(a[i] == b[j])
                F[i][j] = F[i-1][j-1] + 1;
            else 
                F[i][j] = max(F[i-1][j], F[i][j-1]);
        }
    }
    cout << F[n][m] << "\n";
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}