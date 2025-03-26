#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The " << n << "th term in Fibonacci series is: " << fibonacci(n) << endl;
    return 0;
}


