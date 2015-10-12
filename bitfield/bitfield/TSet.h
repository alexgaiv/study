#ifndef _TSET_H
#define _TSET_H

#include "tbitfield.h"

class TSet
{
public:
	TSet(int USize = 0);
	TSet(const TSet &s);

	int GetSize() { return size; }

	void AddElem(int elem);
	void DelElem(int elem);
	bool HasElem(int elem);

	TSet &operator=(const TSet &s);
	TSet operator*(const TSet &s);
	TSet operator+(const TSet &s);
	TSet operator-();

	bool FromString(String ^s);
	String ^ToString();
private:
	int size;
	TBitField bitField;
	void SplitStr(String ^s, array<String ^> ^words, int &numWords);
};

TSet::TSet(int USize) {
	this->size = USize;
	bitField = TBitField(size);
}

TSet::TSet(const TSet &s) {
	size = s.size;
	bitField = s.bitField;
}

void TSet::AddElem(int elem) {
	bitField.SetBit(elem);
}

void TSet::DelElem(int elem) {
	bitField.ClearBit(elem);
}

bool TSet::HasElem(int elem) {
	return bitField.HasBit(elem);
}

TSet &TSet::operator=(const TSet &s) {
	size = s.size;
	bitField = s.bitField;
	return *this;
}

TSet TSet::operator*(const TSet &s) {
	TSet tmp;
	tmp.bitField = bitField & s.bitField;
	tmp.size = tmp.bitField.GetSize();
	return tmp;
}

TSet TSet::operator+(const TSet &s) {
	TSet tmp;
	tmp.bitField = bitField | s.bitField;
	tmp.size = tmp.bitField.GetSize();
	return tmp;
}

TSet TSet::operator-() {
	TSet tmp;
	tmp.bitField = ~bitField;
	tmp.size = tmp.bitField.GetSize();
	return tmp;
}

bool TSet::FromString(String ^s)
{
	int numWords = 0;
	array<String ^> ^words = gcnew array<String ^>(s->Length / 2 + 1);

	SplitStr(s, words, numWords);

	bitField.ClearAll();
	for (int i = 0; i < numWords; i++)
	{
		int index = 0;
		if (!Int32::TryParse(words[i], index))
			return false;
		if (index < 0 || index >= size)
			return false;

		bitField.SetBit(index);
	}
	return true;
}

String ^TSet::ToString()
{
	return bitField.ToString();
}

void TSet::SplitStr(String ^s, array<String ^> ^words, int &numWords)
{
	s += " ";
	numWords = 0;
	while (s->Length > 0) {
		int l = s->IndexOf(' ');
		if (l > 0) {
			words[numWords++] = s->Substring(0, l);
		}
		s = s->Remove(0, l + 1);
	}
}

#endif // _TSET_H