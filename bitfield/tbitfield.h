#ifndef _TBITFIELD_H_
#define _TBITFIELD_H_

using namespace System;

class TBitField
{
public:
	TBitField(int USize = 0);
	TBitField(const TBitField &bf);
	~TBitField();

	TBitField &operator=(const TBitField &bf);

	void AddElem(int index);
	void DelElem(int index);
	bool IsElemPresent(int index);

	TBitField operator&(const TBitField &bf);
	TBitField operator|(const TBitField &bf);
	TBitField operator~();

	String ^ToString();
private:
	int *mem;
	int memSize;

	int GetElemIndex(int idx);
	int GetBitIndex(int idx);
};

#endif // _TBITFIELD_H_