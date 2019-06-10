#include<iostream>
using std::cout; using std::cin; using std::endl;

int InsertMoney(int total_knuts) {    //count the total money the customer inserted
    int galleons, sickles, knuts;
    cout << "How many Galleons are you inserting?" << endl;
    cin >> galleons;
    cout << "How many Sickles are you inserting?" << endl;
    cin >> sickles;
    cout << "How many Knuts are you inserting?" << endl;;
    cin >> knuts;
    total_knuts = knuts + sickles * 29 + galleons * 17 * 29;
    return total_knuts;
}

int CalculateChange(int item_price, int total_knuts) {
    int num_change;
    num_change = total_knuts - item_price * 29;
    return num_change;
}

int main() {
    int num_bb = 3, num_gw = 3, num_fw = 3;
    int num_pj = 3, num_ff = 3;
    char option;
    while (1) {
        cout << "What would you like to do: "
            << "(p)urchase, (r)estock, (i)nventory, (q)uit?" << endl;;
        cin >> option;
        if (option == 'p') {                   // purchase
            char item;
            int total_knuts = 0, num_change;
            cout << "You chose (p)urchase." << endl;
            cout << "What would you like to purchase: "
                << "(b)utterbeer, (g)illywater, fire (w)hiskey, "
                << "(p)umpkin juice, (f)elix felicius?" << endl;
            cin >> item;
            if (item == 'b') {
                int galleon_change, sickle_change, knut_change;
                if (num_bb != 0) {
                    cout << "You chose Butterbeer. "
                        << "It costs 4 (Sickles)." << endl;
                }
                else {
                    cout << "You chose Butterbeer. "
                        << "But, there isn't any. Sorry!" << endl;
                    continue;
                }
                while (1) {
                    total_knuts = InsertMoney(total_knuts);
                    if (total_knuts < 4 * 29) {
                        cout << "You didn't pay enough."
                            << " Returning coins." << endl;
                        cout << "It costs 4 (Sickles)." << endl;
                    }
                    else {
                        break;
                    }
                }
                num_change = CalculateChange(4, total_knuts);
                num_bb -= 1;
                galleon_change = num_change / (17 * 29);
                sickle_change = (num_change - 17 * 29 * galleon_change) / 29;
                knut_change = (num_change - 17 * 29 * galleon_change) % 29;
                cout << "Your change is " << galleon_change << " Galleons, "
                    << sickle_change << " Sickles, and "
                    << knut_change << " Knuts. "
                    << "Enjoy your beverage." << endl;
                continue;
            }
            if (item == 'g') {
                int galleon_change, sickle_change, knut_change;
                if (num_gw != 0) {
                    cout << "You chose Gillywater. "
                        << "It costs 3 (Sickles)." << endl;
                }
                else {
                    cout << "You chose Gillywater. "
                        << "But, there isn't any. Sorry!" << endl;
                    continue;
                }
                while (1) {
                    total_knuts = InsertMoney(total_knuts);
                    if (total_knuts < 3 * 29) {
                        cout << "You didn't pay enough. "
                            << " Returning coins." << endl;
                        cout << "It costs 3 (Sickles)." << endl;
                    }
                    else {
                        break;
                    }
                }
                num_change = CalculateChange(3, total_knuts);
                num_gw -= 1;
                galleon_change = num_change / (17 * 29);
                sickle_change = (num_change - 17 * 29 * galleon_change) / 29;
                knut_change = (num_change - 17 * 29 * galleon_change) % 29;
                cout << "Your change is " << galleon_change << " Galleons, "
                    << sickle_change << " Sickles, and "
                    << knut_change << " Knuts. "
                    << "Enjoy your beverage." << endl;
                continue;
            }
            if (item == 'w') {
                int galleon_change, sickle_change, knut_change;
                if (num_fw != 0) {
                    cout << "You chose Fire Whiskey. "
                        << "It costs 6 (Sickles)." << endl;
                }
                else {
                    cout << "You chose Fire Whiskey. "
                        << "But, there isn't any. Sorry!" << endl;
                    continue;
                }
                while (1) {
                    total_knuts = InsertMoney(total_knuts);
                    if (total_knuts < 6 * 29) {
                        cout << "You didn't pay enough. "
                            << " Returning coins." << endl;
                        cout << "It costs 6 (Sickles)." << endl;
                    }
                    else {
                        break;
                    }
                }
                num_change = CalculateChange(6, total_knuts);
                num_fw -= 1;
                galleon_change = num_change / (17 * 29);
                sickle_change = (num_change - 17 * 29 * galleon_change) / 29;
                knut_change = (num_change - 17 * 29 * galleon_change) % 29;
                cout << "Your change is " << galleon_change << " Galleons, "
                    << sickle_change << " Sickles, and "
                    << knut_change << " Knuts. "
                    << "Enjoy your beverage." << endl;
                continue;
            }
            if (item == 'p') {
                int galleon_change, sickle_change, knut_change;
                if (num_pj != 0) {
                    cout << "You chose Pumpkin Juice. "
                        << "It costs 2 (Sickles)." << endl;
                }
                else {
                    cout << "You chose Fire Whiskey. "
                        << "But, there isn't any. Sorry!" << endl;
                    continue;
                }
                while (1) {
                    total_knuts = InsertMoney(total_knuts);
                    if (total_knuts < 2 * 29) {
                        cout << "You didn't pay enough. "
                            << " Returning coins." << endl;
                        cout << "It costs 2 (Sickles)." << endl;
                    }
                    else {
                        break;
                    }
                }
                num_change = CalculateChange(2, total_knuts);
                num_pj -= 1;
                galleon_change = num_change / (17 * 29);
                sickle_change = (num_change - 17 * 29 * galleon_change) / 29;
                knut_change = (num_change - 17 * 29 * galleon_change) % 29;
                cout << "Your change is " << galleon_change << " Galleons, "
                    << sickle_change << " Sickles, and "
                    << knut_change << " Knuts. "
                    << "Enjoy your beverage." << endl;
                continue;
            }
            if (item == 'f') {
                int galleon_change, sickle_change, knut_change;
                if (num_ff != 0) {
                    cout << "You chose Felix Felicius. "
                        << "It costs 777 (Sickles)." << endl;
                }
                else {
                    cout << "You chose Felix Felicius. "
                        << "But, there isn't any. Sorry!" << endl;
                    continue;
                }
                while (1) {
                    total_knuts = InsertMoney(total_knuts);
                    if (total_knuts < 777 * 29) {
                        cout << "You didn't pay enough. "
                            << " Returning coins." << endl;
                        cout << "It costs 777 (Sickles)." << endl;
                    }
                    else {
                        break;
                    }
                }
                num_change = CalculateChange(777, total_knuts);
                num_ff -= 1;
                galleon_change = num_change / (17 * 29);
                sickle_change = (num_change - 17 * 29 * galleon_change) / 29;
                knut_change = (num_change - 17 * 29 * galleon_change) % 29;
                cout << "Your change is " << galleon_change << " Galleons, "
                    << sickle_change << " Sickles, and "
                    << knut_change << " Knuts. "
                    << "Enjoy your beverage." << endl;
                continue;
            }
        }
        else if (option == 'r') {            // restock
            cout << "You chose (r)estock." << endl;
            num_bb = 3;
            num_gw = 3;
            num_fw = 3;
            num_pj = 3;
            num_ff = 3;
            cout << "Fully restocked. There are 3 of each item." << endl;
        }
        else if (option == 'i') {            // inventory
            cout << "You chose (i)nventory." << endl;
            cout << "There are " << num_bb << " cans of Butterbeer." << endl;
            cout << "There are " << num_gw << " cans of Gillywater." << endl;
            cout << "There are " << num_fw << " cans of Fire Whiskey." << endl;
            cout << "There are " << num_pj << " cans of Pumpkin Juice." << endl;
            cout << "There are " << num_ff
                << " cans of Felix Felicius." << endl;
        }
        else if (option == 'q') {
            cout << "You chose (q)uit." << endl;
            cout << "Have a magical day!" << endl;
            break;
        }
    }
}