class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                
                int num1 = operands.top(); 
                operands.pop();
                
                int num2 = operands.top(); 
                operands.pop();

                if (tokens[i] == "+") {
                    operands.push(num2 + num1);
                } else if (tokens[i] == "-") {
                    operands.push(num2 - num1);
                } else if (tokens[i] == "*") {
                    operands.push(num2 * num1);
                } else if (tokens[i] == "/") {
                    operands.push(num2 / num1); 
                }
            } else {
            
                operands.push(stoi(tokens[i])); //stoi để chuyển string to int
            }
        }

        return operands.top();
    }
};