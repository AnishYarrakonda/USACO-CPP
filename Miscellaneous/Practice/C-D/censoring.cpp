#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
typedef long long ll;

int main() {
    freopen("censor.in","r",stdin);
    freopen("censor.out","w",stdout);
    
    string S, T;
    cin >> S >> T;
    
    int M = T.length();
    string result = "";

    for (char c : S) {
        result += c;
        if (result.length() >= M and result.substr(result.length()-M, M) == T) {
            result.erase(result.length()-M);
        }
    }
    
    cout << result << endl;

    return 0;
}