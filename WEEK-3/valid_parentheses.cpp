class Solution {
public:
    bool isValid(string s) {
        stack<char> keep;
        for (char c : s) {
            if (c == ')') {
                if (keep.empty()) return false;
                else if (keep.top() != '(') return false;
                else keep.pop();
            }
            else if (c == '}') {
                if (keep.empty()) return false;
                else if (keep.top() != '{') return false;
                else keep.pop();
            }
            else if (c == ']') {
                if (keep.empty()) return false;
                else if (keep.top() != '[') return false;
                else keep.pop();
            }
            else keep.push(c);
        }
        if (keep.empty()) return true;
        else return false;
        
    }
};