// SỐ NHỎ NHẤT

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int s, d; cin >> s >> d;
    if(s > d * 9){
        cout << -1 << endl;
    }
    else{
        int a[d+1] = {0};
        a[1] = 1;
        s = s - 1;
        for(int i =d; i >= 1; i--){
            if(s >= 9){
                a[i] += 9;
                s -= 9;
            }
            else{
                a[i] += s;
                s = 0;
            }
        }
        for(int i =1; i <=d; i++) cout << a[i];
        cout << endl;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}