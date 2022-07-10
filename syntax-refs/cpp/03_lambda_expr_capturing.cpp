#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	
	/**
	 * This is how to specify capture :
	 *     [] : no capturing. you can't use variables outside the scope.
	 *     [&] : capture all variables outside the scope by reference.
	 *     [=] : capture all variables outside the scope by value.
	 *     [&variableName] : capture specified variable by reference.
	 *     [=variableName] : capture specified variable by value.
	 *
	 * Example below is to show how to use Capturing of Lambda expr.
	 *     sort target string by character frequency & ASCII.
	 */

	unordered_map<char, int> m;
	string strIn = "CapturingOfLambdaExpr";

	for(const auto& ch : strIn) {
		if(m.count(ch) == 0) {
			m[ch] = 0;
		}
		m[ch]++;
	}

	sort(strIn.begin(), strIn.end(), [&m](const char& ch1, const char& ch2) {
		if(m[ch1] != m[ch2]) {
			return m[ch1] > m[ch2];
		}
		return ch1 > ch2;
	});

	cout << strIn << endl; // result is "aaarrppxutnmigfdbOLEC"
	return 0;
}
