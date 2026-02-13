#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using vi = vector<int>;

string S;
int N;

// Returns {length (alpha chars only), leftmost index, rightmost index}
vi expandPalindrome(int left, int right) {
    int alphaCount = 0;
    int leftBound = left;
    int rightBound = right;
    
    // For odd-length palindromes starting at same position
    if (left == right && left < N && isalpha(S[left])) {
        alphaCount = 1;
        left--;
        right++;
    }
    
    while (true) {
        // Skip non-alphabetic characters
        while (left >= 0 && !isalpha(S[left])) left--;
        while (right < N && !isalpha(S[right])) right++;
        
        // Check if we can continue expanding
        if (left < 0 || right >= N || tolower(S[left]) != tolower(S[right])) {
            break;
        }
        
        // Found matching characters
        alphaCount += 2;
        leftBound = left;
        rightBound = right;
        left--;
        right++;
    }
    
    return {alphaCount, leftBound, rightBound};
}

int main() {
    // Read all input
    string line;
    while (getline(cin, line)) {
        S += line + "\n";
    }
    N = S.size();
    
    int maxLen = 0;
    int bestL = 0, bestR = 0;
    
    // Try each position as potential palindrome center
    for (int i = 0; i < N; i++) {
        // Odd-length palindromes (center at i)
        vi result = expandPalindrome(i, i);
        if (result[0] > maxLen) {
            maxLen = result[0];
            bestL = result[1];
            bestR = result[2];
        }
        
        // Even-length palindromes (center between i and i+1)
        result = expandPalindrome(i, i + 1);
        if (result[0] > maxLen) {
            maxLen = result[0];
            bestL = result[1];
            bestR = result[2];
        }
    }
    
    // Output the result
    cout << maxLen << "\n";
    cout << S.substr(bestL, bestR - bestL + 1);
    if (S[bestR] != '\n') cout << "\n";
    
    return 0;
}