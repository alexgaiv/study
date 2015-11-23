#ifndef _POLIZ_H_
#define _POLIZ_H_

#include <string>
#include "parser.h"
#include "stack.h"
#include "map.h"
using namespace std;


class Poliz
{
public:
	Poliz(const string &expr = "");
private:
	friend class Parser;

	static const char *delims[];
	static int priority[];

	enum lexem_t {
		LEX_PLUS = 0,
		LEX_MINUS,
		LEX_MULT,
		LEX_DIV,
		LEX_POW,
		LEX_COS,
		LEX_SIN,
		LEX_TAN,
		LEX_ATAN,
		LEX_LOG,
		LEX_LPAREN,
		LEX_RPAREN,
		LEX_VAR,
		LEX_NUMBER
	};

	struct Lexem
	{
		lexem_t type;
		union
		{
			double value;
			int varIndex;
		};
	};
	
	Stack<Lexem> poliz;
	Stack<Lexem> lexemStack;
	Map<double> varTable;
	Map<int> opTable;

	void FillOpTable();
	Lexem NextLexem();
};

const char *Poliz::delims[] = { "+", "-", "*", "/", "^", "cos", "sin", "tan", "atan", "log", "(", ")" };
int Poliz::priority[] = { 1, 1, 2, 2, 3, 4, 4, 4, 4, 4 };

Poliz::Poliz(const string &expr)
	: poliz(expr.size()), lexemStack(100),
	varTable(expr.size()), opTable(10)
{
	FillOpTable();
}

void Poliz::FillOpTable()
{
	for (int i = 0; i < 10; i++)
		opTable.Add(delims[i], priority[i]);
}

Lexem Poliz::NextLexem()
{
	
}

#endif // _POLIZ_H_