#include "backpack.h"
#include "cashinstance.h"
#include "drone.h"


int main() {

    CashInstance array[6];

    CashInstance five_Cent_Coins(0.05, 6);
    array[0] = five_Cent_Coins;
    CashInstance ten_Cent_Coins(0.10, 5);
    array[1] = ten_Cent_Coins;
    CashInstance twenty_Cent_Coins(0.20, 3);
    array[2] = twenty_Cent_Coins;
    CashInstance fifty_Cent_Coins(0.50, 5);
    array[3] = fifty_Cent_Coins;
    CashInstance one_Euro_Coins(1.0, 4);
    array[4] = one_Euro_Coins;
    CashInstance two_Euro_Coins(2.0, 5);
    array[5] = two_Euro_Coins;


    Drone drone(array, 6);

    std::cout << "Der Rechnungsbetrag lautet: 4.8" << std::endl;
    std::cout << "Bezahlt: 6.0" << std::endl;
    drone.returnChange(drone.calculateChange(4.8, 6.0));
    std::cout << "____________________________________________________________________________________" << std::endl;
    std::cout << "Der Rechnungsbetrag lautet: 9.98" << std::endl;
    std::cout << "Bezahlt: 15.0" << std::endl;
    drone.returnChange((drone.calculateChange(9.9, 15.0)));

}