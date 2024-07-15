//SUM TRIPLE ZERO
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n+1];
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    int count = 0;
    for(int i=1; i <=n-2; i++){
        int left = i+1;
        int right = n;
        while(left < right){
            int tmp = a[i] + a[left] + a[right];
            if(tmp == 0){
                count++;
                left++;
            }
            else if(tmp > 0){
                right--;
            }
            else left++;
        }
    }
    cout << count << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}