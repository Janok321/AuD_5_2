
#ifndef AUD_5_2_CASHINSTANCE_H
#define AUD_5_2_CASHINSTANCE_H


class CashInstance {
public:
    float value;
    int availableAmount;

    void print();
    CashInstance();
    CashInstance(float value, int amount);
};

#endif //AUD_5_2_CASHINSTANCE_H
