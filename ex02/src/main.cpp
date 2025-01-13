#include "../includes/Array.hpp"
// SECTION - press_any_key()

#include <termios.h>
#include <unistd.h>
void press_any_key()
{
	PRINT << LOW_BRIGHT << "Press any key ( )" << CURSOR_LEFT(2);

	struct termios old_terminal, newt;
	tcgetattr(STDIN_FILENO, &old_terminal);
	newt = old_terminal;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	char c = getchar();
	if (!std::isprint(c))
		c = ' ';
	PRINT << c << CURSOR_RIGHT(1) << RESEND;

	tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);
}

//! SECTION

// SECTION - Test Functions

struct s_test
{
	int a;
	char b;
};

//! SECTION

// SECTION - main()

int main(int, char **)
{
	{
		MAIN_MSG("Empty Array")
		Array<int> emptyArray;

		PRINT << "emptyArray size: " << emptyArray.size() << RESEND;
		press_any_key();
	}
	SPACER(3)
	{
		MAIN_MSG("Out of Bounce")
		Array<int> emptyArray;

		try
		{
			PRINT << "emptyArray[5]: " << emptyArray[5] << RESEND;
		}
		CATCH
		press_any_key();
	}
	SPACER(3)
	{
		Array<int> intArray(5);
		{
			MAIN_MSG("Int Array")

			for (int i = 0; i < 5; i++)
				intArray[i] = i;

			PRINT << "intArray size: " << intArray.size() << RESEND;
			PRINT << "intArray: ";

			for (int i = 0; i < 5; i++)
				PRINT << intArray[i] << " ";

			PRINT << RESEND;
			press_any_key();
		}
		SPACER(3)
		{
			MAIN_MSG("Copy Constructor")
			Array<int> intArrayCopy(intArray);

			PRINT << "intArrayCopy size: " << intArrayCopy.size() << RESEND;
			PRINT << "intArrayCopy: ";

			for (int i = 0; i < 5; i++)
				PRINT << intArrayCopy[i] << " ";

			PRINT << RESEND;
			press_any_key();
		}
		SPACER(3)
	}
	SPACER(3)
	{
		MAIN_MSG("Double Array")
		Array<double> doubleArray(10);

		for (int i = 0; i < 10; i++)
			doubleArray[i] = i / 2.0;

		PRINT << "doubleArray size: " << doubleArray.size() << RESEND;
		PRINT << "doubleArray: ";

		for (int i = 0; i < 10; i++)
			PRINT << doubleArray[i] << " ";

		PRINT << RESEND;
		press_any_key();
	}
	SPACER(3)

	return (0);
}

//! SECTION