#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // (n x m) x (m x k) = (n x k)
    int n = arr1.size(), m = arr2.size(), k = arr2[0].size();
    vector<vector<int>> answer(n, vector<int>(k, 0));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < k; c++) {
            for (int i = 0; i < m; i++) {
                answer[r][c] += arr1[r][i] * arr2[i][c];
            }
        }
    }
    return answer;
}