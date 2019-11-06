#include <iostream>
#include <string>
/*
    给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

    Solution:
    if a[i, j] = 1, means string[i:j] is palindrome, therefore it's obviouse that:
        i) a[i + 1, j - 1] = a[i, j], if a[i] == a[j]
        ii) a[i, j] = 0, if not a[i] == a[j]
*/

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") {
            return s;
        }
        if (s.length() == 1) {
            return s;
        }
        this->init_matrix(s);
        string result_palindrome =  this->dp();
        this->delete_matrix();
        return result_palindrome;
    }

private:
    int l;
    int ** matrix;
    int max_length;
    string curr_string;
    int start;

    void delete_matrix() {
        for (int i = 0; i < l; i++) {
            delete [] matrix[i];
        }

        delete [] matrix;
    }

    void init_matrix(string s) {
        curr_string = s;
        max_length = 1;
        l = s.length();

        matrix = new int*[l];
        for (int i = 0; i < l; i++) {
            matrix[i] = new int[l];
            for (int j=0; j < l ; j++) {
                if (i == j) {
                    matrix[i][j] = 1;
                }
                else {
                    matrix[i][j] = 0;
                }
            }
        }

        /* is this necessary */
        for (int i = 0; i < l; i++) {
            if (i+1 < l && curr_string[i] == curr_string[i+1]) {
                matrix[i][i+1] = 1;
                max_length = 2;
            }
        }
    }

    string dp() {
        for (int v=3; v<=l; v++) {
            for (int i=0; i < l-v+1; i++) {
                if (curr_string[i] == curr_string[i+v-1] && matrix[i+1][i+v-2] == 1) {
                    matrix[i][i+v] = 1;
                    max_length = v;
                    start = i;
                }
            }
        }

        return curr_string.substr(start, max_length);
    }

    ~Solution() {
    }
};

int main(int argc, char * argv[]) {
    Solution * solution = new Solution();
    string curr_input;
    while (cin >> curr_input) {
        string longest_palindrome = solution->longestPalindrome(curr_input);

        std::cout << longest_palindrome << std::endl;
    }
    return 0;
}