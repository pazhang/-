#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

        if (m <= 0 || n <= 0) {
            return 0;
        }

        std::vector<std::vector<int> > f(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    cout << "A" << endl;
                    f[i][j] = 1;
                } else if (i == 1) {
                    cout << "B" << endl;
                    f[i][j] = j + 1;
                } else if (j == 1) {
                    cout << "C" << endl;
                    f[i][j] = i + 1;
                } else {
                    cout << "D" << endl;
                    f[i][j] = f[i][j-1] + f[i-1][j];
                }
            }
        }

        return f[n-1][m-1];
    }
};


int main(int argc, char * argv[]) {
    Solution * solution = new Solution();
    int m, n;
    cin >> m >> n;

    cout << solution->uniquePaths(m, n) << endl;
    return 0;
}
