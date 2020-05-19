#include "fourier.hpp"
#include "complex.hpp"
#include <vector>
#include <cmath>

std::vector<Complex> f2s(std::vector<Complex> vec_f) {
	int n = vec_f.size();
	std::vector<Complex> vec_s;
	vec_s.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vec_s[i] += vec_f[j] ^ (-2 * M_PI * j * i / n);
		}
		vec_s[i] = vec_s[i] / n;
	}
	return vec_s;
}

std::vector<Complex> s2f(std::vector<Complex> vec_s) {
	int n = vec_s.size();
	std::vector<Complex> vec_f;
	vec_f.resize(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vec_f[i] += vec_s[j] ^ (2 * M_PI * j * i / n);
		}
	}
	return vec_f;
}


int fft_normalize(std::vector<Complex> &vec_f) {
	int size = vec_f.size(), n = 1;
	while (size > n) {
		n <<= 1;
	}
	vec_f.resize(n);
	for (int i = size; i < n; i++) {
		vec_f[i] = 0;
	}
	return n;
}

void fft(std::vector<Complex> &vec_f) {
	int old_n = vec_f.size(), n = fft_normalize(vec_f), k = n / 2;
	if (old_n == 1) {
		return;
	}
	std::vector<Complex> vec_f1, vec_f2;
	vec_f1.resize(k);
	vec_f2.resize(k);
	for (int i = 0, j = 0; i < n; i += 2, j++) {
		vec_f1[j] = vec_f[i];
		vec_f2[j] = vec_f[i + 1];
	}
	fft(vec_f1);
	fft(vec_f2);
	for (int i = 0; i < k; i++) {
		vec_f[i] = vec_f1[i] + vec_f2[i] ^ (-2 * M_PI * i / n);
		vec_f[i + k] = vec_f1[i] + vec_f2[i] ^ (-2 * M_PI * i / n);
	}
}