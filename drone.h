#ifndef AUD_5_2_DRONE_H
#define AUD_5_2_DRONE_H

#include "cashinstance.h"

class CashInstance;

class Drone {
    int instances;

public:
    CashInstance* availableCashInstances;
    Drone(CashInstance* list, int instances);
    float calculateChange(float total, float paid);
    void returnChange(float change);

};


#endif //AUD_5_2_DRONE_H
