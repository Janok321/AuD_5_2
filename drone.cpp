#include "drone.h"
#include <vector>
#include <iostream>

Drone::Drone(CashInstance *list, int instances) {
    this->availableCashInstances = list;
    this->instances = instances;
}

float Drone::calculateChange(float total, float paid) {
    if (total < paid){
        float change = paid - total;
        return change;
    }
    else if(total > paid){
        return -1;
    }
    else {
        return 0;
    }
}

void Drone::returnChange(float change){
    if (change > 0){
        std::vector<CashInstance> tempArray;
        while(change > 0){
            int max = -1;
            int counter = 0;
            for (int i = 0; i < this->instances; i++){
                if (this->availableCashInstances[i].availableAmount <= 0){
                    counter++;
                }
                if (this->availableCashInstances[i].value <= change && this->availableCashInstances[i].availableAmount > 0){
                    max = i;
                }
                if (i == this->instances - 1 && max == -1 && counter == this->instances){
                    std::cout << "Wechselgeld ist knapp" << std::endl;
                    return;
                }
            }
            if (max > -1){
                tempArray.push_back(this->availableCashInstances[max]);
                this->availableCashInstances[max].availableAmount--;
                change = change * 1000;
                change -= 1000 * (this->availableCashInstances[max].value);
                change = change/1000;

                if (change < 0.001){
                    change = -1;
                }
            }
            else {
                int amount_low = -1;
                for (int i = 0; i < this->instances; i++){
                    if(this->availableCashInstances[i].availableAmount > 0){
                        amount_low = i;
                        break;
                    }
                }
                tempArray.push_back(this->availableCashInstances[amount_low]);
                this->availableCashInstances[amount_low].availableAmount--;

                change = change * 1000;
                float moreChange = (1000 * this->availableCashInstances[amount_low].value) - change;
                moreChange = moreChange / 1000;
                change = -1;
                std::cout << "Warnung: Rueckgeld kann nicht genau herausgegeben werden! Ausbezahlter Betrag ueberschreitet"
                             " den genauen Wert um "
                          << moreChange << "!" << std::endl;
            }
        }
        CashInstance* changeList = new CashInstance[tempArray.size()];

        std::cout << "Sie bekommen zurueck: ";
        for(unsigned int i = 0; i < tempArray.size(); i++){
            changeList[i] = tempArray.at(i);
            std::cout << changeList[i].value;
            if (i < tempArray.size()-1){
                std::cout << " + ";
            }
        }
        std::cout << std::endl;
    }
    else if (change < 0){
        std::cout << "Rechnungsbetrag ist noch offen." << std::endl;
    }
    else {
        std::cout << "Rechnungsbetrag ist beglichen" << std::endl;
    }
}