#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

char new_color(char a, char b){
    set<char> colors = {'R', 'G', 'B'};
    colors.erase(a);
    if(colors.count(b)) colors.erase(b);
    return *colors.begin();
}

int repaint(int i, int j, string &s){
    int total = (j - i + 1);
    for(int k = 0; k < total; k++){
        if(k % 2 != 0){
            s[i + k] = new_color(s[i + k - 1], s[i + k + 1]);
        }
    }
    return total / 2;
}

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;

    ll sum = 0;
    for(int i = 0; i < n - 1; i++){
        int j = i;
        while(j < n - 1 and s[j] == s[j + 1]){
            j++;
        }
        sum += repaint(i, j, s);
    }

    cout << sum << endl << s << endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}