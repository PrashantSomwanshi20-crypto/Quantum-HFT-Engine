<div align="center">
  <img src="https://images.unsplash.com/photo-1640340434805-3221543bc815?q=80&w=1200&auto=format&fit=crop" alt="Quantum HFT 3D Banner" width="100%" style="border-radius: 10px;">
  
  <br><br>

  # 🚀 Quantum HFT Engine
  
  **An Ultra-Low Latency Order Matching Engine Built in Pure C++**
  
  ![C++](https://img.shields.io/badge/C++-17-00599C.svg?style=for-the-badge&logo=c%2B%2B)
  ![Data Structures](https://img.shields.io/badge/Data_Structures-STL-purple.svg?style=for-the-badge)
  ![Latency](https://img.shields.io/badge/Latency-Microseconds-ff69b4.svg?style=for-the-badge)
  ![Status](https://img.shields.io/badge/Status-Active-success.svg?style=for-the-badge)
</div>

<br>

## 🧠 System Architecture & Concept
This system simulates the core brain of top stock exchanges. It matches 'Buy' (Bids) and 'Sell' (Asks) orders with extreme computational efficiency. 

By utilizing self-sorting data structures, the engine ensures that the most aggressive buyers and cheapest sellers are matched instantly.

 <img width="1024" height="572" alt="image" src="https://github.com/user-attachments/assets/bd4c3633-2634-4792-b6f0-ba3be9314105" />
 

## ⚡ Core Engineering Features
* **O(log N) Order Sorting:** Utilizes C++ `std::map` to automatically sort Buy orders in descending order and Sell orders in ascending order.
* **Instant Trade Execution:** Cross-matches overlapping bids and asks the exact microsecond they arrive.
* **Microsecond Profiling:** Embedded `<chrono>` library logic to track and print the execution time of each functional block.
* **Live Market Depth:** Calculates and displays the current pending liquidity (Bids/Asks) after every execution cycle.

## 🚀 How to Run Locally

1. **Clone this repository:**
   ```bash
   git clone [https://github.com/PrashantSomwanshi20-crypto/Quantum-HFT-Engine.git](https://github.com/PrashantSomwanshi20-crypto/Quantum-HFT-Engine.git)<img width="1024" height="572" alt="watermarked_img_17767511864414334822" src="https://github.com/user-attachments/assets/32fc8331-e9e2-400c-a39e-a0beaa6d1dff" />
