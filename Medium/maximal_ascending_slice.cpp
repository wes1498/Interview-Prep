#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

// DemonWare OA Question
/**
  A non-empty zero-indexed array A consisting of N integers is given. A slice of that array is a pair of integers (P, Q) such that O <= P <= Q <= N

Integer P is called the beginning of the slice; integer Q is called the end of the slice. The number Q - P + 1 is called the size of the slice. A slice (P, Q) of array A is called ascending if the corresponding items form a strictly increasing sequence: A[P] < A[P + 1] < ... < A[Q - 1] < A[Q].

Note that we consider a slice (P, P) consisting of one element to be ascending.

For example, consider array A such that:

A[0] = 2
A[1] = 2
A[2] = 2
A[3] = 2
A[4] = 1
A[5] = 2
A[6] = -1
A[7] = 2
A[8] = 1
A[9] = 3
Pair (0, 3) is a slice of array A of size 4 that is not ascending.

Pair (2, 2) is a slice of size 1 that is ascending.

Pair (4, 5) is a slice of size 2 that is ascending.

Pair (6, 7) and (8, 9) are other slices of size 2 that are ascending.

There is no slice of array A that is ascending and has size greater than 2.

Write a function:

    def solution(A)
that, given a zero-indexed array consisting of N integers, returns the beginning of any ascending slice of maximal size.

For instance, in the above example, the function may return 4, 6, or 8 as explained above.

For the following array A consisting of N = 3 elements:

A[0] = 30
A[1] = 20
A[2] = 10
the function may return 0, 1 or 2, because all the ascending slices of this array have size 1.

Assume that:

* N is an integer within range [1..150,000]
* each element of A is an integer within the range [-2**31 .. 2**31 - 1]
**/
int maximal_slice(vector<int>& A){
    int max_slice_index = 0;
    int max_slice_length = 1;

    int current_slice_start = 0;

    for (int i = 1; i < A.size(); i++) {
        current_slice_start = A[i - 1] >= A[i] ? i : current_slice_start;

        if (i - current_slice_start + 1 > max_slice_length) {
            max_slice_index = current_slice_start;
            max_slice_length = i - current_slice_start + 1;
        }
    }

    return max_slice_index;
}