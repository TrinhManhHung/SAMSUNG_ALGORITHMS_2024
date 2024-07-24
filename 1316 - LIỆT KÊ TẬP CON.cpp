//LIỆT KÊ TẬP CON
#include<bits/stdc++.h>
using namespace std;

int n; string s;
set<string> se;
void Try(int bd, string tmp){
    for(int j =bd; j <=n; j++){
        tmp += s[j];
        se.insert(tmp);
        Try(j+1, tmp);
        tmp.pop_back();
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> s;
        s = " " + s;
        Try(1, "");
        for(auto x : se) cout << x << " ";
        cout << endl;
    }  
    return 0;
}