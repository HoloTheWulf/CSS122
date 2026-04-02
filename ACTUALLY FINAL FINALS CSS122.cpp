#include <iostream>
#include <iomanip>
#include <string>
#include <cstring> 
#include <cctype>

using namespace std;
//int Drinks[6];

int selection = 0;
double upsize_Value = 30;
int main_memory[6][2] = {(0,0), (0,0), (0,0), (0,0),(0,0),(0,0)};

// Initialize struct for storing menu data
struct menu_Drinks
{
	string name;
	int size;
	double price;
};

int num_Drinks = 6;
int size_Drinks = 2;
void set_Drinks(menu_Drinks Drinks[6])
{
	Drinks[0] = menu_Drinks{.name = "Brewed Coffee", .size = 1, .price = 50};
	Drinks[1] = menu_Drinks{.name = "Spanish Latte", .size = 2, .price = 75}; 
	Drinks[2] = menu_Drinks{.name = "Matcha Latte", .size = 2, .price = 100};
	Drinks[3] = menu_Drinks{.name = "Iced Coffee", .size = 1, .price = 65};
	Drinks[4] = menu_Drinks{.name = "Capuccino", .size = 1, .price = 70};
	Drinks[5] = menu_Drinks{.name = "Espresso" , .size = 1, .price = 80};	
}

void print_Drinks(menu_Drinks Drinks[6])
{
	for (int i = 0; i < 6; i++)
	{
		cout << "(" << i+1 << ") ";
		cout << Drinks[i].name << endl;
		cout << "	" << "Regular: PHP" << Drinks[i].price << endl;
		if (Drinks[i].size != 1)
		{
			cout<< "	" <<"LARGE: PHP" << Drinks[i].price + upsize_Value << endl;
		}
		cout << endl;
	}
}

void welcome()
{	
	cout << "Welcome to Mapua Cafe!" << endl;
	cout << "What would you like to have today?" << endl;
	cout << "(1) Order Drinks" << endl;
	cout << "(2) View Cart" << endl;
	cout << "(3) Restart Order" << endl;
	cout << "(4) Checkout" << endl;
	cout << "(5) Exit" << endl;
	
}

//USED FOR ALL SELECTION IN THE PROGRAM
void select_menu(int &selection, int select_max)
{
	int choice_int;
	string choice_string;
	bool cont = true;
	selection = 0;
	while(cont)
	{
		try
		{
			cout << endl;
			cout << "INPUT OPTION NUMBER: ";
			cin >> choice_string;
			

			stoi(choice_string);
			
			choice_int = stoi(choice_string);
			if (to_string(choice_int) != choice_string)
			{
				throw 'a';
			}
			if((choice_int < 1) or (choice_int > select_max))
			{
				throw invalid_argument("ZERO");
			}
			
			cont = false;
			selection = choice_int;
			system("cls");
		}
		catch(char a )
		{
			cout << "NO, ADDING LETTERS AT THE END WILL NOT BREAK THE PROGRAM" << endl;
		}
		catch(const invalid_argument)
		{
			cout << "Error: SELECT ONLY FROM THE SPECIFIED OPTIONS" << endl;
		}
	}
}

void order_size(menu_Drinks Drinks[6])
{
	cout << "You have selected: " << Drinks[selection -1].name << endl;
	cout << "What size would you want?" << endl;
	cout << "(1) REGULAR	(2) LARGE" << endl;	
}

void order_quantity(menu_Drinks Drinks[6],int *ptr_temp)
{

	cout << "You have selected: " << Drinks[*(ptr_temp +1)].name << endl;
	cout << "How many would you want? (MAX 10 items)" << endl;
}

void cart(menu_Drinks Drinks[6], int num_Total, int &select_max, int &count)
{
	int total;
	
	cout << "YOUR CART CONTAINS: " << endl;
	count = 0;
	if (num_Total > 0)
	{
		for (int i=0; i < num_Drinks; i++)
		{
			for (int j=0; j < size_Drinks; j++)
			{
				if (main_memory[i][j] > 0)
				{
					count += 1;
					cout << "(" << count << ")" << Drinks[i].name << endl;
					if (j > 0)
					{
						cout << "	Size: LARGE";
						num_Total += main_memory[i][j];
	
					}
					else
					{
						cout << "	Size: REGULAR";
						num_Total += main_memory[i][j];
					}
					cout << "	Quantity: " << main_memory[i][j] << endl;
				}
			}
		}
		for (int i = 0; i < num_Drinks; i++)
		{
			for (int j=0; j < size_Drinks; j++)
			{
				if (main_memory[i][j] > 0)
				{
					count += 1;
	
					if (j > 0)
					{
						total += ((Drinks[i].price + upsize_Value) * main_memory[i][j]);
					}
					else
					{
						total += (Drinks[i].price * main_memory[i][j]);
					}
				}
			}
		}
		cout << endl;
		cout << "THE TOTAL BILL IS: " << total << endl;
	}
	select_max = count;
	if (num_Total == 0)
	{
		cout << "Your cart is empty... :(" << endl;
	}
	
	cout << endl;
	cout << endl;

}

