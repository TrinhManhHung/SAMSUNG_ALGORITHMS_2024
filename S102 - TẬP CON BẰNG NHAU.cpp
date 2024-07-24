// TẬP CON BẰNG NHAU

#include<bits/stdc++.h>
using namespace std;
int f[10005];
void init(){
    for(int i =1; i <=10000; i++) f[i] = i;
    for(int i =1; i <=100; i++){
        f[i*i] = 1;
    }
    for(int i =2; i <=10000; i++){
        if(f[i] != 1){
            for(int j =1; j <i; j++){
                f[i] = min(f[i], f[i-j] + f[j]);
            }
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n+1];
        int sum = 0;
        for(int i =1; i <=n; i++){ 
            cin >> a[i];
            sum += a[i];
        }
        if(sum % 2 == 1) cout << "NO";
        else{
            sum /= 2;
            int dp[n+1][sum + 1];
            for(int i =0; i <=n; i++){
                for(int j =0; j <=sum; j++){
                    dp[i][j] = 0;
                }
            }
            for(int i =1; i <=n; i++) dp[i][0] = 1;
            for(int i =1; i <=n; i++){
                for(int j =1; j <=sum; j++){
                    dp[i][j] = max(dp[i-1][j-a[i]], dp[i-1][j]);
                }
            }
            
            if(dp[n][sum] == 0) cout << "NO";
            else cout << "YES";
        }
        cout << endl;
    }
    return 0;
}