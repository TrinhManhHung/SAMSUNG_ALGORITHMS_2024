// GIÁ TRỊ LỚN NHẤT

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n; cin >> n;
    ll res = 0;
    for(int i =0; i <n; i++){
        int x; cin >> x;
        if(x >= 0) res += 2*x;
    }
    cout << res << endl;
}