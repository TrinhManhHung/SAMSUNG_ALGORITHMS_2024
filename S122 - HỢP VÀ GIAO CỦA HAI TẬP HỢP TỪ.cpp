// HỢP VÀ GIAO CỦA HAI TẬP HỢP TỪ

#include<bits/stdc++.h>
using namespace std;

void changeLowerCase(string &s){
    for(auto &x : s){
        x = tolower(x);
    }
}
int main(){
    string s1; getline(cin, s1);
    string s2; getline(cin, s2);
    //chuyển về in thường
    changeLowerCase(s1);
    changeLowerCase(s2);
    //tách các từ
    vector<string> v1; 
    vector<string> v2;
    stringstream ss1(s1);
    string word;
    while(ss1 >> word){
        v1.push_back(word);
    }
    stringstream ss2(s2);
    while(ss2 >> word){
        v2.push_back(word);
    }
    //xử lí
    set<string> se;
    map<string, int> mp;
    for(auto x : v1){
        se.insert(x);
        mp[x] = 1;
    }
    for(auto x : v2){
        se.insert(x);
        if(mp[x] == 1) mp[x] = 2;
    }
    for(auto x : se) cout << x << " ";
    cout << endl;
    for(auto x : mp){
        if(x.second == 2) cout << x.first << " ";
    }
}
// Lap trinh huong doi tuong
// Ngon ngu lap trinh C++