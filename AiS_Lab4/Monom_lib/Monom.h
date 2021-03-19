#include <iostream>
using namespace std;
#include "../List_lib/List.h"

class Monom{
	double c; //коэффициент монома
	int ind; //свертка степеней монома
public:
	Monom (double _c = 1.0, int _ind = 0) { c = _c; ind = _ind; } 

	Monom (const Monom& tm) { c = tm.c; ind = tm.ind; }

	~Monom() { c = 0; ind = 0; }

	//получить, установить сверстку степеней
	void setInd (int _ind) { ind = _ind; }
	int getInd() { return ind; }
	
	//получить, установить коэффициент
	void setC(double _c) { c = _c; }
	double getC() { return c; }

	Monom& operator= (const Monom& tm) { c = tm.c; ind = tm.ind; return *this; }

	bool operator == (const Monom& tm) { if ((c == tm.c) && (ind == tm.ind)) return true; else return false; }

	bool operator != (const Monom& tm) { if ((c != tm.c) || (ind != tm.ind)) return true; else return false; }

	friend ostream& operator << (ostream& os, Monom& tm) {
		int p = 20, i, j, k;
		i = tm.ind / (p * p);
		j = (tm.ind - i * p * p) / p;
		k = (tm.ind - i * p * p) % p;
		if (tm.c > 0)
			os << "+" << tm.c << "x^" << i << "y^" << j << "z^" << k;
		else os << tm.c << "x^" << i << "y^" << j << "z^" << k;
		return os;
	}

	void Analys(int _state, string _s) {
		int p = 20, k;
		if (_state == 0 && _s.length() > 0)
			c = atof(_s.c_str());
		if (_state == 1 && _s.length() > 0) {
			k = atof(_s.c_str());
			ind += k * p * p;
		}
		if (_state == 2 && _s.length() > 0) {
			k = atof(_s.c_str());
			ind += k * p;
		}
		if (_state == 3 && _s.length() > 0) {
			k = atof(_s.c_str());
			ind += k;
		}
	}

	Monom operator-(const Monom& m) {
		if (m.ind != ind) throw -1;
		Monom res;
		res.ind = ind;
		res.c = c - m.c;
		return res;
	}

	Monom operator+(const Monom& m) {
		if (m.ind != ind) throw - 1;
		Monom res;
		res.ind = ind;
		res.c = c + m.c;
		return res;
	}

	Monom operator*(const Monom& m) {
		Monom res;
		res.c = c * m.c;
		res.ind = ind + m.ind;
		return res;
	}

};