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
                while (i < expression.size() && isdigit(expression[i])) {
                    res += expression[i++];
                }
                res += ' '; // Thêm khoảng trắng sau số để phân biệt những số có nhiều hơn 1 chữ số
                continue;
            }
            if (expression[i] == '(') {
                operators.push(expression[i]);
            }
            else if (is_operator(expression[i])) {
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
                operators.pop(); // Bỏ dấu '('
            }
            ++i;
        }
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
            if (isdigit(post_fix_expression[i])) {
                ll num = 0;
                while (i < post_fix_expression.size() && isdigit(post_fix_expression[i])) {
                    num = num * 10 + (post_fix_expression[i] - '0');
                    ++i;
                }
                operands.push(num);
            }
            else if (is_operator(post_fix_expression[i])) {
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
        return operands.top();
    }
};

#endif
