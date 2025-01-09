#include "../includes/whatever.hpp"

//SECTION - press_any_key()

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

//!SECTION

//SECTION - main()

int main(void)
{
	MAIN_MSG("int")
	int a = 2;
	int b = 3;
	::swap(a, b);
	PRINT << "a = " << a << ", b = " << b << RESEND;
	PRINT << "min( a, b ) = " << ::min(a, b) << RESEND;
	PRINT << "max( a, b ) = " << ::max(a, b) << RESEND;
	press_any_key();

	MAIN_MSG("string")
	STRING c = "word1";
	STRING d = "word2";
	::swap(c, d);
	PRINT << "c = " << c << ", d = " << d << RESEND;
	PRINT << "min( c, d ) = " << ::min(c, d) << RESEND;
	PRINT << "max( c, d ) = " << ::max(c, d) << RESEND;
	press_any_key();

	return 0;
}

//!SECTION