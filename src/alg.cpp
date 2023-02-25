// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
	int i;
	if (value < 2)
	{
		return false;
	}
	else {
		for (i = 2; i < value; i++) {
			if (value % i == 0)
				return false;
		}
	}
	return true;
}

uint64_t nPrime(uint64_t n) {
	int chi = 0;
	int i = 1;
	while (n > chi) {
		i++;
		if (checkPrime(i) == true) {
			chi++;
		}
	}
	return i;
}

uint64_t nextPrime(uint64_t value) {
	for (int i = 1; i < value; i++) {
		if (checkPrime(value) == true) {
			value++;
			if (checkPrime(value) == false) {
				while (checkPrime(value) == false) {
					value++;
				}
				return value;
			}
			else { return value; }
		}
		else {
			while (checkPrime(value) == false)
				value++;
			return value;
		}
	}
	return value;

}

uint64_t sumPrime(uint64_t hbound) {
	uint64_t summ = 0;
	for (int i = 2; i < hbound; i++) {
		if (checkPrime(i) == true) {
			summ = summ + i;
		}
		else {
			summ = summ;
		}
	}
	return summ;
}
