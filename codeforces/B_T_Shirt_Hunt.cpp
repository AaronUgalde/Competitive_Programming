#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

void solve(int testcase){
    int p, x, y; cin >> p >> x >> y;

    auto is_p = [&](int score){    
        int i = (score / 50) % 475;
        for(int j = 0; j<25; j++){
            i = (i * 96 + 42) % 475;
            if(p == (26 + i)) return true;
        }
        return false;
    };

    int first_digits_x = (x/10 % 10) * 10 + x%10;
    int first_digits_y = (y/10 % 10) * 10 + y%10;

    int start = 0;
    if(first_digits_x < first_digits_y){
        start = y - first_digits_y + first_digits_x + 50;
        if(start < y) start += 50;
    }else{
        if(first_digits_x - 50 == first_digits_y) start = y;
        else start = y - first_digits_y + first_digits_x;
    }

    for(int i = 0; i<475; i++){
        if(is_p(start)) break;
        start += 50;
    }

    int diff = start - x;
    if(diff <= 0){
        cout << 0 << endl;
        return;
    }

    cout << (diff / 100) + (diff % 100 > 0) << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}