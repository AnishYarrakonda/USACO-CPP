#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll BASE = 26;

ll computeHash(const string& s) {
    ll hash = 0;
    for (char c : s) {
        hash = (hash * BASE + (c - 'a')) % MOD;
    }
    return hash;
}

ll modPow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

string censor(const string& S, const string& T) {
    if (T.empty() || S.empty()) return S;
    
    int m = T.size();
    ll patternHash = computeHash(T);
    ll power = modPow(BASE, m - 1, MOD);  // BASE^(m-1) for rolling hash
    
    vector<char> result;  // Stack to build censored string
    vector<ll> hashes;    // Stack of rolling hashes
    
    for (char c : S) {
        result.push_back(c);
        
        // Compute rolling hash
        ll currentHash = 0;
        if (result.size() < m) {
            // Build up initial hash
            if (hashes.empty()) {
                currentHash = (c - 'a');
            } else {
                currentHash = (hashes.back() * BASE + (c - 'a')) % MOD;
            }
        } else if (result.size() == m) {
            // First complete window
            currentHash = computeHash(string(result.begin(), result.end()));
        } else {
            // Rolling hash: remove leftmost of window, add new char
            char oldChar = result[result.size() - m - 1];
            currentHash = hashes.back();
            currentHash = (currentHash - ((oldChar - 'a') * power) % MOD + MOD) % MOD;
            currentHash = (currentHash * BASE + (c - 'a')) % MOD;
        }
        
        hashes.push_back(currentHash);
        
        // Check for match
        if (result.size() >= m && currentHash == patternHash) {
            // Verify the match (avoid hash collisions)
            bool match = true;
            for (int i = 0; i < m; i++) {
                if (result[result.size() - m + i] != T[i]) {
                    match = false;
                    break;
                }
            }
            
            if (match) {
                // Remove pattern
                for (int i = 0; i < m; i++) {
                    result.pop_back();
                    hashes.pop_back();
                }
                
                // Recompute hash after deletion
                if (result.size() >= m) {
                    currentHash = computeHash(
                        string(result.end() - m, result.end())
                    );
                    hashes.back() = currentHash;
                }
            }
        }
    }
    
    return string(result.begin(), result.end());
}

int main() {
    freopen("censor.in","r",stdin);
    freopen("censor.out","w",stdout);
    
    string S, T;
    cin >> S >> T;
    
    string result = censor(S, T);
    cout << result << endl;
    
    return 0;
}