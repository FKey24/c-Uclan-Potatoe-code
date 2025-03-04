
// Student Name: Farris Key
// STUDENT NUMBER: 21281755 



// This has quite a bit of extra Code that has not been covered 
//including OOP, Vectors, things like cin.fail, sleep, string () alignment ect. 
// i would like to preface this by saying its not referenced as these are all concepts i have previously learnt and studdied
// this is because i have previously studdied c++ to university level
// iam just stating this as i would not like it to come up as plagirism or academic missconduct due to the lack of references
// and thus have tried to explain and justify why things like this have been used



// vector was used originally in a different pice of code so i could pass arrays into functions and store multiple values
// however i used it here also so that i could store new toppings and extras in the same vector and remove magic numbers
// while also allowing for additiona and subtractiona nd easy manipulation of the array

// sleep was used to add a delay between the display of the menu and the user input for a more user friendly experience
// system("CLS") was used to clear the console screen after each menu was displayed to make the program more user friendly and easier to read

#include <iostream>  
#include <string>
#include <vector> // Changed to vector to store multiple toppings and remove magic numbers
#include <windows.h> // for Sleep function
#include <cstdlib>   // for system("CLS")

using namespace std;

// a class was used for greater efficeincy and to make the code more readable
// it was also als used to demonstrate greater understanding of OOP
// additionally it meant i could use variables and paramenters that are accessible to all functions in the class without having to pass them as parameters
// it made the code much easier to format and understand
// class was also used for any possible future advancements as it means you can make multiple objects that use the same functions
// it also allows for constructors to be used to initialize variables

class HotPotatoShop
{
private: // doesn't need to be changed anywhere outside the class and cannot be accessed 
    double credits;
    double totalPrice;
    string sizePotato;
    vector<string> toppings;
    vector<string> extras; // Changed to vector to store multiple extras

    // Menu options
    vector<string> potSizes = { "Small", "Medium", "Large" }; // Changed to vector to store multiple sizes
    vector<double> potPrices = { 5.00, 8.50, 10.25 }; // Changed to vector to store multiple prices
    vector<string> toppingNames = { "Cheese", "Butter", "Garlic Butter", "Beans", "Curry Sauce", "Mushrooms", "Onions", "Extra Special Cheese" };
    vector<double> toppingPrices = { 1.00, 0.40, 0.50, 0.75, 1.20, 0.80, 0.40, 1.50 };
    vector<string> extrasOptions = { "Salad Box", "Hot Dog", "Can of Fizzy Drink", "Bottle of Water", "Tea", "Coffee" };
    vector<double> extrasPrices = { 1.50, 4.00, 1.20, 0.80, 1.00, 1.20 };

    // Function adds credits 
    void addCredits()
    {
        double addedCredits;
        int positive = 0;
        cout << "Enter credits to add: ";
        cin >> addedCredits;
        while (cin.fail() || addedCredits < positive) // validation for negatives or invalid inputs , will keep asking until a positive number is entered
        {
            cout << "Invalid input. Please enter a positive number:\n";
            cin.clear();
            cin.ignore(256, '\n'); // clear input buffer (256 is the max buffer size)(ignores until new line)
            cin >> addedCredits;
        }
        credits += addedCredits;
        cout << "Credits updated. Current credits: " << credits << "\n"; // Display updated credits
    }


	// the string function was used to format the menu and make it more readable
    // it works by taking the length of the string and then subtracting the length of the object in the array
	// this means that the string will always be the same length and the prices will always be aligned

    // Formats and displays size menu
    void displaySizeMenu()
    {
        int menuString = 12;
        cout << "Welcome to the Hot Potato shop\nHere's our Menu:\n";
        cout << "Size   Price (Credits)\n";
        cout << "----   ---------------\n";
        for (size_t i = 0; i < potSizes.size(); i++)
        {
            cout << potSizes[i] << string(menuString - potSizes[i].length(), ' ') << potPrices[i] << "\n"; // Adjusts spacing based on size of string 
        } // uses string() to create a string of spaces to adjust the spacing
        cout << "Enter from 1 - 3 for your size\n";
    }

