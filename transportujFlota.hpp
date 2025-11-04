#pragma once

#include "Stocznia.hpp"

class Statek {
public:
	virtual ~Statek() {}
	virtual unsigned int transportuj()
	{
		return 0;
	}
};

class Tankowiec : public Statek {
public:
	unsigned int transportuj() override
	{
		return 500;
	}
};

class Zaglowiec : public Statek {
public:
	unsigned int transportuj() override
	{
		return 100;
	}
};

class Stocznia {
public:
	Stocznia()
	{
		srand(time(NULL));
	}

	Statek* operator()()
	{
		int min = 1;
		int max = 2;
		int L = max - min + 1;
		selected = rand() % L + min;
		if (selected == 2)
			return new Tankowiec{};
		else
			return new Zaglowiec{};
	}
private:
	double selected;
};

unsigned int transportujFlota(unsigned int towar) {
	if (towar == 0)
	{
		return 0;
	}
	else
	{
		Stocznia stocznia{};
		int przetransportowano = 0;
		int zaglowce = 0;

		while (przetransportowano < towar) {
			Statek* statek = stocznia();
			int ilosc = statek->transportuj();
			przetransportowano = przetransportowano + ilosc;
			if (dynamic_cast<Zaglowiec*>(statek))
				zaglowce = zaglowce + 1;

			delete statek;
		}
		return zaglowce;
	}
}