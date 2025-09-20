#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())



void solve(int testcase){
    int h, m, s, t_1, t_2; 
    cin >> h >> m >> s >> t_1 >> t_2;

    m = (m == 0 ? 60 : m);
    s = (s == 0 ? 60 : s);
    h *= 60;
    m *= 12;
    s *= 12;
    t_1 *= 60;
    t_2 *= 60;
    
    h %= 720;
    m %= 720;
    s %= 720;
    t_1 %= 720;
    t_2 %= 720;
     
    //cout << "h: " << h << " m: " << m << " s: " << s << " t_1: " << t_1 << " t_2: " << t_2 << endl;

    bool f1 = true;
    //cout << " t_1 -> t_2" << endl; 
    for(int i = t_1; i != t_2; i = (i + 1) % 720){
        //cout << "i: " << i << endl;
        if(i == h || i == m || i == s) f1 = false;
    }

    bool f2 = true;
    //cout << " t_2 -> t_1" << endl; 
    for(int i = t_2; i != t_1; i = (i + 1) % 720){
        //cout << "i: " << i << endl;
        if(i == h || i == m || i == s) f2 = false;
    } 

    if(f1 == false && f2 == false) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}