// ĐÁNH DẤU CHỮ CÁI

#include<bits/stdc++.h>
using namespace std;

int main(){
    set<char> se;
    string s; cin >> s;
    for(auto x : s) se.insert(x);
    cout << se.size() << endl;
    return 0;
}