#ifndef FOURIER_HPP
#define FOURIER_HPP

#include "complex.hpp"
#include <vector>

std::vector<Complex> f2s(std::vector<Complex> vec_f);

std::vector<Complex> s2f(std::vector<Complex> vec_s);

int fft_normalize(std::vector<Complex> &vec_f);

void fft(std::vector<Complex> &vec_f);

#endif