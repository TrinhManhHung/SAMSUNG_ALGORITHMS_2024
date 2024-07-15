//KIỂM TRA CHU TRÌNH
#include<bits/stdc++.h>
using namespace std;

int V, E;
int parent[1005];
int Find(int u){
    if(parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}
bool Union(int u, int v){
    int rootu = Find(u);
    int rootv = Find(v);
    if(rootu != rootv){
        if(rootu < rootv) parent[rootv] = rootu;
        else parent[rootu] = rootv;
        return true;
    }
    return false;
}
void solve(){
    bool check = false;
    cin >> V >> E;
    for(int i=1; i<=V; i++) parent[i] = i;
    for(int i =0; i <E; i++){
        int x, y; cin >> x >> y;
        if(!Union(x, y)) check = true;
    }
    if(check) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}