#include <list>
#include "StockExchange.cpp"
#include "ByteArrayTrade.cpp"

class ByteArrayStockExchange : public StockExchange{

private:
  int recordsCount = 0;
  ByteArrayTrade flyweight;

public:
	void order(int ticket, int amount, int price, bool buy) {
		ByteArrayTrade trade = get(recordsCount++);
    	trade.setTicket(ticket);
    	trade.setAmount(amount);
    	trade.setPrice(price);
    	trade.setBuy(buy);
	}

	double dayBalance() {
		double balance = 0;
		for (int i = 0; i < recordsCount; i++) {
			ByteArrayTrade trade = get(i);
			balance += trade.getAmount() * trade.getPrice() * (trade.isBuy() ? 1 : -1);
		}
		return balance;
	}

private:
	ByteArrayTrade get(int index) {
		int offset = index * flyweight.getObjectSize();
		flyweight.setObjectOffset(offset);
		return flyweight;
	}

};