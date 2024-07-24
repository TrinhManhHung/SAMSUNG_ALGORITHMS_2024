// SỐ NHỎ NHẤT
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n; 
ll m;
ll a[35];
int res = 35;

void Try(int bd, int cnt, ll cursum) {
    if (cursum == m) {
        res = min(res, cnt);
        return;
    }
    if (cursum > m || bd > n || cnt >= res) return;

    for (int j = bd; j <= n; j++) {
        if (cursum + a[j] <= m) {
            Try(j + 1, cnt + 1, cursum + a[j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    // Sort array in descending order
    sort(a + 1, a + n + 1, greater<ll>());
    
    Try(1, 0, 0);
    
    if (res == 35) cout << -1 << endl;
    else cout << res << endl;
    
    return 0;
}