    // Formats and displays toppings menu
    void displayToppingsMenu()
    {
        int menuString = 24;
        cout << "\n\nToppings       Price (Credits)\n";
        cout << "--------       ---------------\n";
        for (size_t i = 0; i < toppingNames.size(); i++)
        {
            cout << toppingNames[i] << string(menuString - toppingNames[i].length(), ' ') << toppingPrices[i] << "\n";
        }
    }

    // Formats and displays extras menu
    void displayExtrasMenu()
    {
        int menuString = 24;
        cout << "\n\nExtras         Price (Credits)\n";
        cout << "------         ---------------\n";
        for (size_t i = 0; i < extrasOptions.size(); i++)
        {
            cout << extrasOptions[i] << string(menuString - extrasOptions[i].length(), ' ') << extrasPrices[i] << "\n";
        }
    }

	// this is ne of the places where the vector was used to store multiple values and demonstatres it can be easily manipulated
	// the push_back function was used to add the values to the vector 
	// push works by adding it to the end of the vector and increasing the size of the vector by 1

	void addToppings() // function to add toppings
    {
        int choice;
        int exit = 0;
        int indexAdjuster = 1;
        displayToppingsMenu(); // Display toppings menu
        while (true) // Loop to add toppings
        {
            cout << "\nSelect toppings from 1 - 8\n(enter 0 to finish): ";
            cin >> choice;
            if (choice == 0) break; // Exit loop if 0 is entered

            validateInput(choice, exit, toppingNames.size()); // Validate input against 0 as min and the size of the toppings array as max

            double toppingPrice = toppingPrices[choice - indexAdjuster]; // Get price of topping
            processCredits(toppingPrice); // Check if there's enough credits

            toppings.push_back(toppingNames[choice - indexAdjuster]); // Add to toppings list (vector)
            totalPrice += toppingPrice; // Add price to total price
            cout << "Added " << toppingNames[choice - indexAdjuster] << ". Remaining Credits: " << credits << "\n";
        }
    }


	void addExtras() // Function to add extras
    {
        int choice;
        displayExtrasMenu(); // Display extras menu
        int exit = 0;
        int indexAdjuster = 1;
        while (true) // Loop to add extras
        {
            cout << "\nSelect extras from 1 - 6\n(enter 0 to finish): ";
            cin >> choice;
            if (choice == 0) break; // Exit loop if 0 is entered

			validateInput(choice, exit, extrasOptions.size()); // Validate input against 0 as min and the size of the extras array as max

			double extraPrice = extrasPrices[choice - indexAdjuster]; // Get price of extra
            processCredits(extraPrice);

            extras.push_back(extrasOptions[choice - indexAdjuster]); // Add to extras to the list (vector)
            totalPrice += extraPrice;
            cout << "Added " << extrasOptions[choice - indexAdjuster] << ". Remaining Credits: " << credits << "\n";
        }
    }

	// here parameter passing was used to validate the input against the min and max values and it meant the input value that was 
    // originally passed could be manipulated without issue or return statements

	// the cin.fail() function was used to check if the input was a number or not
	// it was used as it is an easy way to quickly see that the user has entered an invalid / erroneous input

    void validateInput(int& input, int min, int max)
    {
        while (cin.fail() || input < min || input > max) // Validation for invalid inputs
        {
            cin.clear(); // Clear any error state
			cin.ignore(256, '\n'); // Clear input buffer
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ":\n";
            cin >> input; // Re-ask for input
        }
    }



    // Function checks if there's enough credits and gives option to add more or cancel order
    void processCredits(double price)
    {
        int moreCredits = 1;
        int cancelOrder = 2;
        while (credits < price) // Check if there's enough credits
        {
            cout << "You do not have enough credits for this item. Current credits: " << credits << "\n";
            int option;
            cout << "\n1. Add More Credits\n2. Cancel Order\nChoose an option:\n";
            cin >> option;
            validateInput(option, moreCredits, cancelOrder); // Validate input against 1 as min and 2 as max

            if (option == moreCredits) // if user chooses to add more credits(1)
            {
                addCredits(); // Add credits
            }
            else
            {
                cout << "Order cancelled.\n"; // Cancel order
                return;
            }
        }

        // Removes current price from credits
        credits -= price;
        cout << "Credits remaining: " << credits << "\n";
    }

public:
    HotPotatoShop() : credits(0.0), totalPrice(0.0), sizePotato("") {} // Constructor (initializes credits, totalPrice and sizePotato) of this class

