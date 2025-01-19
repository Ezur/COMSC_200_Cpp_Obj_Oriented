#include <iostream>
#include <string>
#include "Elise_Zur_Ship.h"
#include "Elise_Zur_CruiseShip.h"
#include "Elise_Zur_CargoShip.h"
using namespace std;
int main()
{
    // Create an array of Ship pointers, initialized with
    // the addresses of 3 dynamically allocated objects.
    Ship *ships[3] = { new Ship("USS Constitution", "1794"),
                       new CruiseShip("RMS Titantic", "1909", 3320),
                       new CargoShip("Ever Given", "2015", 220940)
                     };
    // Call each object's print function using polymorphism.
    for (int index=0; index < 3; index++)
    {
        ships[index]->print();
        cout << "----------------------------\n";
        
        delete ships[index];     //release memory (avoid memory leak)
        ships[index] = nullptr;   //avoid dangling pointer
    }
    
           
//    system("PAUSE");
    return 0;
}
