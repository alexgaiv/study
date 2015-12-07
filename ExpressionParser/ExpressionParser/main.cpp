#include "parser.h"

int main()
{
	Poliz p("a + bv - cos(atan(342))/3");
	string s = p.ToString();
	return 0;
}