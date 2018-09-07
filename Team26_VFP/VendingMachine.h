#ifndef VENDING_H
#define VENDING_H

#define MAX_PRODUCT_COUNT

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class VendingMachine
{
public:
    // The name of the machine
    string name;

    // The amount of money currently in the machine
    double money;

	//unique identifier
	int machineID;

    // Returns how many products are in the machine
    int ProductCount();



    enum MachineType
    {
        FOUNTAIN,
        SNACK,
        BEVERAGE
    };

    struct Product
    {
        // Product name
        string name = "";

        // Product ID
        string id = "-1";

        // Product price
        double price = -1;

        // How much of this product is left in the machine
        int quantity = -1;

        // Running total of how many have been sold
        int amountSold = -1;

        // Displays item information
        void ShowInfo();
    };
private:

	// The type of the machine
	MachineType type;

	// The products in the machine
	Product* products[MAX_PRODUCT_COUNT];

public:

	// accesses name
	string getMachineName();

    // Sets name
    VendingMachine(string name);

    // Adds a new product to the machine if possible
    // Returns true if product was successfully added, returns false otherwise
    bool AddProduct(Product product);

    // Changes the price of a product with the given index
    // Returns true if the price change was successfull, returns false otherwise
    bool ChangePrice(int index, double price);

    // Displays the products offered
    void DisplaySelection();

    // Returns true if the product is available at the given index
    bool IsProductAvailable(int index);

    // Returns true if the product price is less than or equal to the amount of money in the machine
    bool CanAfford(int index);

	//returns Product at index value;
	Product GetProductAt(int index);

	bool fileIn()
	{
		bool fileGood;
		ifstream input;
		Product p;
		int mach;//had to create becayse could no acces machineID MUST BE DELETED
		string temp;//used to cast string to ints or doubles
		input.open("mData.txt"); //input stream
		if (input.good())//(vector, machinecounter)
		{
			while (!input.eof())
			{
				getline(input, temp);
				int stype = atoi(temp.c_str());
				getline(input, temp);
				getline(input, temp);
				money = atof(temp.c_str());
				getline(input, temp);
				machineID = atoi(temp.c_str());
				getline(input, p.id, ',');
				getline(input, p.name, ',');
				getline(input, temp, ',');
				p.price = atof(temp.c_str());
				getline(input, temp, ',');
				p.quantity = atoi(temp.c_str());
				getline(input, temp);
				p.amountSold = atof(temp.c_str());
			}
			input.close();
			fileGood = true;
		}
		else
		{
			input.close();
			cout << "\n\nFile Load Failed\n\n";			
			fileGood = false;
		}
		
		return fileGood;
	}

	bool fileOut()
	{

	}

    /* Virtuals */

    // Makes the purchase. Note: You must call IsProductAvailable and CanAfford before calling this function.
    virtual void MakePurchase() = 0;
};

#endif
