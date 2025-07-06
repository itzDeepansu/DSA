class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int last = numbers.top();
                numbers.pop();
                int secondLast = numbers.top();
                numbers.pop();
                if (token == "+")
                    numbers.push(secondLast + last);
                else if (token == "-")
                    numbers.push(secondLast - last);
                else if (token == "*")
                    numbers.push(secondLast * last);
                else if (token == "/")
                    numbers.push(secondLast / last);
            } else {
                numbers.push(stoi(token));
            }
        }

        return numbers.top();
    }
};
