#include "src/A/app.hpp"
#include "src/B/calc_expression.hpp"

void run_A() {
	App app;
	app.run();
}

void run_B() {
	const calc_expression expression("123+54*(17+65*(65-12))");

	cout << expression.calculate() << endl;
}

int main() {
	run_B();
 	return 0;
}