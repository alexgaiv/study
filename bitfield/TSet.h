#ifndef _TSET_H
#define _TSET_H

#include "tbitfield.h"

class TSet
{
public:
	TSet(int USize = 0);
	TSet(const TSet &s);

	void AddElem(int elem);
	void DelElem(int elem);
	bool HasElem(int elem);

	TSet &operator=(const TSet &s);
	TSet operator*(const TSet &s);
	TSet operator+(const TSet &s);
	TSet operator-();

	void FromString(String ^s);
	String ^ToString();
private:
	int USize;
	TBitField bitField;
};

TSet::TSet(int USize)
{
	this->USize = USize;
	bitField = TBitField(USize);
}

TSet::TSet(const TSet &s)
{
	USize = s.USize;
	bitField = s.bitField;
}

void TSet::AddElem(int elem)
{
	bitField.SetBit(elem);
}

void TSet::DelElem(int elem)
{
	bitField.ClearBit(elem);
}

bool TSet::HasElem(int elem)
{
	return bitField.HasBit(elem);
}


TSet &TSet::operator=(const TSet &s)
{
	USize = s.USize;
	bitField = s.bitField;
}

TSet TSet::operator*(const TSet &s)
{
	TSet tmp;
	tmp.bitField = bitField & s.bitField;
	tmp.USize = tmp.bitField.GetSize();
}

TSet TSet::operator+(const TSet &s)
{

}

TSet TSet::operator-()
{

}

void TSet::FromString(String ^s)
{

}

String ^TSet::ToString()
{

}

#endif // _TSET_H