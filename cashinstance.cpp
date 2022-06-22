#include "cashinstance.h"
#include <iostream>

CashInstance::CashInstance() {}

CashInstance::CashInstance(float value, int amount) {
    this->value = value;
    this->availableAmount = amount;
}

void CashInstance::print() {
    std::cout << "Value: " << this->value << "\t amount: " << this->availableAmount << std::endl;
}