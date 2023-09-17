#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

class {
int ammo;
};

int main()
{
	int bills[5] = { 100,200,500,1000,5000 };
	int money[1000];

	std::cout << "Operation: ";
	std::string operation;
	std::cin >> operation;

	std::ifstream in("money.bin", std::ios::binary);
	if (in.is_open()) {
		in.read((char*)money,sizeof(money));
		in.close();
	}
	else {
		for (int i = 0; i < 1000; ++i)
		{
			money[i] = 0;
		}
	}

	if (operation == "+")
	{
		for (int i = 0; i < 1000; ++i)
		{
			if (money[i] == 0)
			{
				money[i] = bills[std::rand() % 5];
			}
		}
		std::ofstream out("money.bin", std::ios::binary);
		out.write((char*)money, sizeof(money));
		return 0;
	}

	else if (operation == "-")
	{
		std::cout << "Amount: ";
		int amount;
		std::cin >> amount;
		if ((amount % 100) != 0)
		{
			std::cout << "Invalid amount: " << amount << std::endl;
			return 1;
		}

		int amount_to_collect = amount;
		for (int i = 0; i >= 0; --i) {
			int bill = bills[i];
			for (int j = 0; j < 1000; ++j)
			{
				if (money[j] == bill) {
					if (amount_to_collect >= bill) {
						money[j] = 0;
						amount_to_collect -= bill;
						if (amount_to_collect == 0)
						{
							std::cout << "amount taken: " << amount << std::endl;
							std::ofstream out("money.bin", std::ios::binary);
							out.write((char*)money, sizeof(money));
							return 0;
						}
					}
				}
			}
		}
	};

	int i = 0;
	int summ = 0;
	while (i < 10)
	{
		summ += i;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
<<<<<<< HEAD
	std::cout << "summ of elements: " << summ << std::endl;
}
=======

	int bills[5] = { 100,200,500,1000,5000 };
	int money[1000];

	std::cout << "Operation: ";
	std::string operation;
	std::cin >> operation;
}
>>>>>>> 79deb6ecb5b2a38a978b0a5f14a82289a25fe664
