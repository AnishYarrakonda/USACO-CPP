#include <bits/stdc++.h>
using namespace std;

bool isPrefix(const string& message, const string& phrase) {
    if (message.size() > phrase.size()) return false;
    return phrase.substr(0, message.size()) == message;
}

int main() {
    int M, N;
    cin >> M >> N;
    cin.ignore();
    
    vector<string> phrases(M);
    for (int i = 0; i < M; i++) {
        getline(cin, phrases[i]);
    }
    
    vector<string> messages(N);
    for (int i = 0; i < N; i++) {
        getline(cin, messages[i]);
    }
    
    // Sort the book phrases for efficient searching
    sort(phrases.begin(), phrases.end());
    
    int count = 0;
    
    for (const string& message : messages) {
        // Binary search to find where this message would fit
        auto it = lower_bound(phrases.begin(), phrases.end(), message);
        
        // Check phrases starting from the lower_bound position
        // Since they're sorted, potential matches are clustered together
        bool found = false;
        for (auto check = it; check != phrases.end() && !found; check++) {
            // If phrase doesn't start with message's first char, we've gone too far
            if (check->empty() || (*check)[0] != message[0]) break;
            
            if (isPrefix(message, *check)) {
                found = true;
            }
            
            // Optimization: if current phrase is lexicographically greater
            // than message + 'z', no more matches possible
            if (*check > message + "~") break;
        }
        
        if (found) count++;
    }
    
    cout << count << endl;
    
    return 0;
}