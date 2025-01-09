#include "../includes/iter.hpp"

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
	PRINT << c << CURSOR_RIGHT(1) << RESEND;

	tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);
}

//! SECTION

// SECTION - Test Functions

void string_upper(STRING &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = std::toupper(str[i]);
	}
}

void square_of(int &nb)
{
	nb *= nb;
}

//! SECTION

// SECTION - main()

int main(void)
{
	{
		MAIN_MSG("string array")

		STRING array[] = {"hola", "mundo", "como", "estas"};
		int array_size = 4;
		::iter(array, array_size, string_upper);

		for (int i = 0; i < array_size; i++)
		{
			PRINT << "array[" << i << "] = " << array[i] << RESEND;
		}
		press_any_key();
		SPACER(2)
	}
	{
		MAIN_MSG("int array")

		int array[] = {1, 2, 3, 4, 5};
		int array_size = 5;
		::iter(array, array_size, square_of);

		for (int i = 0; i < array_size; i++)
		{
			PRINT << "array[" << i << "] = " << array[i] << RESEND;
		}
		press_any_key();
		SPACER(2)
	}
	return 0;
}

//! SECTION