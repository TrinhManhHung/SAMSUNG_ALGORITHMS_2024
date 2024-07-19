// TÌM SỐ DƯ

#include<bits/stdc++.h>
using namespace std;
void solve(string s, int n){
    if((s[n] - '0') % 2 == 1){
        cout << 0 << endl;
    }
    else{
        int tmp = (s[n-1] - '0') * 10 + (s[n] - '0');
        if(tmp % 4 == 0) cout << 4 << endl;
        else cout << 0 << endl;
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        s = " " + s;
        solve(s, n);
    } 
}