#include <iostream>
#include <vector>

using namespace std;

// We have a sequence of books: the i-th book has thickness books[i][0] and height books[i][1].

// We want to place these books in order onto bookcase shelves that have total width shelf_width.

// We choose some of the books to place on this shelf (such that the sum of their thickness is <= shelf_width), then build another level of shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down.  We repeat this process until there are no more books to place.

// Note again that at each step of the above process, the order of the books we place is the same order as the given sequence of books.  For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.

// Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

int minHeightShelves(vector<vector<int>> &books, int shelf_width)
{
    int n = books.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = 1;
        int current_height = 0;
        int current_width = 0;

        while (k <= i)
        {
            // grab the max height of all books up to i
            current_height = max(current_height, books[i - k][1]);
            current_width += books[i - k][0];
            // if adding the current book exceeds the width, start a new row!
            if (current_width > shelf_width)
            {
                break;
            }

            // grab the samllest possible combination of book placements of books from k=0,..,i
            // that maximizes the width, and MINIMIZES the height
            dp[i] = min(dp[i], dp[i - k] + current_height);
            k++;
        }
    }
    return dp[n];
}

int main()
{
    //[[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]
    vector<vector<int>> books;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(1);
    books.push_back(temp);
    temp.clear();

    temp.push_back(2);
    temp.push_back(3);
    books.push_back(temp);
    books.push_back(temp);
    temp.clear();

    temp.push_back(1);
    temp.push_back(1);
    books.push_back(temp);
    books.push_back(temp);
    books.push_back(temp);
    temp.clear();

    temp.push_back(1);
    temp.push_back(2);
    books.push_back(temp);

    if (minHeightShelves(books, 4) == 6)
    {
        printf("minimum height of 6! \n");
    }
    assert(minHeightShelves(books, 4));
    return 0;
}