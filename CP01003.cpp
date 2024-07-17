// SỐ THUẦN NGUYÊN TỐ
#include<bits/stdc++.h>
using namespace std;

bool checknt(int n){
    if(n < 2) return false;
    for(int i =2; i * i <=n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
bool checknt2(int n){
    int sum = 0;
    int x = n;
    while(x > 0){
        int d = x % 10;
        if(d != 2 && d != 3 && d != 5 && d != 7) return false;
        sum += d;
        x /= 10;
    }
    if(!checknt(sum)) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        int cnt = 0;
        for(int i =l; i <=r; i++){
            if(checknt(i) && checknt2(i)){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}