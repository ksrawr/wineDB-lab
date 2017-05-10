// wine.h

#ifndef WINE_H
#define WINE_H

class Wine
{
	public:
		Wine();
		Wine(string name, int vintage, int score, double price, string type);
		void setInfo(string name, int vintage, int score, double price, string type);
		void setPrice(double price);
		string getName() const;
		int getPrice() const;
		void printInfo();
	
	private:
		string name;
		int vintage;
		int score;
		double price;
		string type;
};

#endif
