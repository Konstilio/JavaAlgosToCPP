#pragma once

namespace Algorithm
{
	constexpr long long fact(long long accumulator, long long n) {

		if (n == 1)
			return accumulator;

		return fact(accumulator * n, n - 1);
	}

	constexpr long long factorial(long long n) {
		return fact(1, n);
	}

	constexpr long long factorialIterative(long long n) {
		long long data = 1;
		for (long long i = 2; i <= n; ++i)
			data *= i;

		return data;
	}
}
