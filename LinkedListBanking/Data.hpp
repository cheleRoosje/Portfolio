#ifndef DATA_HPP
#define DATA_HPP

class Data {
public:
    Data(int accountNumber, const char* nameArray, float balance);

    void getBalance(int acctNum);
    float setDeposit(int acctNum, float depositAmt);
    float setWithdrawal(int acctNum, float withdrawAmt);
    void updateBalance(float newBalance);
    int getAccountNumber() const; // Getter for accountNumber

private:
    char name[50]; 
    int accountNumber;
    float balance; 
};

#endif // DATA_HPP
