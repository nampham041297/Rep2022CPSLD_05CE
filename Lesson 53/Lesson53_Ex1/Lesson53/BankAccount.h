#pragma once
#include <string>
using namespace std;

class BankAccount
{
private:
	int id;
	string owner;
	string cardNumber;
	long ballance = 0;
	string startDate;
	string endDate;
	string bankName;
public:
	// hàm tạo
	BankAccount();
	BankAccount(int, string, string, long, string, string, string);
	// hành động:
	void checkBallance();		// kiểm tra số dư
	bool withdraw(long amount);	// rút tiền
	bool transfer(BankAccount other, long amount); // chuyển tiền
	bool deposit(long amount);	// nạp tiền
	// cac getter/setter
	void setOwner(string owner);
	string getOwner();
	void setCardNumber(string cardNumber);
	string getCardNumber();
	void setBallance(long ballance);
	long getBallance();
	void setStartDate(string startDate);
	string getStartDate();
	void setEndDate(string endDate);
	string getEndDate();
	void setBankName(string bankName);
	string getBankName();
};

