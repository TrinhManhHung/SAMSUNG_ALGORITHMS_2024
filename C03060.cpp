// CHIA HẾT
#include<bits/stdc++.h>
using namespace std;

int process(int n){
    int cnt = 0;
    for(int i =2; i <=n; i++){
        int tmp = i;
        while(tmp % 2 == 0){
            cnt++;
            tmp /= 2;
        }
    }
    return cnt;
}
int main(){
    int n, k; cin >> n >> k;
    int h = process(n);
    if(h >= k) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}