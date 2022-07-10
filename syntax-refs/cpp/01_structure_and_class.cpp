#include <iostream>

using namespace std;

/**
 * In cpp, struct is almost same as class.
 *     The difference is that by default members of struct are public whereas members of class are private.
 */

struct DotAIO {
    // These members has public access specifiers by default.
    string strColor;

    void bape() {
        cout << "sweeet" << endl;
    }

private:
    //You can limit access to private by private access specifiers
    string strWhoAmI = "DotAIO";

public:
    //You can limit access to public by public access specifiers
    void printWhoAmI() {
        // "this" keyword is defined pointer. so you must use arrow(->) operator.
        cout << this->strWhoAmI << ' ';

        // NOTE: double-colon operator(::) is to limit the scope of access. you can use this after classes, structs, namespaces.
        //     if you use double-colon operator by itself, like "::foo", you can seperate the global variables, functions, or anything else from local one.
        DotAIO::bape();
    }
}; // You must add semicolon when struct or class declaration ends.

class DotStick {
    // These members has private access specifiers by default.
    string strColor;

    void bape() {
        cout << "sweeet" << endl;
    }

private:
    string strWhoAmI = "DotStick";

public:
    void printWhoAmI() {
        cout << this->strWhoAmI << ' ';
        DotStick::bape();
    }
};

struct DotBox {
    string strColor;
    int nPrice;
};

int main() {
    DotAIO dotaio;
    DotStick dotstick;
    DotAIO* dotaio1 = new DotAIO;
    DotStick* dotstick1 = new DotStick;

    // You must use the arrow (->) operator to access members of a struct or class pointer.
    //     and must use the dot(.) operator to access members of struct or class.
    dotaio.printWhoAmI(); // result is DotAIO sweeet.
    dotaio1->printWhoAmI(); // result is DotAIO sweeet.
    dotstick.printWhoAmI(); // result is DotStick sweeet.
    dotstick1->printWhoAmI(); // result is DotStick sweeet.

    // As cpp's class members has private access specifiers by default, you can't use access-not-specified members outside of class.
    dotaio.bape(); // this is not error! result is sweeet.
    // dotstick.bape(); => this is error!

    // If structure has fields only, you can initiate structure by {}, not ().
    //     beware of difference between string and char*.
    DotBox* dotbox = new DotBox{string("black"), 120};
}