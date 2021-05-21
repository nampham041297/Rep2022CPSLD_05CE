/**
 * @author Branium Academy
 * @website braniumacademy.net
 * @version 2021.05
 */

#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

int main() {
	BankAccount acc1{ 1, "LE VIET HUNG", "9704 3668 1450 3266 098",
		99825000, "01/01/2023", "01/01/2028", "Vietcombank" };
	BankAccount acc2{ 2, "HOANG TRONG TU", "9704 3668 1450 3266 338",
		5925000, "01/05/2023", "01/05/2028", "Vietcombank" };
	int choice = 0;
	do {
		cout << "==================== MENU ====================\n";
		cout << "1. Check ballance\n2. Deposit\n3. Withdraw\n";
		cout << "4. Bank transfer\n0. Exit\n";
		cout << "Your choice? ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 0:
			cout << "<== Thank you for using our service! ==>\n";
			break;
		case 1: {
			cout << "Enter card number: ";
			string cardNumber;
			getline(cin, cardNumber);
			if (cardNumber.compare(acc1.getCardNumber()) == 0) {
				acc1.checkBallance();
			}
			else if (cardNumber.compare(acc2.getCardNumber()) == 0) {
				acc2.checkBallance();
			}
			else {
				cout << "Card number mismatch. Please try again!\n";
			}
			break;
		}
		case 2: { // giả định nạp tiền vào tk acc1
			long amount;
			cout << "Enter amount you want to deposit: ";
			cin >> amount;
			acc1.deposit(amount);
			break;
		}
		case 3: { // giả định rút tiền trên tk acc1
			long amount;
			cout << "Enter amount you want to with draw: ";
			cin >> amount;
			acc1.withdraw(amount);
			break;
		}
		case 4: { // giả định chuyển tiền từ tk acc1 sang tài khoản khác
			BankAccount* accPtr = nullptr;
			cout << "Enter card number: ";
			string cardNumber;
			getline(cin, cardNumber);
			if (cardNumber.compare(acc1.getCardNumber()) == 0) {
				accPtr = &acc1;
			}
			else if (cardNumber.compare(acc2.getCardNumber()) == 0) {
				accPtr = &acc2;
			}
			else {
				cout << "Card number mismatch. Please try again!\n";
			}
			if (accPtr != nullptr) {
				long amount;
				cout << "Enter amount you want to transfer: ";
				cin >> amount;
				acc1.transfer(*accPtr, amount);
			}
			break;
		}
		default:
			cout << "Invalid choice. Please try again!\n";
			break;
		}
	} while (choice != 0);

	return 0;
}