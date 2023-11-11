#include <iostream>
#include <string>

int main()
{
	setlocale(0, "");

	int value; 
	std::string binary_number = "";

	std::cout << "\tВведите номер задания (1 - перевод из двоичной в десетичную; перевод из десятичного в двоичную): ";
	std::cin >> value;

	switch (value)
	{
	case 1:
		double number = 0;
		double x = 0;
		double y = 0;
		
		std::cout << "\tВведите двоичное дробное число: ";
		std::cin >> binary_number;
		
		for (int i = 0; i < binary_number.length(); i++)
		{
			char b = binary_number[i];
		
			if (binary_number[i] == '0' || binary_number[i] == '1')
			{
				x = 2 * x + b - '0';
				y *= 2;
			}
			else if (binary_number[i] == '.')
				y = 1;
		}
		
		if (y > 0)
			number = x / y;
		
		std::cout << "\t" << number;
		
		break;

	case 2: 
		std::string number;
		std::string binary_whole, binary_factorial;
		std::string number_whole, number_factorial;
		std::string k = "1";
		int whole = 0, factorial = 0;
		int x = 0, x_1 = 0;

		std::cout << "\tВведите десятичное число: ";
		std::cin >> number;

		for (int i = 0; i < number.length(); i++)
		{
			if (number[i] == ',')
			{
				i++;

				for (int j = i; j < number.length(); j++)
					number_factorial += number[j];

				break;
			}

			number_whole += number[i];
		}

		whole = std::stoi(number_whole);
		factorial = std::stoi(number_factorial);

		while (whole)
		{
			x_1 = whole % 2;
			whole /= 2;

			x = 10 * x + x_1;
		}

		binary_whole = std::to_string(x);

		for (int i = 0; i < number_factorial.length() - 1; i++)
			k += '0';

		int k_1 = std::stoi(k);

		while (factorial > 10)
		{
			factorial *= 2;

			if (factorial >= k_1)
			{
				std::string str = std::to_string(factorial);

				if (factorial > 199 && str[str.length() - 1] == '0')
				{
					std::string value_str = std::to_string(factorial);
					std::string value_str_1;

					for (int i = 0; i < value_str.length() - 1; i++)
						value_str_1 += value_str[i];

					factorial = std::stoi(value_str_1);

					binary_factorial = '0';
				}
				else
				{
					factorial = factorial - k_1;

					binary_factorial += '1';
				}
			}
			else
				binary_factorial += '0';
		}

		std::cout << "\t" << binary_whole << "," << binary_factorial;

		break;
	default:
		break;
	}
}

