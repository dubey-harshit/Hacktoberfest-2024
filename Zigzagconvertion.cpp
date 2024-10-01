#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s; 
        
        string ans;
        vector<vector<char>> rows(numRows);
        int k = 0;
        int direction = -1; 

        for (const char c : s) {
            rows[k].push_back(c);
            if (k == 0 || k == numRows - 1)
                direction *= -1;
            k += direction;
        }

        for (const vector<char>& row : rows)
            for (const char c : row)
                ans += c;

        return ans;
    }
};

int main() {
    Solution solution;
    string input;
    int numRows;

    
    cout << "Enter a string: ";
    getline(cin, input);
    cout << "Enter the number of rows: ";
    cin >> numRows;

    string result = solution.convert(input, numRows);
    cout << "Converted string: " << result << endl;

    return 0;
}
