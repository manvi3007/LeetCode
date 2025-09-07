#include <string>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        bool foundB = false;
        for (char c : s) {
            if (c == 'b') foundB = true;
            if (foundB && c == 'a') return false; 
        }
        return true;
    }
};
