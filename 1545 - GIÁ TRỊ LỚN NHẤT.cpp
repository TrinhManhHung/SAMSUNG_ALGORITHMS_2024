//SEGMENT TREE

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 100000;
ll a[maxn+5];
ll t[4*maxn+5]; 

void update(int v, int l, int r, int pos, int val){ //t[v] luu max cua doan [l, r]
    if(l == r){
        t[v] = val;
    }
    else{
        int mid = (l + r) / 2;
        if(pos <= mid){
            update(2*v, l, mid, pos, val);
        }
        if(pos > mid){
            update(2*v + 1, mid+1, r, pos, val);
        }
        t[v] = max(t[2*v], t[2*v + 1]);
    }
}
ll getMax(int v, int l, int r, int x, int y){ //tim max tren doan [x, y]
    if(x > y) return LLONG_MIN;
    if(x == l && y == r){
        return t[v];
    }
    else{
        int mid = (l + r) / 2;
        ll maxLeft = getMax(2*v, l, mid, x, min(y, mid));
        ll maxRight = getMax(2*v + 1, mid+1, r, max(x, mid+1), y);
        return max(maxLeft, maxRight);
    }
}
int main(){
    int n, m; cin >> n >> m;
    memset(a, 0, sizeof(a));
    for(int i =0; i <m; i++){
        int l, r, k; cin >> l >> r >> k;
        a[l] += k;
        a[r+1] -= k;
    }
    for(int i =1; i <=n; i++){
        a[i] = a[i-1] + a[i];
        update(1, 1, n, i, a[i]);
    }
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << getMax(1, 1, n, l, r) << endl;
    }
    return 0;
}