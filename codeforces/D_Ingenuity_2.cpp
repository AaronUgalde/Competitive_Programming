#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

std::pair<int,int> operator+(const std::pair<int,int>& a,
                             const std::pair<int,int>& b) {
    return { a.first  + b.first,
             a.second + b.second };
}

map<char, pair<int, int>> directions = {{'N', {0, 1}}, {'S', {0, -1}}, {'E', {1, 0}}, {'W', {-1, 0}}};
map<char, char> inverse = {{'N', 'S'}, {'S', 'N'}, {'E', 'W'}, {'W', 'E'}};

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> operations_frecuency;
    for(int i = 0; i<n; i++){
        operations_frecuency[s[i]]++;
    }

    set<char> odd;
    map<char, int> rober_operations;
    for(auto &[operation, frecuency] : operations_frecuency){
        if(frecuency % 2 != 0){
            odd.insert(operation);
        }
        rober_operations[operation] = frecuency/2;
    }

    bool giveToR = true;
    while (!odd.empty()) {
        char op = *odd.begin();
        odd.erase(op);

        char inv = inverse[op];
        if (!odd.count(inv)) {
            cout << "NO" << endl; 
            return;
        }
        odd.erase(inv);

        int offset = giveToR ? +1 : 0;
        rober_operations[op]      += offset;
        rober_operations[inv]     += offset;
        giveToR = !giveToR;
    }

    pair<int, int> pos_r = {0, 0}, pos_h = {0, 0};
    
    for(int i = 0; i<n; i++){
        if(rober_operations[s[i]]){
            rober_operations[s[i]]--;
            pos_r = pos_r + directions[s[i]];
            s[i] = 'R';
        }else{
            pos_h = pos_h + directions[s[i]];
            s[i] = 'H';
        }
    }
    
    if(s.size() == 2 && (s == "RR" || s == "HH")){
        cout << "NO" << endl;
        return;
    }

    cout << (pos_h == pos_r ? s : "NO: ") << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}