#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}

string add(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());
    int carry = 0;
    int sum_col;  // sum of the digits in the same column
    string res;

    // pad the shorter string with zeros
    while (lhs.size() < length)
        lhs.insert(0, "0");
    while (rhs.size() < length)
        rhs.insert(0, "0");

    // add them up from right to left
    for (int i = length - 1; i >= 0; i--) {
        sum_col = (lhs[i] - '0') + (rhs[i] - '0') + carry;
        carry = sum_col / 10;
        res.insert(0, to_string(sum_col % 10));
    }
    if (carry)
        res.insert(0, to_string(carry));

    // remove leading zeros
    return res.erase(0, min(res.find_first_not_of('0'), res.size() - 1));
}

string subtract(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());
    int diff;
    string res;

    // pad the shorter string with zeros
    while (lhs.size() < length)
        lhs.insert(0, "0");
    while (rhs.size() < length)
        rhs.insert(0, "0");

    // subtract them from right to left
    for (int i = length - 1; i >= 0; i--) {
        diff = (lhs[i] - '0') - (rhs[i] - '0');
        if (diff >= 0)
            res.insert(0, to_string(diff));
        else {
            // borrow one from previous column
            int j = i - 1;
            while (j >= 0) {
                lhs[j] = ((lhs[j] - '0') - 1) % 10 + '0';
                if (lhs[j] != '9')
                    break;
                else
                    j--;
            }
            res.insert(0, to_string(diff + 10));
        }
    }

    // remove leading zeros
    return res.erase(0, min(res.find_first_not_of('0'), res.size() - 1));
}

string multiply(string lhs, string rhs) {
    int length = max(lhs.size(), rhs.size());

    // pad the shorter string with zeros
    while (lhs.size() < length)
        lhs.insert(0, "0");
    while (rhs.size() < length)
        rhs.insert(0, "0");

    if (length == 1)
        return to_string((lhs[0] - '0') * (rhs[0] - '0'));

    // get a, b, c, d from the original number
    string a = lhs.substr(0, length / 2);
    string b = lhs.substr(length / 2, length - length / 2);
    string c = rhs.substr(0, length / 2);
    string d = rhs.substr(length / 2, length - length / 2);

    // the main body of Karatsuba Multiplication
    string p0 = multiply(a, c);
    string p1 = multiply(b, d);
    string p2 = multiply(add(a, b), add(c, d));
    string p3 = subtract(p2, add(p0, p1));

    for (int i = 0; i < 2 * (length - length / 2); i++)
        p0.append("0");
    for (int i = 0; i < (length - length / 2); i++)
        p3.append("0");

    string res = add(add(p0, p1), p3);

    // remove leading zeros
    return res.erase(0, min(res.find_first_not_of('0'), res.size() - 1));
}

int main() {
    string num1, num2;
    cout << "number 1: ";
    cin >> num1;
    cout << endl;
    cout << "number 2: ";
    cin >> num2;
    cout << endl;
    cout << "result: " << multiply(num1, num2) << endl;
    return 0;
}