#pragma once
#ifndef bank_account
#define bank_account
#include <string>
using std::string; using std::getline;
#include <sstream>
using std::istringstream; using std::ostringstream;
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <iomanip>
using std::fixed; using std::setprecision;
#include <cmath>

void deposit(double &balance, double &amount) {
    balance += amount;
}

bool withdraw(double &balance, double &amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}

void overdraft(double &balance, double &amount) {
    balance -= amount;
    balance -= 35;
}

double interest_for_month(double balance, double apr) {
    return floor(balance * apr / 12) / 100;
}

void string_date_to_int_ptrs(string date, int *const year,
    int *const month, int *const day) {
    istringstream iss_date(date);
    iss_date >> *year >> *month >> *day;
    *month = -(*month);
    *day = -(*day);
}

void string_date_to_ints(string date, int &year,
    int &month, int &day) {
    istringstream iss_date(date);
    iss_date >> year >> month >> day;
    month = -month;
    day = -day;
}

int number_of_first_of_months(const string &earlier_date,
    const string &later_date) {
    int earlier_year, earlier_month, earlier_day;
    int later_year, later_month, later_day;
    int times;
    string_date_to_ints(earlier_date, earlier_year, earlier_month, earlier_day);
    string_date_to_ints(later_date, later_year, later_month, later_day);
    times = (later_year - earlier_year) * 12 + (later_month - earlier_month);
    return times;
}

double interest_earned(const double &balance, const double &apr,
    const string &earlier_date, const string &later_date) {
    int interest_times;
    double earned;
    interest_times = number_of_first_of_months(earlier_date, later_date);
    if (balance > 0.00 && interest_times >= 1) {
        double temp = balance;
        for (auto i = interest_times; i > 0; i--) {
            temp += interest_for_month(temp, apr);
        }
        earned = temp - balance;
        return earned;
    } else {
        return 0.00;
    }
}

string process_command(string &line, string &earlier_date,
    double &balance, double &apr) {
    istringstream iss(line);
    ostringstream res;
    int interest_cover_time;
    istringstream money_stream;
    string date, command, str_money;
    double double_money, interest;
    char cash_sign;
    bool success_withdraw;
    iss >> date >> command >> str_money;
    money_stream.str(str_money);
    money_stream >> cash_sign >> double_money;
    res << fixed << setprecision(2);
    res << "On " << date << ": " << "Instructed to perform \"";
    res << command << " " << str_money << "\"\n";
    interest_cover_time = number_of_first_of_months(earlier_date, date);
    interest = interest_earned(balance, apr, earlier_date, date);
    if (interest_cover_time >= 1 && !earlier_date.empty()) {
        res << "Since " << earlier_date << ", interest has accrued ";
        res << interest_cover_time << " times.\n";
        res << cash_sign << interest;
        res << " interest has been earned.\n";
    }
    if (command == "Deposit")
        deposit(balance, double_money);
    if (command == "Withdraw") {
        success_withdraw = withdraw(balance, double_money);
        if (!success_withdraw) {
            overdraft(balance, double_money);
            res << "Overdraft!\n";
        }
    }
    earlier_date = date;
    balance += interest;
    res << "Balance: " << balance << "\n";
    return res.str();
}

string process_commands(string &in, double apr) {
    istringstream iss(in);
    ostringstream out;
    string line, earlier_date, each_res;
    double balance = 0.00;
    while (getline(iss, line, '\n')) {
        each_res = process_command(line, earlier_date, balance, apr);
        out << each_res;
    }
    return out.str();
}

#endif
