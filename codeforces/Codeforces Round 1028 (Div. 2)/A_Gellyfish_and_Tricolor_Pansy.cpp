#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()


void solve(int testcase){
    int a, b, c, d; cin >> a >> b >> c >> d;
    int mn_g = min(a, c);
    int mn_f = min(b, d);
    if(mn_g >= mn_f){
        cout << "Gellyfish" << endl;
    }else{
        cout << "Flower" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}