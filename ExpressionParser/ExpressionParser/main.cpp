#include "parser.h"

int main()
{
	Poliz p("a + bv - cos(atan(342))/3");
	const char *s = p.ToString().data();
	return 0;
}