#include <iostream>
#include <string>

using namespace std;

class RecursiveDescentParser {
public:
    RecursiveDescentParser(const string& input) : input(input), pos(0) {}

    bool parse() {
        return S() && pos == input.length();
    }

private:
    string input;
    size_t pos;

    bool S() {
        if (pos < input.length() && input[pos] == 'a') {
            pos++;
            return true;
        } else if (pos < input.length() && input[pos] == '(') {
            pos++;
            if (L() && pos < input.length() && input[pos] == ')') {
                pos++;
                return true;
            }
        }
        return false;
    }

    bool L() {
        if (S()) {
            return L_prime();
        }
        return false;
    }

    bool L_prime() {
        if (pos < input.length() && input[pos] == ',') {
            pos++;
            if (S()) {
                return L_prime();
            }
            return false;
        }
        return true; // epsilon transition
    }
};

int main() {
    string input;
    cout << "Enter a string to validate: ";
    cin >> input;

    RecursiveDescentParser parser(input);
    if (parser.parse()) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }

    return 0;
}