//Filename: stockSpanBF.cpp
//Author: Daniel Kruze
//Create Date: 09/23/21
//Compile Date: 09/27/21

#include <cstdlib> // srand, rand
#include <iostream> // cin, cout
#include <vector> // vector, vector operations

using namespace std; // namespace for library functions

int n; // integer n for user input
vector<int> prices; // vector for holding prices
vector<int> span; // vector that represents the span

/*
* This function populates the vector for prices with n random numbers
* The numbers are seeded by the user input integer, meaning each different n has its own, fixed span of pseudo-random values
*   Expected input: integer n
*   Expected output: vector "prices" of size n, with random values from seed n
*/
void setPrices() {
    int stockPrice; // integer representing a price
    srand((n * 10) % 13); // seed the rng
    for (int i = 0; i < n; i++) { // for n elements
        stockPrice = (rand() % 10) + 1; // the price for a given day is a random number mod 10
        prices.push_back(stockPrice); // push that price into the price vector
    }
}

/*
* This function calculates the span for each price, and places it into the vector for span
* These spans are calculated by iterating through each price, then for each price iterating through values before it
* Every value before the price that is lower than that price increases its span by 1, but the span stops increasing once a value that is higher than the price is reached
* The default span for a value with nothing smaller or equal directly before it is 1
*   Expected input: vector of prices
*   Expected output: vector "span" of size n, with elements of value [1, n]
*/
void findSpan() {
    int spanElement = 1; // initial span size
    for (int i = 0; i <= n; i++) { // for every price
        for (int j = i - 1; j >= 0; j--) { // for every price at an index lower than the price evaluated by the previous for loop
            if (prices[j] <= prices[i]) { // if the price from the past is less than or equal to "today's" price
                spanElement++; // add 1 to span
            }
            else { // if the past price is greater than today's price
                break; // stop increasing span
            }
        }
        span.push_back(spanElement); // push span to "span" vector
        spanElement = 1; // reset span to initial value for "tomorrow's" span calculation
    }
}

int main() {
    bool sentryMain = true; // sentry for the following while loop
    while (sentryMain) { // sentry = true
        cout << "Please enter an integer value greater than 2:\n>> "; // 2 and below represents trivial cases for this problem
        cin >> n; // int n = user input
        if (cin.fail()){ // if the user enters a non-integer
            cin.clear(); // clear the error flag that cin throws
            cin.ignore(100000, '\n'); // ignore up to 100,000 entered characters (technically, an input of 100,001 characters could break this program)
            cout << "Invalid input!" << endl; // warn the user their input is invalid, let them try again
        }
        else if (!cin.fail()) { // if the user enters an integer
            if (n <= 2) { // if the user enters any integer lower than 3
                cout << "Invalid Input!" << endl; // warn the user their input is invalid, let them try again
            }
            else { // if the user enters a valid integer
                setPrices(); // populate the prices vector with random values
                findSpan(); // calculate span members and populate the span vector with them
                cout << "Prices for " << n << " days:" << endl; // label the prices
                for (int i = 0; i < (n - 1); i++) { // this for loop prints out all but the latest of the prices in daily order, delineated by commas
                    cout << prices[i] << ", "; // delineator
                }
                cout << prices[n-1] << endl; // print the most recent price
                cout << "Span for " << n << " days:" << endl; // label the span
                for (int i = 0; i < (n - 1); i++) { // this for loop prints out all but the latest of the span values in daily order, delineated by commas
                    cout << span[i] << ", "; // delineator
                }
                cout << span[n-1] << endl; // print the span of the most recent price
                sentryMain = false; // end the loop
            }
        }
    }
    return 0;
}