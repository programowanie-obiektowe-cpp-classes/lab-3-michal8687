#pragma once

#include "Stocznia.hpp"
#include "Statki.hpp"

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