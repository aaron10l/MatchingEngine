# Exchange Simulator in C++
A robust simulation of a financial exchange implemented in C++, leveraging the STL and Boost libraries. The orderbook structure is inspired by the quantcup winning submission by voyager, available [here](https://web.archive.org/web/20141222151051/https://dl.dropboxusercontent.com/u/3001534/engine.c).

## Usage

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/aaron10l/ExchangeSimulator.git
   cd ExchangeSimulator
   ```
   

## Notes & TODOs
- **Server and Client Implementation:**
    - [ ] add server and client files for a UDP server using sockets to enable communication with multiple traders.

- **QuantCup Integration:**
    - [ ] include QuantCup test files to ensure compatibility and benchmark performance against standard test cases.

- **API Enhancement:**
    - [ ] expand the API to include multiple order types including market order.

- **Documentation:**
    - [ ] explain why voyagers implementation is more efficient than WK Selph's and others.
    - [ ] expand comments and docs.

Feel free to suggest additional improvements. Your feedback and contributions are highly appreciated!