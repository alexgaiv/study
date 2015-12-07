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
	string ToString();
private:
	friend class Parser;

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
		LEX_NUMBER,
		LEX_EOL,
	};

	struct Lexem
	{
		lexem_t type;
		union
		{
			double value;
			int varIndex;
		};

		Lexem(lexem_t type = lexem_t(0)) : type(type) { }
		Lexem(lexem_t type, double value)
			: type(type), value(value) { }
		Lexem(lexem_t type, int varIndex)
			: type(type), varIndex(varIndex) { }
	};
	
	Stack<Lexem> poliz;
	Stack<Lexem> lexemStack;
	Map<double> varTable;
	Map<int> opTable;
	const char *str;

	bool IsFunc(lexem_t t) { return t >= LEX_COS && t <= LEX_LOG; }
	bool IsOperator(lexem_t t) { return t >= LEX_PLUS && t <= LEX_POW; }

	void FillOpTable();
	Lexem NextLexem();
	void MakePoliz();
};

Poliz::Poliz(const string &expr)
	: poliz(expr.size()), lexemStack(expr.size()),
	varTable(expr.size()), opTable(12)
{
	try {
		str = expr.c_str();
		FillOpTable();
		MakePoliz();
	}
	catch(char c)
	{
	
	}
	catch(Lexem l)
	{
	
	}
}

void Poliz::FillOpTable()
{
	const char *delims[12] = { "+", "-", "*", "/", "^", "cos", "sin", "tan", "atan", "log", "(", ")" };
	int priority[12] = { 1, 1, 2, 2, 3, 4, 4, 4, 4, 4, 0, 0 };
	for (int i = 0; i < 12; i++)
		opTable.Add(delims[i], priority[i]);
}

Poliz::Lexem Poliz::NextLexem()
{
	enum lexem_state
	{
		INITIAL,
		DIGIT,
		DELIM,
		DELIM_STR,
	};

	lexem_state state = INITIAL;
	int n = 0;

	while (true)
	{
		char c = *str;
		switch (state)
		{
		case INITIAL:
			if (isspace(c))
				str++;
			else if (isdigit(c)) {
				n = c - '0';
				str++;
				state = DIGIT;
			}
			else if (c == 0) {
				return Lexem(LEX_EOL);
			}
			else state = DELIM;
			break;
		case DIGIT:
			while (isdigit(c)) {
				n = n*10 + c - '0';
				c = *(++str);
			}
			return Lexem(LEX_NUMBER, (double)n);
		case DELIM:
		{
			int i = opTable.Find(string(1, c));
			if (i != -1) {
				str++;
				return Lexem(lexem_t(i));
			}
			if (isalpha(c))
				state = DELIM_STR;
			else throw c;
			break;
		}
		case DELIM_STR:
		{
			char buf[5] = { };
			int k = 0;
			while (k < 4 && isalpha(c)) {
				buf[k++] = c;
				c = *(++str);
			}
			int i = opTable.Find(string(buf));
			if (i != -1)
				return Lexem(lexem_t(i));
			else {
				int idx = varTable.Add(string(buf), 0);
				return Lexem(LEX_VAR, idx);
			}
		}
		}
	}
}

void Poliz::MakePoliz()
{
	Lexem l = NextLexem();
	while (l.type != LEX_EOL)
	{
		if (l.type == LEX_NUMBER || l.type == LEX_VAR)
			poliz.Push(l);
		else if (IsFunc(l.type) || l.type == LEX_LPAREN)
			lexemStack.Push(l);
		else if (l.type == LEX_RPAREN)
		{
			while (l.type != LEX_LPAREN)
			{
				if (lexemStack.IsEmpty()) throw l;
				poliz.Push(lexemStack.Pop());
			}
			lexemStack.Pop();
			if (!lexemStack.IsEmpty() && IsFunc(lexemStack.Top().type))
				poliz.Push(lexemStack.Pop());
		}
		else if (IsOperator(l.type)) {
			int p = opTable.GetRecordAt(l.type).GetValue();
			while (!lexemStack.IsEmpty() && IsOperator(lexemStack.Top().type) &&
				p <= opTable.GetRecordAt(lexemStack.Top().type).GetValue())
			{
				poliz.Push(lexemStack.Pop());
			}
			lexemStack.Push(l);
		}
		l = NextLexem();
	}
	while (!lexemStack.IsEmpty()) {
		Lexem l = lexemStack.Pop();
		if (!IsOperator(l.type)) throw l;
		poliz.Push(l);
	}
}

string Poliz::ToString()
{
	string s = "";

	while (!poliz.IsEmpty()) {
		Lexem l = poliz.Pop();
		if (l.type == LEX_VAR)
			s += varTable.GetRecordAt(l.varIndex).GetKey();
		else if (l.type == LEX_NUMBER)
		{
			char buf[20] = { };
			sprintf_s<20>(buf, "%f", (float)l.value);
			s += buf;
		}
		else if (l.type != LEX_EOL) {
			s += opTable.GetRecordAt(l.type).GetKey();
		}
	}

	return s;
}

#endif // _POLIZ_H_