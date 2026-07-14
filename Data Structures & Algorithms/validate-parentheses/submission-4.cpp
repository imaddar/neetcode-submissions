class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) { return false; }
        stack<char> parens;
        parens.push(' ');
        while (!s.empty()) {
            if (s[0] == ')') {
                if (parens.top() != '(') { return false; }
                parens.pop();
            }
            else if (s[0] == ']') {
                if (parens.top() != '[') { return false; }
                parens.pop();
            }
            else if (s[0] == '}') {
                if (parens.top() != '{') { return false; }
                parens.pop();
            }
            else {
                parens.push(s[0]);
            }
            s.erase(s.begin());

            
        }
        parens.pop();
        if (!parens.empty()) { return false; }
        return true;
    }
};
