//MIN TRIPLE

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int min1 = 1e9, min2 = 1e9, min3 = 1e9;
        for(int i =0; i <n; i++){
            int x; cin >> x;
            if(x >= min3) continue;
            if(x < min1){
                min3 = min2;
                min2 = min1;
                min1 = x;
            }
            else if(x < min2){
                min3 = min2;
                min2 = x;
            }
            else if(x < min3){
                min3 = x;
            }
        }
        cout << min1 + min2 + min3 << endl;
    }
    return 0;
}