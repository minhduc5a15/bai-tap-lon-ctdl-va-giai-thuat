#include "src/A/app.hpp"
#include "src/B/calc_expression.hpp"

void run_A() {
    App app;
    app.run();
}

void run_B() {
    // Trường hợp dấu - đứng đầu
    calc_expression expression("-123 + 72313 * (-123)");
    cout << "postfix expression = " << expression.post_fix() << endl;
    cout << expression.get_expression() << " = " << expression.calculate() << endl;
    // Trường hợp dấu + đứng đầu
    expression = calc_expression("-123 + 72313 * (+123)");
    cout << "postfix expression = " << expression.post_fix() << endl;
    cout << expression.get_expression() << " = " << expression.calculate() << endl;
    // Trường hợp bình thường
    expression = calc_expression("1+2+3+4+5+6+7+8+9+10*(11*(12-13)+13*(14+15))/5");
    cout << "postfix expression = " << expression.post_fix() << endl;
    cout << expression.get_expression() << " = " << expression.calculate() << endl;
}

int main() {
    run_B();
    return 0;
}