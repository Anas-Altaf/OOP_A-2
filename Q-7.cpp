#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

class Account {
	public:
	Account(double balance) {
		if (balance < 0.0) {
			cout << "balance cannot be -ve at start" << endl;
			balance_ = 0.0;
		}
		else {
			balance_ = balance;
		}
}

	virtual void credit(double amount) {
		balance_ += amount;
}

	virtual bool debit(double amount) {
		if (amount > balance_) {
			cout << "Error, debit amount exceeds" << endl;
			return false;
	}
		else {
			balance_ -= amount;
			return true;
		}
	}

	double getBalance() const {
		return balance_;
	}

protected:
	double balance_;
};
// 2nd One
class SavingsAccount : public Account {
public:
	SavingsAccount(double balance, double interestRate)
		: Account(balance), interestRate_(interestRate) {}

	double calculateInterest() const {
		return balance_ * interestRate_ / 100.0;
	}

private:
	double interestRate_;
};
// Checking
class CheckingAccount : public Account {
public:
	CheckingAccount(double balance, double fee)
		: Account(balance), fee_(fee) {}

	void credit(double amount) override {
		Account::credit(amount);
		balance_ -= fee_;
	}

	bool debit(double amount) override {
		bool success = Account::debit(amount);
		if (success) {
			balance_ -= fee_;
		}
		return success;
	}

private:
	double fee_;
};
// Main 
int main(){
	//->create objects of each class
	Account account(1000.0);
	SavingsAccount savings(5000.0, 2.5);
	CheckingAccount checking(2000.0, 1.0);
	//->test member functions
	account.credit(500.0);
	account.debit(200.0);
	cout<< " Account Balance = " << account.getBalance()<< endl;
	double interest = savings.calculateInterest();
	savings.credit(interest);
	cout<< "Saved Account Balance : " << savings.getBalance() << endl;
	//->Checking
	checking.credit(100.0);
	checking.debit(500.0);
	cout<<" Balance Checking..." << checking.getBalance() <<endl;
	system("pause");
	return 0;
}
