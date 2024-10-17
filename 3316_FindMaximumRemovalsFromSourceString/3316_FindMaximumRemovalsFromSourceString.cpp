
// class Solution {
// public:
//     int M, N;
//     unordered_set<int> s;
//     vector<vector<int>> memo;

//     int dp(int i, int j, const string& source, const string& pattern) {
//         // If we have reached the end of the source and pattern
//         if (i == M && j == N) {
//             return 0;
//         }
//         // If we have reached the end of the source but not the pattern
//         if (i == M) {
//             return -1e9; // Represents -inf as in the Python code
//         }

//         // Return memoized result if available
//         if (memo[i][j] != -1) {
//             return memo[i][j];
//         }

//         // Calculate the result without taking the current character
//         int res = dp(i + 1, j, source, pattern);

//         // Calculate the result if we take the current character (if it matches)
//         if (j < N && source[i] == pattern[j]) {
//             res = max(res, dp(i + 1, j + 1, source, pattern));
//         }

//         // Calculate the result if we perform the "removal" operation
//         if (s.count(i)) {
//             res = max(res, dp(i + 1, j, source, pattern) + 1);
//         }

//         // Memoize and return the result
//         memo[i][j] = res;
//         return res;
//     }

//     int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
//         M = source.size();
//         N = pattern.size();
//         s = unordered_set<int>(targetIndices.begin(), targetIndices.end());
//         memo = vector<vector<int>>(M + 1, vector<int>(N + 1, -1));

//         // Call the dp function starting from index 0 for both source and pattern
//         int ans = dp(0, 0, source, pattern);
        
//         return ans;
//     }
// };
class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int M = source.size(), N = pattern.size();
        unordered_set<int> s(targetIndices.begin(), targetIndices.end());

        // Initialize a 2D vector with size (M+1) x (N+1) and set all values to -infinity.
        vector<vector<int>> f(M + 1, vector<int>(N + 1, -INT_MAX));
        f[M][N] = 0; // Base case: if both source and pattern are fully traversed.

        // Traverse the source string in reverse.
        for (int i = M - 1; i >= 0; --i) {
            for (int j = N; j >= 0; --j) {
                // Option 1: Do not take the character from source[i].
                int res = f[i + 1][j] + (s.count(i) ? 1 : 0);

                // Option 2: Take the character if it matches the pattern[j].
                if (j < N && source[i] == pattern[j]) {
                    res = max(res, f[i + 1][j + 1]);
                }

                // Store the best result in f[i][j].
                f[i][j] = res;
            }
        }

        // The result is stored in f[0][0], representing the maximum removals from the start.
        return f[0][0];
    }
};