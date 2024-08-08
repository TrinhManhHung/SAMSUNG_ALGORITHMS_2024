// ĐƯỜNG ĐI CÓ HƯỚNG

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n, m, sta, en;
vector<int> adj[1005];
bool used[1005];
int truoc[1005];

void init(){
    cin >> n >> m >> sta >> en;
    for(int i =1; i <=n; i++) adj[i].clear();
    memset(used, false, sizeof(used));
    memset(truoc, 0, sizeof(truoc));
    for(int i =1; i <=m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
    }
    for(int i =1; i <=n; i++) sort(adj[i].begin(), adj[i].end());
}

void BFS(){
    queue<int> Q;
    Q.push(sta);
    used[sta] = true;
    while(!Q.empty() && !used[en]){
        int top = Q.front(); Q.pop();
        for(auto v : adj[top]){
            if(!used[v]){
                Q.push(v);
                truoc[v] = top;
                used[v] = true;
            }
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        init();
        BFS();
        vector<int> res;
        int tmp = en;
        while(truoc[tmp] != 0){
            res.pb(tmp);
            tmp = truoc[tmp];
        }
        if(res.size() < 2) cout << -1 << endl;
        else{
            reverse(res.begin(), res.end());
            cout << sta;
            for(auto x : res){
                cout << " -> " << x;
            }
            cout << endl;
        }
    }
    return 0;
}

// 6 9 1 6
// 1 2  
// 2 5
// 3 1
// 3 2
// 3 5
// 4 3
// 5 4
// 5 6
// 6 4