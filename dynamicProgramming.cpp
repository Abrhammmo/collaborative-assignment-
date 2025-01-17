#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//  Data Handling
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
// Prediction Algorithm 
class StockPredictor {
public:
    static double predictStockPrice(const vector<double>& stockPrices, int windowSize) {
        int n = stockPrices.size();
        if (n < windowSize) {
            cerr << "Error: Not enough data points to make a prediction." << endl;
            return -1;
        }

        vector<double> dp(n, 0.0); // DP table to store computed moving averages
        double weightSum = 0.0;
        for (int i = 1; i <= windowSize; i++) {
            weightSum += i; // Sum of weights for normalization
        }

        double weightedSum = 0.0;
        for (int i = 0; i < windowSize; i++) {
            weightedSum += stockPrices[n - windowSize + i] * (i + 1);
        }
        return weightedSum / weightSum;
    }
};
class UserInterface {
public:
    static int getWindowSize(int dataSize) {
        int windowSize;
        cout << "Enter window size for prediction: ";
        cin >> windowSize;
        
        if (windowSize <= 0 || windowSize > dataSize) {
            cerr << "Error: Invalid window size." << endl;
            return -1;
        }
        return windowSize;
    }
};
class Application {
public:
    static void run() {
        vector<double> stockPrices = DataHandler::inputStockPrices();
        if (stockPrices.empty()) {
            cerr << "No stock price data available." << endl;
            return;
        }
        
        int windowSize = UserInterface::getWindowSize(stockPrices.size());
        if (windowSize == -1) return;

        double predictedPrice = StockPredictor::predictStockPrice(stockPrices, windowSize);
        if (predictedPrice != -1) {
            cout << "Predicted next stock price: $" << fixed << setprecision(2) << predictedPrice << endl;
        } else {
            cout << "Prediction failed due to insufficient data." << endl;
        }
    }
};
int main() {
    Application::run();
    return 0;
}
