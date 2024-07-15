//KRUSKAL
#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second 

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
int V, E;
struct canh{
    int u, v, w;
};

bool cmp(canh a, canh b){
    return a.w < b.w;
}
vector<canh> adj;

void init(){
    adj.clear();
    cin >> V >> E;
    for(int i =1; i <=V; i++) parent[i] = i;
    for(int i =0; i <E; i++){
        canh tmp; cin >> tmp.u >> tmp.v >> tmp.w;
        adj.push_back(tmp);
    }
    sort(adj.begin(), adj.end(), cmp);
}
void process(){
    int res = 0;
    for(auto x : adj){
        if(Union(x.u, x.v)){
            res += x.w;
        }
    }
    cout << res << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        init();
        process();
    }
    return 0;
}