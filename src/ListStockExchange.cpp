#include <list>
#include "StockExchange.cpp"
#include "Trade.cpp"

class ListStockExchange : public StockExchange{

private:
	std::list<Trade> trades;

public:
	void order(int ticket, int amount, int price, bool buy) {
		trades.push_back(Trade(ticket,amount,price,buy));
	}

	double dayBalance() {
		double balance = 0;
		for(auto tradesIterator = trades.begin(); tradesIterator != trades.end(); tradesIterator++)
			balance += tradesIterator->amount * tradesIterator->price * (tradesIterator->buy ? 1 : -1);
		return balance;
	}

	~ListStockExchange(){
		auto i = trades.begin();
		while (i != trades.end())
		{
		    trades.erase(i++);
		}
	}
};