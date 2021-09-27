#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b;
    char c;
    string s;

    cin >> a >> b >> c >> s; // std input, splitted with whitespaces. cin will return true if input was successful. it will fail at EOF and return false.
    cout << a << b << c << s << endl;

    cin.ignore(); // cin will ignore whitespace, but it stayes in buffer. so you have to cin.ignore(); to cleaning up buffer.

    getline(cin, s); // std input, do not split with whitespaces. getline() of <string> will read one line as a whole.
    cout << s << endl;

    
    cin.get(c); // read one character including whitespace
    cout << c << endl;

    return 0;
}