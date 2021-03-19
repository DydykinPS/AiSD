#pragma once
#include <iostream>
#include "../List_lib/List.h"	
#include "../Monom_lib/Monom.h"
using namespace std;

class Polynom {
	List<Monom> list;
public:
	Polynom() {}

	//создание полинома с использованием входной строки
	Polynom (string str) {
	List<string> monom_str;

	string s = "";
	for (int i = 0; i < str.length(); i++) {
		string s = "";
		while ((i < str.length()) && (str[i] != '+') && (str[i] != '-')) {
			if (i > 0 && str[i - 1] == '-')
				s.insert(0, "-");
			s += str[i];
			i++;
		}
		monom_str.addLast(s);
	}
	if (s.length() > 0) {
		monom_str.addLast(s);
	}
	
	Iterator<string> itr = monom_str.getIterator();
	while (itr.hasNext()) {
		Monom m;
		string m_str = itr.val();
		int state = 0;
		s = "";
		for (int i = 0; i < m_str.length() - 1; i++) {
			if ((m_str[i] == 'x') && ((m_str[i + 1] == 'y') || (m_str[i + 1] == 'z') || (m_str[i + 1] == '+') || (m_str[i + 1] == 'y')))
				m_str.insert(i + 1, "1");
			if((m_str[i] == 'y') && ((m_str[i + 1] == 'x') || (m_str[i + 1] == 'z') || (m_str[i + 1] == '+') || (m_str[i + 1] == 'y')))
				m_str.insert(i + 1, "1");
			if ((m_str[i] == 'z') && ((m_str[i + 1] == 'x') || (m_str[i + 1] == 'y') || (m_str[i + 1] == '+') || (m_str[i + 1] == 'y')))
				m_str.insert(i + 1, "1");
			}

		if((m_str[m_str.length()-1]=='x')||(m_str[m_str.length()-1] == 'y')||(m_str[m_str.length()-1] == 'z'))
			m_str.insert(m_str.length(), "1");

		for (int i = 0; i < m_str.length(); i++) {
			if (m_str[i] == 'x') {
				m.Analys(state, s);
				state = 1;
				s = "";
			}
			else
 				if (m_str[i] == 'y') {
					m.Analys(state, s);
					state = 2;
					s = "";
				}
				else
					if (m_str[i] == 'z') {
						m.Analys(state, s);
						state = 3;
						s = "";
					}
					else {
						s += m_str[i];
					}
			}
		m.Analys(state, s);

		list.addLast(m);
		itr.next();
		}
	}
	Polynom(const Polynom& p) {
		list = p.list;
	}

	void add(Monom m) {
		list.addLast(m);
	}

	Polynom& operator=(const Polynom& p) {
		list = p.list;
		return *this;
	}

	Polynom operator+(Polynom& p) {
		Polynom res; 
		Iterator<Monom> it1 = list.getIterator();
		Iterator<Monom> it2 = p.list.getIterator();
		while (it1.hasNext() && it2.hasNext()) {
			if (it1.val().getInd() == it2.val().getInd()) {
				if ((it1.val().getC() + it2.val().getC()) != 0)
					res.add(it1.val() + it2.val());
				it1.next();
				it2.next();
			}
			else {
				if (it1.val().getInd() > it2.val().getInd()) {
					res.add(it1.val());
					it1.next();
				}
				else
				{
					if (it1.val().getInd() < it2.val().getInd()) {
						res.add(it2.val());
						it2.next();
					}
				}
			}
		}
		if (!it1.hasNext()) {
			while (it2.hasNext()) {
				res.add(it2.val());
				it2.next();
			}
		}
		else {
			while (it1.hasNext()) {
				res.add(it1.val());
				it1.next();
			}
		}
		return res;
	}

	Polynom operator-(Polynom& p) {
		Polynom res;
		Iterator<Monom> it1 = list.getIterator();
		Iterator<Monom> it2 = p.list.getIterator();
		while (it1.hasNext() && it2.hasNext()) {
			if (it1.val().getInd() == it2.val().getInd()) {
				if ((it1.val().getC() - it2.val().getC()) != 0)
					res.add(it1.val() - it2.val());
				it1.next();
				it2.next();

			}
			else {
				if (it1.val().getInd() > it2.val().getInd()) {
					res.add(it1.val());
					it1.next();
				}
				else
				{
					if (it1.val().getInd() < it2.val().getInd()) {
						Monom temp(-it2.val().getC(), it2.val().getInd());
						res.add(temp);
						it2.next();
					}
				}
			}
		}
		if (!it1.hasNext()) {
			while (it2.hasNext()) {
				Monom temp(-it2.val().getC(), it2.val().getInd());
				res.add(temp);
				it2.next();
			}
		}
		else {
			while (it1.hasNext()) {
				res.add(it1.val());
				it1.next();
			}
		}
		return res;
	}

	Polynom operator*(Polynom& p) {
		Polynom res;
		Iterator<Monom> it1 = list.getIterator();
		while (it1.hasNext()) {
			Iterator<Monom> it2 = p.list.getIterator();
			while (it2.hasNext()) {
				res.add(it1.val() * it2.val());
				it2.next();
			}
			it1.next();
		}
		return res;
	}

	double result(double x, double y, double z) {
		int p = 20, i, j, k;
		double res = 0;
		Iterator<Monom> it = list.getIterator();
		while (it.hasNext()) {
			i = it.val().getInd() / (p * p);
			j = (it.val().getInd() - i * p * p) / p;
			k = (it.val().getInd() - i * p * p) % p;
			res += it.val().getC() * exp(i * log(x)) * exp(j * log(y)) * exp(k * log(z));
			it.next();
		}
		return res;
	}

	bool operator==(const Polynom& p) {
		return list == p.list;
	}

	friend ostream& operator<<(ostream& o, Polynom& p) {
		o << p.list;
		return o;
	}
};