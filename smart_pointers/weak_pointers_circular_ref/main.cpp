#include "Route.h"

int main()
{
    auto Zurich = std::make_shared<Route>("Zurich");

    auto London = std::make_shared<Route>("London");

    auto Paris = std::make_shared<Route>("Paris");

    auto Berlin = std::make_shared<Route>("Berlin");

    Zurich->setNextLocation(London);
    London->setNextLocation(Paris);
    Paris->setNextLocation(Berlin);
    Berlin->setNextLocation(Zurich);

    Zurich->printNextLocation();
    London->printNextLocation();
    Paris->printNextLocation();
    Berlin->printNextLocation();

    return 0;
}