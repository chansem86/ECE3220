
#include <iostream>
#include <cstring>

class Stock{
	private:
		char company[30];
		int shares;
		double share_val;
		double total_val;
		void set_tot(){total_val = shares * share_val;}
		void acquire(const char * comp, int n, double price){
			std::strncpy(company, comp, 29);
			company[29] = '\0';

			if(n < 0){
				std::cerr << "Number of shares can't be negative; "
						  << company << " shares set to 0.\n";
				shares = 0;
			}
			else{
				shares = n;
				std::cout << "\nUpdated shares." << std::endl;
			}
			share_val = price;
			set_tot();
		}
		void acquire(const char * comp){
			std::strncpy(company, comp, 29);
			company[29] = '\0';
			shares = 0;
			std::cout << "\nUpdated shares." << std::endl;
			share_val = 0;
			set_tot();
		}

	public:
		void buy(int num, double price);
		void sell(int num, double price);
		void update(double price);
		void display();
		Stock(const char*, int, double);
		Stock(const char*);
};

void Stock::buy(int num, double price){
	if(num < 0){
		std::cerr << "\nNumber of shares can't be negative. No shares bought; ";
	}
	else{
		shares += num;
		share_val=price;
		std::cout << "\n" << shares << " shares now owned at the new value of " << share_val << std::endl;
	}
	set_tot();
}

void Stock::sell(int num, double price){
	if(num < 0){
		std::cerr << "\nNumber of shares can't be negative. No shares sold; ";
	}
	else{
		shares -= num;
		share_val=price;
		std::cout << "\n" << shares << " shares now owned at the new value of " << share_val << std::endl;
	}
	set_tot();
}

void Stock::update(double price){
	if(price<0){
		std::cerr << "\nPrice cannot be negative. Price set to 0.\n";
		share_val=0;
	}
	else{
		share_val=price;
		std::cout << "\nPrice set to " << share_val << std::endl;
	}
	set_tot();
}

void Stock::display(){
	std::cout << "\nCompany Name: " << company << std::endl;
	std::cout << "Shares Owned: " << shares << std::endl;
	std::cout << "Share Value: " << share_val << std::endl;
	std::cout << "Total Value: " << total_val << std::endl;
}

Stock::Stock(const char* co, int n, double pr){
	acquire(co, n, pr);
}

Stock::Stock(const char* co){
	acquire(co);
}

int main(){

	Stock stock1("Nanosmart");
	stock1.display();
	stock1.buy(20, 15.00);
	stock1.display();
	stock1.sell(5, 10.0);
	stock1.display();
	stock1.update(5.0);
	stock1.display();

	Stock stock2("Amazon", 30, 100);
	stock2.display();
	stock2.buy(15, 70.00);
	stock2.display();
	stock2.sell(20, 95.0);
	stock2.display();
	stock2.update(125.0);
	stock2.display();

	return 0;
}
