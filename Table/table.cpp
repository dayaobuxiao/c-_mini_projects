#include "pch.h"
#include "table.h"
#include <vector>
using std::vector;
#include <random>
#include <limits>
#include<iostream>
using std::cout; using std::endl; using std::boolalpha; using std::ostream;
#include <exception>
using std::exception;

Table::Table(long width, long height, long val) {
    width_ = width;
    height_ = height;
    t_ = vector<vector<long>>(height_, vector<long>(width_, val));
}

void Table::fill_random(long lo, long hi, unsigned int seed) {
    std::mt19937 generator(seed);
    std::uniform_int_distribution<long> distribution(lo, hi);
    for (auto i = 0; i != height_; i++) {
        for (auto j = 0; j != width_; j++) {
            t_[i][j] = distribution(generator);
        }
    }
}
bool Table::set_value(unsigned int row_num, unsigned int col_num, long val) {
    if (row_num < height_ && col_num < width_) {
        t_[row_num][col_num] = val;
        return true;
    }
    else {
        return false;
    }
}
long Table::get_value(unsigned int row_num, unsigned int col_num) const {
    if (row_num < height_ && col_num < width_) {
        return t_[row_num][col_num];
    }
    else {
        return std::numeric_limits<long>::lowest();
    }
}
void Table::print_table(ostream& out) {
    for (auto i = 0; i != height_; i++) {
        for (auto j = 0; j != width_; j++) {
            out << t_[i][j] << ',';
        }
        out << '\n';
    }
}
ostream& operator<<(ostream& out, Table t) {
    t.print_table(out);
    return out;
}

int main() {
    bool result_bool;
    long result_long;
    cout << boolalpha;

    Table my_table(5, 5);
    cout << my_table << endl;

    my_table.fill_random(1, 10);
    cout << my_table << endl;

    result_bool = my_table.set_value(100, 100, 100);
    cout << "Result:" << result_bool << endl;
    cout << endl;

    result_long = my_table.get_value(3, 3);
    cout << result_long << endl;
    try {
        result_long = my_table.get_value(100, 100);
    }
    catch (exception& e) {
        cout << "Correct!" << endl;
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
        my_table.set_value(i, i, 100);

    cout << my_table << endl;

}