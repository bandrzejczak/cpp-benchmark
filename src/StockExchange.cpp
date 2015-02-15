#pragma once

class StockExchange{
	public:
		virtual void order(int ticket, int amount, int price, bool buy) = 0;
		virtual double dayBalance() = 0;
};