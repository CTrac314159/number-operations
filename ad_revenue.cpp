#include <iostream>
#include <iomanip>

struct Advertising // Define the structure with the three input members, default to zero
{
    int shownAds{};
    double clickedPercent{};
    double averageRevenue{};
};

Advertising getAdvertising() // Get user input for three structure members
{
    Advertising ad_input;

    std::cout << "Enter the number of ads shown: ";
    std::cin >> ad_input.shownAds;

    std::cout << "Enter the percentage of ads clicked on by users: ";
    std::cin >> ad_input.clickedPercent;

    std::cout << "Enter the average revenue from each clicked ad: ";
    std::cin >> ad_input.averageRevenue;

    return ad_input;
}

void printAdvertising(const Advertising& ad_user) // Print user input along with the total daily revenue (while dividing clickedPercent by 100)
{
    std::cout << '\n';
    std::cout << "Number of ads shown: " << ad_user.shownAds << '\n';
    std::cout << "Percentage of ads clicked on by users: " << ad_user.clickedPercent << "%\n";
    std::cout << "Average revenue from each clicked ad: $" << std::fixed << std::setprecision(2) << ad_user.averageRevenue << '\n';
    std::cout << "Total daily revenue: $" << std::fixed << std::setprecision(2) << ad_user.shownAds * (ad_user.clickedPercent / 100) 
                                                                                   * ad_user.averageRevenue;
}

int main()
{
    Advertising ad{getAdvertising()};
    printAdvertising(ad);
 
    return 0;
}