void for_removal_index(int *ptr_temp, int remove_index)
{
	for(remove_index; remove_index > 0; remove_index --)
	{
		for (int i = 0; i < num_Drinks; i++)
		{
			for (int j = 0; j < size_Drinks; j++)
			{
				if(main_memory[i][j] > 0)
			{
					remove_index -= 1;
					*ptr_temp = i;
					*(ptr_temp +1) = j;
				}
			}
		}
	}
}

void checkout(menu_Drinks Drinks[6])
{
	string payment_string;
	float payment_double;
	bool cont = true;
	double total = 0;
	int count = 0;
	
	for (int i = 0; i < num_Drinks; i++)
	{
		for (int j=0; j < size_Drinks; j++)
		{
			if (main_memory[i][j] > 0)
			{
				count += 1;

				if (j > 0)
				{
					total += ((Drinks[i].price + upsize_Value) * main_memory[i][j]);
				}
				else
				{
					total += (Drinks[i].price * main_memory[i][j]);
				}
			}
		}
	}

	while(cont)
	{	
		try
		{
			cout << "The total bill is: " << total << endl;
			cout << "INPUT PAYMENT: ";
			cin >> payment_string;
	    	for (int i = 0; i < payment_string.length(); i++)
	    	{
	    		if (isalpha(payment_string[i]))
	    		{
	    			throw invalid_argument ("HAS LETTERS");
				}
			}

			payment_double = stof(payment_string);
	
	    	cout << fixed << setprecision(2) << "CHANGE: " << payment_double - total << endl;;
			if ((payment_double - total) < 0)
			{
				throw 'a';
			}
			cont = false;
		}
		catch(char a)
		{
			cout << "Error: Input at least enough to cover the payment" << endl;
		}
		catch(invalid_argument &e)
		{
			cout << "Error: Input a valid number" << endl;
		}
	}
}

int main()
{

	// Loads data for drinks
	menu_Drinks Drinks[6];
	set_Drinks(Drinks);
	
	// Variables relating to order data storage;
	int temp_memory[2] = {0, 0};
	int *ptr_temp = temp_memory;
	main_memory[num_Drinks][2] = {};

	
	int count;
	int num_Total;
	double payment;
	int remove_index;
	int remove_quantity;
	
	//LOOPING AND MENU SELECTION
	bool cont = true;
	int select_max = 0;
	//print_Drinks(Drinks);
	while(cont)
	{
		payment = 0;
		fill(begin(temp_memory), end(temp_memory), 0);
		
		welcome();
		select_max = 5;
		select_menu(selection, select_max);
		switch(selection)
		{
			case 1: // SELECT DRINKS
				//DISPLAYS DRINKS, TAKES DRINK ITEM
				select_max = num_Drinks;
				print_Drinks(Drinks);
				select_menu(selection, select_max);
				temp_memory[0] = selection -1;
				
				//DISPLAYS DRINKS, TAKES DRINK SIZE
				if (Drinks[selection -1].size > 1)
				{
					order_size(Drinks);
					select_max = size_Drinks;
					select_menu(selection, select_max);
					temp_memory[1] += (selection -1);
				}
				select_max = 10; // SURELY A REASONABLE ORDER NUMBER FOR ONE ORDER OF A DRINK ITEM >:3
				order_quantity(Drinks, temp_memory);
				select_menu(selection, select_max);
				main_memory[*ptr_temp][*(ptr_temp +1)] += selection;
				num_Total += selection;



				// ^^REMOVE THIS LATER
				break;
			case 2: // VIEW CART
				cart(Drinks, num_Total, select_max, count);
				cout << "(1) Back" << endl;
				select_max = 1;
				if (num_Total > 0)
				{
					cout << "(2) Remove Item" << endl;
					select_max = 2;
				}
				select_menu(selection, select_max);
				switch(selection)
				{
					case 1:
						break;
					case 2:
						cart(Drinks, num_Total, select_max, count);
						

						select_menu(selection, select_max);
						remove_index = selection;

						for_removal_index(temp_memory, remove_index);
						cout << "How many do you want to remove?" << endl;
						select_max = main_memory[*ptr_temp][*(ptr_temp+1)];

						select_menu(selection, select_max);
						remove_quantity = selection;
						main_memory[*ptr_temp][*(ptr_temp +1)] -= remove_quantity;

						num_Total -= remove_quantity;
						break;
				}
				
				break;
			case 3:// RESET CART
				for (int i=0; i < num_Drinks; i++)
				{
					for (int j=0; j < 2; j++)
					{
						main_memory[i][j] = 0;
					}
				}
				num_Total = 0;
				break;
			case 4:// CHECKOUT AND CHANGE
				cart(Drinks, num_Total, select_max, count);
				payment = 0;
				checkout(Drinks);
				cout << "Thank you, come again :)";
				exit(1);
				break;
			case 5:// EXIT
				cout << "Thank you for your patronage! :>";
				exit(1);
				break;
		}
	}
}