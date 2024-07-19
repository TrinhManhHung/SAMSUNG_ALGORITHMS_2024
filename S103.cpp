// TỔNG BÌNH PHƯƠNG

// TỔNG BÌNH PHƯƠNG

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
    init();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}