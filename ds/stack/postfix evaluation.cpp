#include <iostream>
#include <stack>
#include <cctype> // for isalnum()

// Function to check if a character is an operand (letter or digit)
bool isOperand(char c) {
    return isalnum(c) != 0;
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}

// Function to convert infix expression to postfix expression
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operatorStack;
    std::string postfix;

    for (char c : infix) {
        if (isOperand(c)) {
            postfix += c;
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop '('
        } else {
            // Operator
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // Pop remaining operators from the stack
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string infixExpression;
    
    // Input infix expression
  
    std::cout << "Enter the normal expression: ";
    std::getline(std::cin, infixExpression);

    // Convert to postfix and display the result
    std::string postfixExpression = infixToPostfix(infixExpression);
    std::cout << "Postfix expression: " << postfixExpression << std::endl;
 std::cout << ": ";
    return 0;
}
------------
/ postfix 
#include <iostream>
#include <stack>

using namespace std;

int isOperator(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/') {
    return 1;
  } else {
    return 0;
  }
}

int evaluate(char c, int operand1, int operand2) {
  switch (c) {
    case '+':
      return operand1 + operand2;
    case '-':
      return operand1 - operand2;
    case '*':
      return operand1 * operand2;
    case '/':
      return operand1 / operand2;
  }
}

int main() {
  string postfixExpression;
  stack<int> s;

  cout << "Enter postfix expression: ";
  cin >> postfixExpression;

  for (int i = 0; i < postfixExpression.length(); i++) {
    char ch = postfixExpression[i];

    if (isdigit(ch)) {
      s.push(ch - '0');
    } else if (isOperator(ch)) {
      int operand1 = s.top();
      s.pop();

      int operand2 = s.top();
      s.pop();

      int result = evaluate(ch, operand1, operand2);
      s.push(result);
    }
  }

  cout << "Result: " << s.top() << endl;
	cout<<" \n "<<endl;
  return 0;
}