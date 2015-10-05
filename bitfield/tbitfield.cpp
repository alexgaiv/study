#include "tbitfield.h"
#include <math.h>

TBitField::TBitField(int USize)
{
	memSize = ceil((double)USize / (8 * sizeof(int)));
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

void TBitField::AddElem(int index)
{
	mem[GetElemIndex(index)] |= (1 << GetBitIndex(index));
}

void TBitField::DelElem(int index)
{
	mem[GetElemIndex(index)] &= ~(1 << GetBitIndex(index));
}

bool TBitField::GetElem(int index)
{
	return (mem[GetElemIndex(index)] >> index) & 1;
}

TBitField TBitField::operator&(const TBitField &bf)
{
	TBitField tmp;
	if (memSize != bf.memSize) return tmp;

	for (int i = 0; i < memSize; i++)
		tmp.mem[i] = mem[i] & bf.mem[i];
	return tmp;
}

TBitField TBitField::operator|(const TBitField &bf)
{
	TBitField tmp;
	if (memSize != bf.memSize) return tmp;

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