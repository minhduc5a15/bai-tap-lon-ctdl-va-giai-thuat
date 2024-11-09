#ifndef CALC_EXPRESSION_H
#define CALC_EXPRESSION_H
#include "common.hpp"
#include "stack.hpp"

const unordered_map<char, int> precedence = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'(', 0}
};

inline ll calc(const ll a, const ll b, const char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::invalid_argument("division by zero");
            }
            return a / b;
        default:
            throw runtime_error("Invalid operation");
    }
}

inline bool is_operator(const char c) {
    return precedence.contains(c);
}

class calc_expression {
private:
    string expression;

public:
    calc_expression() : expression("") {}
    explicit calc_expression(const string &expression) : expression(expression) {}

    string get_expression() const { return expression; }

    string post_fix() const {
        string res;
        stack<char> operators;
        int i = 0;

        while (i < expression.size()) {
            if (isdigit(expression[i])) {
                // Đọc một số nguyên dương
                while (i < expression.size() && isdigit(expression[i])) {
                    res += expression[i++];
                }
                res += ' ';
                continue;
            }

            if (expression[i] == '(') {
                operators.push(expression[i]);
            }
            else if (expression[i] == '-' || expression[i] == '+') {
                // Kiểm tra nếu là số âm: đầu chuỗi hoặc sau dấu '('
                if (i == 0 || expression[i - 1] == '(') {
                    if (expression[i] == '-') res += '-';
                    ++i;
                    while (i < expression.size() && isdigit(expression[i])) {
                        res += expression[i++];
                    }
                    res += ' ';
                    continue;
                }
                // Xử lý '-' như toán tử trừ
                while (!operators.empty() && precedence.at(operators.top()) >= precedence.at(expression[i])) {
                    res += operators.top();
                    res += ' ';
                    operators.pop();
                }
                operators.push(expression[i]);
            }
            else if (is_operator(expression[i])) {
                // Đẩy các toán tử có độ ưu tiên cao hơn ra khỏi stack
                while (!operators.empty() && precedence.at(operators.top()) >= precedence.at(expression[i])) {
                    res += operators.top();
                    res += ' ';
                    operators.pop();
                }
                operators.push(expression[i]);
            }
            else if (expression[i] == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    res += operators.top();
                    res += ' ';
                    operators.pop();
                }
                operators.pop();
            }
            ++i;
        }

        // Đẩy các toán tử còn lại vào chuỗi hậu tố
        while (!operators.empty()) {
            res += operators.top();
            res += ' ';
            operators.pop();
        }

        return res;
    }


    ll calculate() const {
        const string post_fix_expression = this->post_fix();
        stack<ll> operands;
        int i = 0;

        while (i < post_fix_expression.size()) {
            if (isdigit(post_fix_expression[i]) || (post_fix_expression[i] == '-' && isdigit(post_fix_expression[i + 1]))) {
                // Đọc một số nguyên (có thể là âm)
                ll num = 0;
                bool is_negative = false;
                if (post_fix_expression[i] == '-') {
                    is_negative = true;
                    ++i;
                }
                while (i < post_fix_expression.size() && isdigit(post_fix_expression[i])) {
                    num = num * 10 + (post_fix_expression[i] - '0');
                    ++i;
                }
                if (is_negative) num = -num;
                operands.push(num);
            }
            else if (is_operator(post_fix_expression[i])) {
                if (operands.size() < 2) {
                    throw std::runtime_error("Invalid postfix expression: not enough operands");
                }
                const ll operand = operands.top();
                operands.pop();
                const ll prev_operand = operands.top();
                operands.pop();
                operands.push(calc(prev_operand, operand, post_fix_expression[i]));
                ++i;
            }
            else {
                ++i;
            }
        }

        if (operands.size() != 1) {
            throw std::runtime_error("Invalid postfix expression: stack should contain exactly one result");
        }

        return operands.top();
    }
};

#endif
