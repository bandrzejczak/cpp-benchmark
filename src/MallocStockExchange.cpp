#include <list>
#include "MallocTrade.cpp"

class MallocStockExchange{

private:
  int recordsCount = 0;
  MallocTrade flyweight;

public:

	void order(int ticket, int amount, int price, bool buy) {
		MallocTrade trade = get(recordsCount++);
    	trade.setTicket(ticket);
    	trade.setAmount(amount);
    	trade.setPrice(price);
    	trade.setBuy(buy);
	}

	double dayBalance() {
		double balance = 0;
		for (int i = 0; i < recordsCount; i++) {
			MallocTrade trade = get(i);
			balance += trade.getAmount() * trade.getPrice() * (trade.isBuy() ? 1 : -1);
		}
		return balance;
	}

private:
	MallocTrade get(int index) {
		int offset = index * flyweight.getObjectSize();
		flyweight.setObjectOffset(offset);
		return flyweight;
	}

};