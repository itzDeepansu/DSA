class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (auto token : tokens) {
            if (token == "+") {
                int last = numbers.top();
                numbers.pop();
                int secondLast = numbers.top();
                numbers.pop();
                numbers.push(secondLast + last);
            } else if (token == "-") {
                int last = numbers.top();
                numbers.pop();
                int secondLast = numbers.top();
                numbers.pop();
                numbers.push(secondLast - last);
            } else if (token == "*") {
                int last = numbers.top();
                numbers.pop();
                int secondLast = numbers.top();
                numbers.pop();
                numbers.push(secondLast * last);
            } else if (token == "/") {
                int last = numbers.top();
                numbers.pop();
                int secondLast = numbers.top();
                numbers.pop();
                numbers.push(secondLast / last);
            } else
                numbers.push(stoi(token));
        }
        return numbers.top();
    }
};