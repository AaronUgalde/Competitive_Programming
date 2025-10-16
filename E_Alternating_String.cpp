#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define dbg(x) (cerr << #x << " = " << (x) << '\n')

void solve(int testcase){
    int n; cin >> n;
    string s; cin >> s;
    if(n % 2 == 0){
        vector<vector<int>> appears(2, vector<int>(26));
        for(int i = 0; i < n; i++){
            appears[i % 2][s[i] - 'a']++;
        }

        vector<int> mx(2);
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 26; j++)
                mx[i] = max(mx[i], appears[i][j]);

        int operations = n;
        for(int i = 0; i < 2; i++) operations -= mx[i];
        cout << "test: " << testcase << endl;
        cout << operations << endl;
        return;
    }

    // if n % 2 != 0
    /*
    Tenemos que realizar el sufijo para pares e impares de cuantas veces aparece 
    cada char en todo el arreglo sin contar el primero

    Construir el prefijo mientras vamos probando todas las posibilidades de 
    eliminacion

    Actualizar el maximo iterando sobre todos los caracteres
    */
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i = 0; i<t; i++){
        solve(i);
    }
}