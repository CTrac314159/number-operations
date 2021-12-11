#include <iostream>
#include <cassert>

void isPrime(int x)
{
	int divisors{ 1 }; // Initialize the divisor variable to 1

	for (int test{ 2 }; test <= x; ++test) // Using a test variable, check for prime numbers by iterating from 2 to x
	{
		if (x % test == 0)
			++divisors;
	}

	if (divisors == 2) // If there are only two divisors of x, the integer is prime
		std::cout << "The integer is prime.\n";
	else
		std::cout << "The integer is not prime.\n";
}

int user_input()
{
	std::cout << "Enter an integer: "; // Ask user to input integer
	int x{};
	std::cin >> x;

	return x;
}

int main()
{
	while (true) // Infinite loop to enable continuous user input
	{
		int x{ user_input() }; // Call the user input function
		isPrime(x); // Call the isPrime function
		// assert(isPrime(x)); Uncomment this to return assertion fail if integer is not prime

		std::cout << "Enter another integer? (Y or N): "; // Ask user if they want to enter another integer
		char y_n{};
		std::cin >> y_n;

		switch (y_n)
		{
		case 'Y': // If Y, continue the while loop
			continue;
		case 'N': // If N, set the Boolean to false and exit the loop
			return 0;
		default: // Default is to output an error message. Go to top of the loop
		{
			std::cout << "Invalid response. Exiting the program...\n";
			return 0;
		}

		}
	}
}