    // Welcome message and starts the order by asking for credits then calling place order
    void start()
    {
        cout << "Welcome to the Hot Potato Shop!\n";
        Sleep(1000);
        system("CLS");
        addCredits();
        placeOrder();
    }

    // Function to place order
    void placeOrder()
    {
        int min = 1;
        int indexAdjuster = 1;
        // Choose size menu
        displaySizeMenu();
        int choice;
        cin >> choice;
        validateInput(choice, min, potSizes.size());
        // ^ input validation against 1 as min and the size as max

        // -1 to account for an arrsay
        sizePotato = potSizes[choice - indexAdjuster]; // Get size of potato
        double sizePrice = potPrices[choice - indexAdjuster];
        processCredits(sizePrice); // Check if there's enough credits
        totalPrice += sizePrice;

        Sleep(1000); // Sleep for 1 second
        system("CLS"); // Clear screen

        // Add toppings
        addToppings();

        Sleep(1000);
        system("CLS");

        // Add extras
        addExtras();

        Sleep(1000);
        system("CLS");

        int baseZero = 0;
        // Display order summary
        cout << "\nOrder Summary:\n";
        cout << sizePotato << " Potato with ";
        if (toppings.empty()) // Check if there are no toppings
        {
            cout << "no toppings";
        }
        else
        {
            for (size_t i = baseZero; i < toppings.size(); ++i) // Loop through toppings
            {
                cout << toppings[i];
                if (i < toppings.size() - 1) cout << ", ";
            }
        }

        if (!extras.empty()) // Check if there are extras
        {
            cout << " and extras: ";
            for (size_t i = baseZero; i < extras.size(); ++i) // Loop through extras
            {
                cout << extras[i];
                if (i < extras.size() - 1) cout << ", ";
            }
        }

        cout << ".\n";
        cout << "Total Price: " << totalPrice << " Credits. Remaining Credits: " << credits << "\n"; // Display total price and remaining credits

        // Repeat order or exit
        cout << "\nWould you like to:\n 1) See last order\n 2) do new order\n";
        char repeat;
        cin >> repeat;
        if (repeat == '2') // If user chooses to do a new order
        {
            resetOrder(); // Reset order
        }
        else if (repeat == '1') // If user chooses to see last order
        {
            printLastOrder(); // Print last order
        }
        else
        {
            cout << "Thank you for visiting the Hot Potato Shop. Goodbye!\n";
        }
    }

    void printLastOrder() // Function to print last order
    {
        cout << "\nLast Order Summary:\n";
        cout << sizePotato << " Potato with ";
        if (toppings.empty()) // Check if there are no toppings
        {
            cout << "no toppings";
        }
        else
        {
            for (size_t i = 0; i < toppings.size(); ++i) // Loop through toppings
            {
                cout << toppings[i];
                if (i < toppings.size() - 1) cout << ", ";
            }
        }
        if (!extras.empty()) // Check if there are extras
        {
            cout << " and extras: ";
            for (size_t i = 0; i < extras.size(); ++i) // Loop through extras
            {
                cout << extras[i];
                if (i < extras.size() - 1) cout << ", ";
            }
        }
        cout << ".\n";
        cout << "Total Price: " << totalPrice << " Credits. Remaining Credits: " << credits << "\n";
        cout << "Thank you for visiting the Hot Potato Shop. Goodbye!\n";
    }

    void resetOrder() // Function to reset order
    {
        totalPrice = 0.0; // Reset total price
        sizePotato = ""; // Reset size of potato
        toppings.clear();// Reset toppings list
        extras.clear(); // Reset extras list
        placeOrder(); // Place order (simulationg a new order)
    }
};

int main()
{
    HotPotatoShop shop; // Create an instance of HotPotatoShop called shop
    shop.start(); // Start the shop by calling start function
}
