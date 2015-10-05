#ifndef _TBITFIELD_H_
#define _TBITFIELD_H_

#include <string>
#include <math.h>

using namespace std;
using namespace System;

class TBitField
{
public:
	TBitField(int size = 0);
	TBitField(const TBitField &bf);
	~TBitField();

	int GetSize() const { return numBits; };

	void SetBit(int index);
	void ClearBit(int index);
	bool HasBit(int index);

	TBitField &operator=(const TBitField &bf);
	TBitField operator&(const TBitField &bf);
	TBitField operator|(const TBitField &bf);
	TBitField operator~();

	String ^ToString();
private:
	int *mem;
	int memSize;
	int numBits;

	int GetElemIndex(int idx);
	int GetBitIndex(int idx);
};

TBitField::TBitField(int size)
{
	numBits= size;
	memSize = ceil((double)size / (8 * sizeof(int)));
	mem = new int[memSize];
	memset(mem, 0, memSize*sizeof(int));
}

TBitField::TBitField(const TBitField &bf)
{
	memSize = bf.memSize;
	mem = new int[bf.memSize];
	memcpy(mem, bf.mem, memSize*sizeof(int));
}

TBitField::~TBitField()
{
	delete[] mem;
}

TBitField &TBitField::operator=(const TBitField &bf)
{
	if (memSize != bf.memSize) {
		delete[] mem;
		mem = new int[bf.memSize];
	}
	memSize = bf.memSize;
	memcpy(mem, bf.mem, memSize*sizeof(int));
	return *this;
}

int TBitField::GetElemIndex(int idx)
{
	return idx / (8 * sizeof(int));
}

int TBitField::GetBitIndex(int idx)
{
	return idx % (8 * sizeof(int));
}

void TBitField::SetBit(int index)
{
	mem[GetElemIndex(index)] |= (1 << GetBitIndex(index));
}

void TBitField::ClearBit(int index)
{
	mem[GetElemIndex(index)] &= ~(1 << GetBitIndex(index));
}

bool TBitField::HasBit(int index)
{
	return (mem[GetElemIndex(index)] >> index) & 1;
}

TBitField TBitField::operator&(const TBitField &bf)
{
	TBitField tmp(min(numBits, bf.numBits));

	for (int i = 0; i < tmp.memSize; i++)
		tmp.mem[i] = mem[i] & bf.mem[i];
	return tmp;
}

TBitField TBitField::operator|(const TBitField &bf)
{
	TBitField tmp(max(numBits, bf.numBits));

	for (int i = 0; i < memSize; i++)
		tmp.mem[i] = mem[i] | bf.mem[i];
	return tmp;
}

TBitField TBitField::operator~()
{
	TBitField tmp = *this;

	for (int i = 0; i < memSize; i++)
		tmp.mem[i] = ~mem[i];
	return tmp;
}

String ^TBitField::ToString()
{
	String ^s = "";
	for (int i = 0; i < memSize; i++)
		for (int j = 0; j < 8*sizeof(int); j++) {
			if (mem[i] & (1 << j)) {
				s += Convert::ToString((int)(8*sizeof(int)*i + j), 10) + " ";
			}
		}
	return s;
}

#endif // _TBITFIELD_H_