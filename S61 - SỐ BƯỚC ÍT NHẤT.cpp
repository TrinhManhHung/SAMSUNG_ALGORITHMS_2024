// SỐ BƯỚC ÍT NHẤT

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n+1];
        for(int i =1; i <=n; i++) cin >> a[i];
        int dp[n+1]; // dp[i] do dai day con tang dai nhat tinh den chi so i
        dp[1] = 1;
        for(int i =1; i <=n; i++){
            dp[i] = 1;
            for(int j =1; j <i; j++){
                if(a[i] >= a[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int len = *max_element(dp+1, dp+n+1);
        cout << n - len << endl;
    }
    return 0;
}