#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(int testcase){
    int q; cin >> q;
    map<int, int> bag;

    int different = 0;
    for(int i = 0; i<q; i++){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            if(bag[x] == 0) different++;
            bag[x]++;
        }else if(type == 2){
            int x; cin >> x;
            if(bag[x] == 1) different--;
            bag[x]--;
        }else{
            cout << different << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}