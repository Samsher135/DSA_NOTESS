#include <bits/stdc++.h>
using namespace std;

// sieve of eratosthenes
// The simple seive approach is to use a boolean array to mark the non-primes.
// The array is initialized with all true values.
// Then, we iterate over the array till the square root of the n and mark the multiples of the current index as false.
// Time complexity: O(n*log(log(n)))
void simplesieve(int n)
{
	vector<bool> v(n + 1, 1);
	for (int i = 2; i * i <= n; i++)
	{
		if (v[i] == 1)
		{
			for (int j = i * i; j <= n; j += i)
			{
				v[j] = 0;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 1)
		{
			cout << i << " ";
		}
	}
}

// segmented sieve
// The need of segmented sieve is to reduce the space complexity and also the array cannot store more than 10^7 elements.
// 1. we will find the prime numbers in the range [2,sqrt(n)] and store them in an array using the simple sieve.
// 2. we will take small segments of array of size sqrt(n) and mark the non-prime numbers in the segment using mapping explained in the code.
void simpleSieve(int limit, vector<int> &prime)
{
	// Create a boolean array "mark[0..n-1]" and initialize
	// all entries of it as true. A value in mark[p] will
	// finally be false if 'p' is Not a prime, else true.
	vector<bool> mark(limit + 1, true);

	for (int p = 2; p * p < limit; p++)
	{
		// If p is not changed, then it is a prime
		if (mark[p] == true)
		{
			// Update all multiples of p
			for (int i = p * p; i < limit; i += p)
				mark[i] = false;
		}
	}

	// Print all prime numbers and store them in prime
	for (int p = 2; p < limit; p++)
	{
		if (mark[p] == true)
		{
			prime.push_back(p);
			cout << p << " ";
		}
	}
}

// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n)
{
	// Compute all primes smaller than or equal
	// to square root of n using simple sieve
	int limit = floor(sqrt(n)) + 1;
	vector<int> prime;
	prime.reserve(limit);
	simpleSieve(limit, prime);

	// Divide the range [0..n-1] in different segments
	// We have chosen segment size as sqrt(n).
	int low = limit;
	int high = 2 * limit;

	// While all segments of range [0..n-1] are not processed,
	// process one segment at a time
	while (low < n)
	{
		if (high >= n)
			high = n;

		// To mark primes in current range. A value in mark[i]
		// will finally be false if 'i-low' is Not a prime,
		// else true.
		bool mark[limit + 1];
		memset(mark, true, sizeof(mark));

		// Use the found primes by simpleSieve() to find
		// primes in current range
		for (int i = 0; i < prime.size(); i++)
		{
			int val = prime[i];
			int lower = (low / val);
			// here lower means the first multiple of prime which is in range [low,high]
			// for eg: 3's first multiple in range [28,40] is 30
			if (lower <= 1)
			{
				lower = val + val;
			}
			else if (low % val)
			{
				lower = (lower * val) + val;
			}
			else
			{
				lower = (lower * val);
			}

			/* Mark multiples of prime[i] in [low..high]:
				We are marking j - low for j, i.e. each number
				in range [low, high] is mapped to [0, high-low]
				so if range is [50, 100] marking 50 corresponds
				to marking 0, marking 51 corresponds to 1 and
				so on. In this way we need to allocate space only
				for range */
			for (int j = lower; j < high; j += prime[i])
				mark[j - low] = false;
		}

		// Numbers which are not marked as false are prime
		for (int i = low; i < high; i++)
			if (mark[i - low] == true)
				cout << i << " ";

		// Update low and high for next segment
		low = low + limit;
		high = high + limit;
	}
}

// GCD:
// GCD of two numbers is the largest number that divides both of them with remainder 0.
// Eg: GCD of 12 and 18 is 6.
// applications of GCD:
// 1. To simplify fractions.
// 2. To find the LCM of two numbers.
// 3. To find largest equal number of groups i.e we can make each group of maximum and equal 6 persons if two class has 12 and 18 students.

void gcditerative(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	cout << a << endl;
}

// LCM:
// LCM is the smallest number that is common in table of all the numbers or it is a smallest number divisible by all the numbers.
// Eg: LCM of 8 and 4 is 8.
// applications of LCM:
// 1. To analyse when something will happen again at the same time.
//    i.e. if a exercises every 8 days and b exercises every 4 days, then they will exercise together at every 8th day.

void lcmiterative(int a, int b)
{
	int lcm = a * b;
	while (a != 0 && b != 0)
	{
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	lcm /= (a + b);
	cout << lcm << endl;
}

// Modulo arithmetic:
//  % is the modulo operator. It returns the remainder of the division of two numbers.
//  The a%n is always 0 < n-1.
//  some properties of modulo arithmetic:
//  1. a%n = a - n*(a/n)
//  2. (a+b)%n = (a%n + b%n)%n
//  3. (a*b)%n = (a%n * b%n)%n
//  above formulas is used when additon or mul of two numbers is greater than 10^9 and we have calc the modulo of the numbers.

// significance of 10^9+7:-
// 1. 10^9+7 is a prime number.
// 2. It is common convention used by programmers to remember largest range of integer number in c++.
// 3. There are some algo which grows rapidly like factorial of a number where we cannot store factorial of a some numbers
//    in a single variable. so to check the answer is correct or not the coding questions tell to return the modulo of the answer.

// fast exponentiation:
// 1. It is used to calculate the power of a number in O(log n) time.
// 2. Properties of exponentiation:
//    a. (a^b) = (a^(b/2))^2; if b is even.
//    b. (a^b) = (a^(b/2))^2 * a; if b is odd.

// modulare exponentiation using iterative method:
// 1. Every iteration if number is even then the square of the previous answer is calculated and n is divided by 2.
// 2. If number is odd then the square of the previous answer is calculated and n is divided by 2 and the result is multiplied by a.
int modularExponentiation(long long int x, long long int n, int m)
{
	// Write your code here.
	int res = 1; // Initialize result

	x = x % m; // Update x if it is more than or equal to m

	if (x == 0)
		return 0; // In case x is divisible by m;

	while (n > 0)
	{
		// If n is odd, multiply x with result
		if (n & 1)
			res = (res * x) % m;

		// n must be even now
		n = n >> 1; // n = n/2
		x = (x * x) % m;
	}
	return res;
}


//pegionhole principle:
// It states that if there are n+1 pegions and n holes then there will be at least one hole contain multiple pegions.
// if n is number of pegion holes and kn+1 is number of pegions then there will be at least one hole contain k + 1 pegions.
// for eg if a bag contain 10 marbles of 3 different colors we have tell how much marbles we have to randomly pick from the bag
// so that we get at least 4 marbles of same color.
// soln:- n = 3 colors, K + 1 = 4 marbles, kn + 1 = 10 marbles, so we have to pick at least 10 marbles from bag.

//catalan numbers:-
// It is a series where c0 = 1 and c1 = 1 and cn = submission of C0 to n-1 * Cn-1 to 0
// therefore C2 = C0*C1 + C1*C0, C3 = C0*C2 + C1*C1 + C2*C0, C4 = C0*C3 + C1*C2 + C2*C1 + C3*C0...

void catalan(int n)
{
	int C[n + 1];
	C[0] = C[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		C[i] = 0;
		int l=0,r=i-1;
		while(l != i && r!=-1){
			C[i] += C[l] * C[r];
			l++;
			r--; 
		}
	}
	cout << C[n];
}

//Inclusion-exclusion principle:-
// If in class n1 students select x1 language and n2 students select x2 language and n3 students selects both languages we have to find number of students in a class.
// we will add n1 and n2 and subtract n3 to find the number of students in a class.
//Eg:- numbers between 1 to 1000 divisible either by 5 or 7.

int divisible(int n, int a, int b){
	int c1 = n/a;
	int c2 = n/b;

	int c3 = n/(a*b);

	return c1+c2-c3;
}

int main(){
	catalan(9);
	return 0;
}