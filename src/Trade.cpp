class Trade{
	public:
		int ticket;
		int amount;
		int price;
		bool buy;

		Trade(int t, int a, int p, bool b)
			: ticket(t), amount(a), price(p), buy(b)
			{}
};