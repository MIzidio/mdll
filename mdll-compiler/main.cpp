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

enum class SyntaxKind
{
	NumberToken
};

class SyntaxToken
{
public:
	SyntaxToken(SyntaxKind kind, int position, const char* text)
	{
		p_kind = kind;
		p_position = position;
		p_text = text;
	}

	//SyntaxKind getKind() {
	//	return p_kind;
	//}

	//int getPosition() {
	//	return p_position;
	//}

	//std::string getText() {
	//	return p_text;
	//}

public: 
	SyntaxKind p_kind;
	int p_position;
	std::string p_text;
};

class Lexer
{

public:
	Lexer(std::string text) : _text(m_text)
	{
		m_text = text;
	}

	SyntaxToken NextToken()
	{
		if (isdigit(Current()))
		{
			auto start = m_position;

			while (isdigit(Current()))
				Next();

			auto length = m_position - start;
			auto text = m_text.substr(start, length);
		}
	}

	void setText(std::string _text)
	{
		this->m_text = _text;
	}

public:
	const std::string _text;

private:
	std::string m_text;
	int m_position;

private:
	char Current()
	{
		if (m_position >= m_text.length())
			return '\0';

		return m_text[m_position];
	}

	void Next()
	{
		m_position++;
	}
};