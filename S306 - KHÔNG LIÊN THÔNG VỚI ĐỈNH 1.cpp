// KHÔNG LIÊN THÔNG VỚI ĐỈNH 1

#include<bits/stdc++.h>
using namespace std;

int parent[500];

int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
void Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u != v){
        if(u < v) parent[v] = u;
        else parent[u] = v;
    }
}

int main(){
    int n, m; cin >> n >> m;
    for(int i =1; i <=n; i++) parent[i] = i;
    for(int i =1; i <=m; i++){
        int x, y; cin >> x >> y;
        Union(x, y);
    }
    bool check = false;
    for(int i =2; i <=n; i++){
        parent[i] = Find(parent[i]);
        if(parent[i] != 1){
            check = true;
            cout << i << "\n";
        }
    }
    if(check == false) cout << 0 << endl;
    return 0;
}