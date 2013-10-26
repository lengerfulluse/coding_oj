#include<iostream>
#include<cassert>
using namespace std;
class Transaction {
public: 
    Transaction();
    virtual void logTransaction();
};
Transaction::Transaction() {
        cout<<"Base Construct..."<<endl;
        logTransaction();
}

void Transaction::logTransaction() {
        cout<<"Base Virtual"<<endl;
}

class BuyTransaction: public Transaction {
public:
    BuyTransaction();
    void logTransaction();
};

BuyTransaction::BuyTransaction() {
        cout<<"Derived Construct..."<<endl;
}

void BuyTransaction::logTransaction(){
    cout<<"Derived Log Transaction"<<endl;
}

int main() {
    Transaction* t = new BuyTransaction();
	return 0;
}
