#include "complex.hpp"
#include "fourier.hpp"
#include <vector>
#include <cmath>
#include <iostream>

int main() {
	Complex number;
	std::vector<Complex> vec_f = {1 , 6 , 2 , 5 , 3 , 4}, vec_s, vec_check;
	vec_s = f2s(vec_f);
	vec_check = s2f(vec_s);
	int i = 0;
	for (auto &num: vec_s) {
		std::cout << "s[" << i << "] = " << num;
		std::cout << "|s[" << i++ << "]| = " << num.amp() << std::endl;
	}
	i = 0;
	for (auto &num: vec_check) {
		std::cout << "f[" << i++ << "] = " << num;
	}
	std::cout << "now FFT :\n";
	fft(vec_f);
	i = 0;
	for (auto &num: vec_f) {
		std::cout << "c[" << i++ << "] = " << num;
	}
	return 0;
}