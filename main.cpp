#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <chrono> // Header for time measurement

using namespace std;
using namespace std::chrono;

// Structure representing a single trading order
struct Order {
    int orderId;
    double price;
    int quantity;
    bool isBuy;
};

// Core class for the High-Frequency Trading Order Book
class OrderBook {
public:
    // Bids: Buy orders sorted in descending order (highest price gets priority)
    map<double, vector<Order>, greater<double>> bids;
    
    // Asks: Sell orders sorted in ascending order (lowest price gets priority)
    map<double, vector<Order>> asks;

    void addOrder(Order order) {
        // Start the high-resolution timer as soon as the order arrives
        auto start = high_resolution_clock::now();

        if (order.isBuy) {
            bids[order.price].push_back(order);
            cout << "[LOG] BUY Order Booked  -> ID: " << order.orderId << " | Price: " << order.price << " | Qty: " << order.quantity << "\n";
        } else {
            asks[order.price].push_back(order);
            cout << "[LOG] SELL Order Booked -> ID: " << order.orderId << " | Price: " << order.price << " | Qty: " << order.quantity << "\n";
        }
        
        // Check for potential matches immediately after adding the new order
        matchOrders();

        // Stop the timer and calculate the processing duration
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "[SPEED] Order processed in: " << duration.count() << " microseconds\n\n";
    }

    void matchOrders() {
        // Continue matching as long as there are both buy and sell orders available
        while (!bids.empty() && !asks.empty()) {
            auto bestBidIter = bids.begin();
            auto bestAskIter = asks.begin();

            double bestBidPrice = bestBidIter->first;
            double bestAskPrice = bestAskIter->first;

            // If the highest buy price is greater than or equal to the lowest sell price, a trade occurs
            if (bestBidPrice >= bestAskPrice) {
                Order& buyOrder = bestBidIter->second.front();
                Order& sellOrder = bestAskIter->second.front();

                // The traded quantity is the minimum of the buy and sell quantities
                int tradeQuantity = min(buyOrder.quantity, sellOrder.quantity);

                cout << "$$$ [TRADE EXECUTED] Buy ID: " << buyOrder.orderId 
                     << " | Sell ID: " << sellOrder.orderId 
                     << " | Trade Price: " << bestAskPrice 
                     << " | Trade Qty: " << tradeQuantity << " $$$\n";

                // Deduct the traded quantity from both orders
                buyOrder.quantity -= tradeQuantity;
                sellOrder.quantity -= tradeQuantity;

                // Remove the order from the book if its quantity becomes zero
                if (buyOrder.quantity == 0) {
                    bestBidIter->second.erase(bestBidIter->second.begin());
                    if (bestBidIter->second.empty()) bids.erase(bestBidIter);
                }
                
                if (sellOrder.quantity == 0) {
                    bestAskIter->second.erase(bestAskIter->second.begin());
                    if (bestAskIter->second.empty()) asks.erase(bestAskIter);
                }
            } else {
                // Break the loop if prices do not match
                break;
            }
        }
    }

    // Function to display the current market depth (pending orders)
    void printOrderBook() {
        cout << "========== MARKET DEPTH ==========\n";
        
        cout << "--- BIDS (Buy Orders) ---\n";
        for (auto& priceLevel : bids) {
            int totalQty = 0;
            for (auto& o : priceLevel.second) totalQty += o.quantity;
            cout << "Price: " << priceLevel.first << " | Total Qty: " << totalQty << "\n";
        }
        
        cout << "--- ASKS (Sell Orders) ---\n";
        for (auto& priceLevel : asks) {
            int totalQty = 0;
            for (auto& o : priceLevel.second) totalQty += o.quantity;
            cout << "Price: " << priceLevel.first << " | Total Qty: " << totalQty << "\n";
        }
        cout << "==================================\n\n";
    }
};

int main() {
    OrderBook engine;

    cout << "===========================================\n";
    cout << ">>> SYSTEM BOOT: HFT TRADING ENGINE STARTED <<<\n";
    cout << "===========================================\n\n";
    
    // Simulating the arrival of incoming market orders
    engine.addOrder({1, 105.50, 10, true});
    engine.addOrder({2, 104.00, 5, false});
    engine.addOrder({3, 106.00, 20, true});
    engine.addOrder({4, 106.50, 15, false});

    // Display the final state of the order book after processing all initial orders
    engine.printOrderBook();

    return 0;
}