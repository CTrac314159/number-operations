#include <iostream>
#include <functional>

// Function to add two numbers. Parameters and return value are ensured double types.
double add(double x, double y)
{
    return (x + y);
}

// Function to multiply two numbers. Parameters and return value are ensured double types.
double mult(double x, double y)
{
    return (x * y);
}

// Function to divide two numbers. Parameters and return value are ensured double types.
double divis(double x, double y)
{
    return (x / y);
}

// Function to subtract two numbers. Parameters and return value are ensured double types.
double subt(double x, double y)
{
    return (x - y);
}

double userInput() // Ask user to input number
{
    std::cout << "Enter a number: "; // Ask user to input number
    double x{}; // Convert user input to type double to avoid data loss
    std::cin >> x;
    
    return x;
}

using ArithmeticFunction = std::function<double(double, double)>; // Type alias for user-selected arithmetic function

// Function to return the pointer to the appropriate operation function based on operator inputted by the user
ArithmeticFunction getArithmeticFunction(char operate)
{
    switch (operate)
    {
    case '+':
        return &add;
    case '-':
        return &subt;
    case '*':
        return &mult;
    case '/':
        return &divis;
    default: // Return a null pointer if operator is none of the above
        return nullptr;
    }
}

int main()
{   
    while (true)
    {
        auto x{ userInput() }; // Ask user to input two numbers
        auto y{ userInput() };
        
        std::cout << "Choose an arithmetic operator (+, *, /, -): "; // Ask user to choose an operator
        char userOperator{};
        std::cin >> userOperator;
        ArithmeticFunction operation{getArithmeticFunction(userOperator)}; // Call appropriate operation function, output result if not null
        if (operation)
            std::cout << x << userOperator << y << " = " << operation(x, y) << '\n';

        std::cout << '\n'; // Ask the user if they want to perform another calculation
        std::cout << "Do you want to perform another arithmetic operation (Y or N)? ";
        char keepOperating{};
        std::cin >> keepOperating;
        
        if (keepOperating == 'N') // If not, terminate the program
            return 0;
    }

    return 0;
}
