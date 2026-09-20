#include <vector>
#include <string>
#define MAX 101
using namespace std;

int solution(vector<string> arr)
{
    int n = (arr.size() + 1) / 2;
    vector<int> numbers;
    vector<string> operators;
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 1) 
            operators.push_back(arr[i]);
        else
            numbers.push_back(stoi(arr[i]));
    }
    vector<vector<int>> min_ij(MAX + 1, vector<int>(MAX + 1, 987654321));
    vector<vector<int>> max_ij(MAX + 1, vector<int>(MAX + 1, -987654321));
    for (int i = 0; i <= n; i++) {
        min_ij[i][i] = numbers[i];
        max_ij[i][i] = numbers[i];
    }
    
    for (int step = 1; step <= n - 1; step++) {
        for (int i = 0; i < n - step; i++) {
            int j = i + step;
            for (int k = i; k < j; k++) {
                if (operators[k] == "+") {
                    max_ij[i][j] = max(max_ij[i][j], max_ij[i][k] + max_ij[k + 1][j]);
                    min_ij[i][j] = min(min_ij[i][j], min_ij[i][k] + min_ij[k + 1][j]);
                }
                else if (operators[k] == "-") {
                    max_ij[i][j] = max(max_ij[i][j], max_ij[i][k] - min_ij[k + 1][j]);
                    min_ij[i][j] = min(min_ij[i][j], min_ij[i][k] - max_ij[k + 1][j]);
                }
            }
        }
    }
    return max_ij[0][n - 1];
}