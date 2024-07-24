// TÍCH LỚN NHẤT

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n+1];
    for(int i =1; i <=n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    int res = max({a[1] * a[2],  a[n] * a[n-1]}); // truong hop 2 so
    res = max({a[1] * a[2] * a[3],                // truong hop 3 so
               a[n] * a[n-1] * a[n-2],
               a[1] * a[2] * a[n]
            });
    cout << res << endl;
}