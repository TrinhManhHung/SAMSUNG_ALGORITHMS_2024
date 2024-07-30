// LỰA CHỌN TỐI ƯU

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
void solve(){
    int n; cin >> n;
    vector<pair<int, int>> v;
    for(int i =0; i <n; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);

    int dem = 0; int curEnd = -1;
    for(auto x : v){
        if(x.first >= curEnd){
            dem++;
            curEnd = x.second;
        }
    }
    cout << dem << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}