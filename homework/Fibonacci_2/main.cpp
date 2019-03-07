#include <iostream>

// Helper function that multiplies 2 matrices F and M of size 2 X 2, and
// puts the multiplication result back to F[][]
void multiply(long long F[2][2], long long M[2][2]) {
    long long x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % 1000000007;
    long long y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % 1000000007;
    long long z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % 1000000007;
    long long w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % 1000000007;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

// Helper function that calculates F[][] raise to the power n and puts the 
// result in F[][]
// Note that this function is designed only for fib() and won\'t work as general 
// power function
// [=== Fast Matrix Exponentiation ===]
void power(long long F[2][2], long long n) {
    if (n == 0 || n == 1) {
        return;
    }
    long long M[2][2] = { { 1, 1 },{ 1, 0 } };
    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0) {
        multiply(F, M);
    }
}

long long fib(long long n) {
    long long F[2][2] = { { 1, 1 },{ 1, 0 } };
    if (n == 0) {
        return 0;
    }
    power(F, n - 1);
    return F[0][0];
}

int main() {
    long long num;
    while (std::cin >> num) {
        std::cout << (fib(num) % 1000000007) << std::endl;
    }
}
