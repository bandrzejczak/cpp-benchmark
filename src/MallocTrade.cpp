typedef unsigned char byte;
#include <cstdlib>

class MallocTrade {
    private:
    	long offset = 0;
		long ticketOffset = offset += 0;
		long amountOffset = offset += 4;
		long priceOffset = offset += 4;
		long buyOffset = offset += 4;
		long objectSize = offset += 1;
		long objectOffset;
  		byte * buffer;

    public:
		MallocTrade(int size) {
			buffer = (byte *) malloc(size * objectSize);
		}

		~MallocTrade() {
			free(buffer);
		}

		long getObjectSize(){
			return objectSize;
		}

    	void setObjectOffset(long objectOffset) {
      		this->objectOffset = objectOffset;
    	}

	    void setTicket(int ticket) {
	    	for(int i=0; i<4; i++)
	    		buffer[objectOffset+ticketOffset+3-i] = (ticket >> (i*8));
	    }

	    long getPrice() {
	    	long price = 0;
	    	for(int i=0; i<4; i++)
	    		price += buffer[objectOffset+priceOffset+3-i] << (i*8);
	    	return price;
	    }

	    void setPrice(int price) {
	    	for(int i=0; i<4; i++)
	    		buffer[objectOffset+priceOffset+3-i] = (price >> (i*8));
	    }

	    long getAmount() {
	    	long amount = 0;
	    	for(int i=0; i<4; i++)
	    		amount += buffer[objectOffset+amountOffset+3-i] << (i*8);
	    	return amount;
	    }

	    void setAmount( int quantity) {
	    	for(int i=0; i<4; i++)
	    		buffer[objectOffset+amountOffset+3-i] = (quantity >> (i*8));
	    }

	    bool isBuy() {
	      return buffer[objectOffset+buyOffset] == 1;
	    }

	    void setBuy(bool buy) {
    		buffer[objectOffset+buyOffset] = buy ? 1 : 0;
	    }
  };