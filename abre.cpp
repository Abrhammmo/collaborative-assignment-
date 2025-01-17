#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// === Section 1: Data Handling (Assigned to Member 1) ===
class DataHandler {
public:
    static vector<double> inputStockPrices() {
        int numPrices;
        vector<double> stockPrices;
        cout << "Enter the number of stock prices: ";
        cin >> numPrices;

        if (numPrices <= 0) {
            cerr << "Error: Number of stock prices must be greater than 0." << endl;
            return stockPrices;
        }

        cout << "Enter " << numPrices << " stock prices: ";
        for (int i = 0; i < numPrices; i++) {
            double price;
            cin >> price;
            stockPrices.push_back(price);
        }
        return stockPrices;
    }
};
