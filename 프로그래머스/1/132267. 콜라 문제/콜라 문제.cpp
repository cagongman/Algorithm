#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
	int answer = 0;

	while (n >= a )
	{
		int div = (n / a) * b;
		int mod = n % a;

		n = div + mod;
		answer += div;
	}

	return answer;
}