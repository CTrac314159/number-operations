#include <iostream>

template <typename T> // Template function to add two numbers of same type
T add(T x, T y)
{
    return x + y;
}

template <typename U> // Template function to multiply number of any type and integer
U mult(U x, int y)
{
    return x * y;
}

template <typename V, typename W> // Template function to subtract numbers of different types. Infer return type with "auto" keyword
auto subt(V x, W y)
{
    return x - y;
}

double userInput() // Convert user input to a double initially to avoid data loss if later converted to an integer
{
    std::cout << "Enter a number: "; // Ask user to input number
    double x{};
    std::cin >> x;

    return x;
}

int main()
{   
    auto x{ userInput() }; // Ask user to input two numbers, then infer their data types
    auto y{ userInput() };
    
    std::cout << "Choose an arithmetic operator (+, *, -): "; // Ask user to choose an operator
    char operation{};
    std::cin >> operation;

    switch (operation) // Switch sequence based on requested user operator to call the appropriate template function, output the result
    {
    case '+': // Addition
        std::cout << "Both numbers will be converted to the same type.\n";
        std::cout << "The sum of the numbers is " << add(x, y);
        break;
    case '*': // Multiplication
        std::cout << "If not already, the second number will be converted to an integer.\n";
        std::cout << "The product of the numbers is " << mult(x, static_cast<int>(y));
        break;
    case '-': // Subtraction
        std::cout << "The difference between the numbers is " << subt(x, y);
        break;
    default: // Invalid operator
        std::cout << "Invalid operator. Please try again.";
        break;
    }

    return 0;
}