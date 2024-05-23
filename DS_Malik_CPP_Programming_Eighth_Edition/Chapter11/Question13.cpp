#include <iostream>
using namespace std;

class bankAccount {
protected:
    int accountNumber;
    double balance;

public:
    bankAccount(int accNum = 0, double bal = 0.0) : accountNumber(accNum), balance(bal) {}

    void setAccountNumber(int accNum) {
        accountNumber = accNum;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        balance -= amount;
    }

    void printAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minBalance;
    double serviceCharges;

public:
    checkingAccount(int accNum = 0, double bal = 0.0, double intRate = 0.0, double minBal = 0.0, double servCharges = 0.0)
        : bankAccount(accNum, bal), interestRate(intRate), minBalance(minBal), serviceCharges(servCharges) {}

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    double getInterestRate() const {
        return interestRate;
    }

    void setMinimumBalance(double minBal) {
        minBalance = minBal;
    }

    double getMinimumBalance() const {
        return minBalance;
    }

    void setServiceCharges(double charges) {
        serviceCharges = charges;
    }

    double getServiceCharges() const {
        return serviceCharges;
    }

    void postInterest() {
        balance += balance * (interestRate / 100.0);
    }

    bool isBalanceBelowMinimum() const {
        return balance < minBalance;
    }

    void writeCheck(double amount) {
        if (balance - amount >= 0) {
            withdraw(amount);
        } else {
            cout << "Insufficient amount to write check." << endl;
        }
    }

    void withdraw(double amount) override {
        if (balance - amount >= minBalance) {
            balance -= amount;
        } else {
            balance -= (amount + serviceCharges);
            cout << "Service charges applied due to low balance." << endl;
        }
    }

    void printAccountInfo() const {
        bankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance: " << minBalance << endl;
        cout << "Service Charges: " << serviceCharges << endl;
    }
};

class savingsAccount : public bankAccount {
private:
    double interestRate;
    
public:
    savingsAccount(int accNum = 0, double bal = 0.0, double intRate = 0.0)
        : bankAccount(accNum, bal), interestRate(intRate) {}

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    double getInterestRate() const {
        return interestRate;
    }

    void postInterest() {
        balance += balance * (interestRate / 100.0);
    }

    void withdraw(double amount) override {
        if (balance - amount >= 0) {
            balance -= amount;
        } else {
            cout << "Insufficient funds to withdraw." << endl;
        }
    }

    void printAccountInfo() const {
        bankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    checkingAccount checking(1234, 1000, 5.0, 500, 10);
    savingsAccount savings(5678, 2000, 3.5);

    checking.deposit(500);
    checking.printAccountInfo();
    cout << endl;

    savings.withdraw(300);
    savings.postInterest();
    savings.printAccountInfo();

    return 0;
}
