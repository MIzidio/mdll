#include <iostream>
#include <string>

int main()
{
	std::string a;
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, a);

		// Check if the string is empty or contains only spaces
		// The a.find_first_not_of(' ') == std::string::npos means that the string contains only spaces
		// std::string::npos is a special value that means "until the end of the string"
		// So, if the string contains only spaces, the first non-space character will be at the end of the string
		if (a.empty() || a.find_first_not_of(' ') == std::string::npos)
		{
			return false;
		}

		if (a == "1 + 2 + 3")
		{
			std::cout << "6" << std::endl;
		}
		else {
			std::cout << "Invalid input" << std::endl;
		}
	}
}