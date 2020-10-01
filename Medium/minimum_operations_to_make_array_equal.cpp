#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

int minOperations(int n) {
    int avg=0,operations=0;
    for(int i = 0; i<n; i++) {
        avg += 2*i + 1;
    }
    avg /= n;
    for(int i = 0; i<n; i++) {
        int val = 2*i+1;
        int op = abs(avg - val);
        operations += op;
    }
    
    return operations/2;
    
    /**
     * Alternative solutions:

    If n is even then resultant ans will be the sum of odd numbers starting from 1 to n/2 --> formula =>
		(number of terms)^2
		
		if n is odd then resultant ans will be the sum of even numbers starting from 2 to n/2 --> formula =>
		(number of terms)*(number of terms + 1)
        Now if you are thinking why sum of odd/ even numbers upto n/2 terms, Let me give you a brief idea :
		
			suppose n = 7, i.e array = [1, 3, 5, 7, 9, 11, 13]
			First, look at the middle element, we are going to convert whole array to this number.
			1) convert 5 and 9 to 6 and 8, then again convert them to 7 and 7, which costs --> 2
			2) convert 3 and 11 to 7 and 7 which costs                                                          --> 4
			3) convert 1 and 13 to 7 and 7 which costs                                                          --> 6

			So, ans will be 2 + 4 + 6 ===> 3 terms (n/2), where n is 7
			Therefore, ans = 3*(3 + 1).
		
    */
   return (n%2 == 0) ? (n/2)*(n/2) : (n/2)*((n/2)+1);

}

int main() {
    return 0;
}