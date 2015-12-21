#ifndef _PARSER_H_
#define _PARSER_H_

#include "poliz.h"

class Parser
{
public:
	Parser(string expr);
	TMap<double> *GetVarTable() { return &poliz.varTable; }
	string GetPoliz() { return poliz.ToString(); }
	double Evaluate();

	string LastError() {
		if (lastError == "") {
			string s = lastError;
			lastError = "";
			poliz.LastError();
			return s;
		}
		return poliz.LastError();
	}
private:
	Poliz poliz;
	TStack<double> st;
	string lastError;
};

Parser::Parser(string expr) : poliz(expr)
{
	st = TStack<double>(poliz.polizSize);
}

double Parser::Evaluate()
{
	try {
		int i = 0;
		double op1, op2;
		while (i < poliz.polizSize)
		{
			Lexem l = poliz.poliz[i];
			if (l.IsOperator()) {
				if (st.GetCount() < 2) throw false;
				op2 = st.Pop();
				op1 = st.Pop();

				switch (l.type)
				{
				case LEX_PLUS:
					st.Push(op1 + op2);
					break;
				case LEX_MINUS:
					st.Push(op1 - op2);
					break;
				case LEX_MULT:
					st.Push(op1 * op2);
					break;
				case LEX_DIV:
					st.Push(op1 / op2);
					break;
				case LEX_POW:
					st.Push(pow(op1, op2));
					break;
				}
			}
			else if (l.IsFunc()) {
				if (st.IsEmpty()) throw false;
				op1 = st.Pop();
				switch (l.type)
				{
				case LEX_SQRT:
					st.Push(sqrt(op1));
					break;
				case LEX_COS:
					st.Push(cos(op1));
					break;
				case LEX_SIN:
					st.Push(sin(op1));
					break;
				case LEX_TAN:
					st.Push(tan(op1));
					break;
				case LEX_ATAN:
					st.Push(atan(op1));
					break;
				case LEX_LOG:
					st.Push(log(op1));
					break;
				}
			}
			else if (l.type == LEX_NUMBER) {
				st.Push(l.value);
			}
			else if (l.type == LEX_VAR) {
				st.Push(poliz.varTable.GetValueAt(l.varIndex));
			}
			i++;
		}
		return st.Pop();
	}
	catch(bool) {
		lastError = "Computation failed";
	}
	return 0.0;
}

#endif // _PARSER_H_