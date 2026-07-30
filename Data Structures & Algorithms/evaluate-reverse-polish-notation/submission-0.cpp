class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int x, y, z;
        stack<int> s;
        for (string c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/"){

                y = s.top();
                s.pop();
                x = s.top();
                s.pop();

                if (c == "+"){
                    z = x + y;
                }
                else if (c == "-"){
                    z = x - y;
                }
                else if (c == "*"){
                    z = x * y;
                }
                else {
                    z = x / y;
                }
                s.push(z);

            }
            else {
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};
