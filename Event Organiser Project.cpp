#include <iostream>
#include <cmath>

const double CostPerHour = 18.50;
const double CostPerMinute = 0.40;
const double CostOfDinner = 20.70;

class EventOrganizer 
{
private:
    std::string eventName;
    std::string firstName;
    std::string lastName;
    int numGuests;
    int numMinutes;
    int numServers;
    double costForOneServer;
    double totalFoodCost;
    double averageCostPerPerson;
    double totalCost;
    double depositAmount;

public:
    void start() 
	{
        std::cout << "Enter the name of the event: ";
        std::getline(std::cin, eventName);

        std::cout << "Enter your first name: ";
        std::getline(std::cin, firstName);

        std::cout << "Enter your last name: ";
        std::getline(std::cin, lastName);

        std::cout << "Enter the number of guests: ";
        std::cin >> numGuests;

        std::cout << "Enter the number of minutes for the event: ";
        std::cin >> numMinutes;

        calculateNumServers();
        calculateCostForOneServer();
        calculateTotalFoodCost();
        calculateAverageCostPerPerson();
        calculateTotalCost();
        calculateDepositAmount();

        displayEventDetails();
        displayCostEstimation();
    }

private:
    void calculateNumServers() 
	{
        numServers = std::ceil(static_cast<double>(numGuests) / 20);
    }

    void calculateCostForOneServer() 
	{
        double cost1 = (numMinutes / 60) * CostPerHour;
        double cost2 = (numMinutes % 60) * CostPerMinute;
        costForOneServer = cost1 + cost2;
    }

    void calculateTotalFoodCost() 
	{
        totalFoodCost = numGuests * CostOfDinner;
    }

    void calculateAverageCostPerPerson() 
	{
        averageCostPerPerson = totalFoodCost / numGuests;
    }

    void calculateTotalCost() 
	{
        totalCost = totalFoodCost + (costForOneServer * numServers);
    }

    void calculateDepositAmount() 
	{
        depositAmount = totalCost * 0.25;
    }

    void displayEventDetails() const {
        std::cout << "\nEvent Details:\n";
        std::cout << "Event Name: " << eventName << "\n";
        std::cout << "Host Name: " << firstName << " " << lastName << "\n";
        std::cout << "Number of Guests: " << numGuests << "\n";
        std::cout << "Number of Minutes: " << numMinutes << "\n";
        std::cout << "Number of Servers: " << numServers << "\n";
    }

    void displayCostEstimation() const {
        std::cout << "\nCost Estimation:\n";
        std::cout << "Cost for Server: " << costForOneServer << "\n";
        std::cout << "Total Food Cost: " << totalFoodCost << "\n";
        std::cout << "Average Cost per Person: " << averageCostPerPerson << "\n";
        std::cout << "Total Cost is: " << totalCost << "\n" << "\n";
        std::cout << "Please deposite a 25% of Toatal Cost to reserve event. the deposite needed is:  " << depositAmount << "\n";
    }
};

int main() 
{
    EventOrganizer eventOrganizer;
    eventOrganizer.start();

}

