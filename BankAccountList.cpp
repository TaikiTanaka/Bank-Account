#include "BankAccountList.h"

//Get instances
void BankAccountList::getInstance(BankAccountList & BAL, istream & in)
{
	int index = 0;

	while (in.peek() != EOF && index < MAX)
	{
		BankAccount temp;
		//Builds individual bankaccount into temp
		BankAccount::getinstance(temp, in);
		//Adds the temp employee into the Bank account list
		BAL.addAccount(temp);
		index++;
	}
}

void BankAccountList::getInstance(BankAccountList & BAL)
{
	string actNum, fname, lname;
	double bal;
	BankAccount BA;

	cout << "Please enter the account number: ";
	cin >> actNum;
	cout << "Please enter the first name: ";
	cin >> fname;
	cout << "Please enter the last name: ";
	cin >> lname;
	cout << "Please enter the balance: ";
	cin >> bal;

	BA = BankAccount(actNum, fname, lname, bal);
	BAL.addAccount(BA);

}

//Constructor

BankAccountList::BankAccountList()
{
	num_elements = 0;
	list_state = 1;//unsorted state
};

//Other

const string BankAccountList:: toString()
{
	ostringstream os;
	for (int i = 0; i < num_elements; i++)
	{
		os << LIST[i].toString();
	}
	return os.str();
}

bool BankAccountList::findAccount (const string & actNum,  int & i) const
{
	/*Takes the account number and an index i both as reference. Searches for the account number actNum. 
	If found then returns the index at which found (by reference) and returns true. 
	If not found then returns -1 as value of i and returns false. Does not alter the BankAccountList object.*/

	for (int index = 0; index < num_elements; index++)
	{
		if (LIST[index].get_account_number() == actNum)
			{
			i=index;
			return true;
			}
	}
	i = -1;
	cout << "Could not find account";
	return false;
};

void BankAccountList::addAccount(const BankAccount & BA)
{
	if (num_elements == MAX)
	{
	cout << "Array is full and only the first 30 entries have been processed" << endl;
	return;
	}

	LIST[num_elements] = BA;
	list_state = 1;
	num_elements++;
	return;
}

void BankAccountList::sort(int flag)
{
//flag 1 - Ascending order based on bank account 
//flag 2 - ascending order based on last name
//flag 3 - //ascending order based on balance
	for (int j = 0; j < num_elements; j++)
	{
			for (int i = 0; i < num_elements - j - 1 ; i++)
			{
				//ascending order based on bank account
				if (flag == 1)
				{
					list_state = 2;
					if (LIST[i].get_account_number() > LIST[i+1].get_account_number() )
					{
						BankAccount temp;
						temp = LIST[i];
						LIST[i] = LIST[i+1];
						LIST[i+1] = temp;
					}
				}
				//ascending order based on last name
				else if (flag == 2)
				{
					list_state = 3;
					if (LIST[i].get_lname() > LIST[i+1].get_lname() )
					{
						BankAccount temp;
						temp = LIST[i];
						LIST[i] = LIST[i+1];
						LIST[i+1] = temp;
					}
				}
				//ascending order based on balance
				else if (flag == 3)
				{
					list_state = 4;
					if (LIST[i].get_balance() > LIST[i+1].get_balance() )
					{
						BankAccount temp;
						temp = LIST[i];
						LIST[i] = LIST[i+1];
						LIST[i+1] = temp;
					}
				}
		}
	}
}

bool BankAccountList::deleteAccount(const string & actNum)
{
	int i;
	if(findAccount(actNum,i))
	{
		cout << "\nFound account, proceeding to delete it\n\n";
		LIST[i] = LIST[num_elements-1];
		if (list_state == 2)
			{
				sort(1);
			}
		else if (list_state==3)
			{
				sort(2);
			}

		else if (list_state==4)
			{
				sort(3);
			}
		--num_elements;
	}

	else 
		cout << "\nCould not find account, no accounts have been deleted\n\n";
	return false;
}

bool BankAccountList::isEmpty() const
{
	return num_elements == 0;
}

bool BankAccountList::isFull()const
{
	return num_elements == 30;
}

const string BankAccountList:: listDescription()
{
	ostringstream os;

	os <<"\nThe current number of elements in the list is " <<num_elements << endl;
	if (list_state==1)
	{
		os << "The list is unsorted" << endl;
	}
	else if (list_state==2)
	{
		os << "The list is sorted according to account number" << endl;
	}
	else if (list_state==3)
	{
		os << "The list is sorted according to last name" << endl;
	}
	else if (list_state==4)
	{
		os << "The list is sorted according to balance" << endl;
	}

	return os.str();
}

void BankAccountList:: makeEmpty()
{
	num_elements = 0;
	list_state=1;
}

void BankAccountList:: writeToNewInputFile(ostream & out)
{
	for (int i = 0; i < num_elements; i++)
	{
		out << LIST[i].get_account_number() << ' ' <<  LIST[i].get_lname() <<' '<< LIST[i].get_fname()<<' '<< LIST[i].get_balance()<<endl;
	}
}

bool BankAccountList:: updateAccount()
{
string search;
int i;
cout << "Please enter the account number: ";
cin >> search;
if (findAccount(search,i))
{
	string lname;
	cout << "Please enter the new last name: ";
	cin >> lname;
	cout << "\n\n";
	LIST[i].set_lname(lname);
	return true;
}
cout << "\n\nCould not find account";
return false;
}


//Print functions
void BankAccountList::printStatistics(ostream & out)
{
	out << left << fixed << showpoint << setprecision(2);
	BankAccount temp1, temp2;
	getHighestBalanceAccount(temp1);
	getSmallestBalanceAccount(temp2);


	out << "There are currently " << num_elements << " accounts" << endl
		<< "The sum of all deposits are $" << sumAllDeposits() << endl
		<< "The mean balance is $" << getMeanOfAllDeposits() << endl
		<< "The number of accounts above the mean balance is " << numberOfDepositsAboveMean() << endl
		<< "The number of accounts at or below the mean balance is " << numberOfDepositsAtOrBelowMean() << endl
		<< "The highest balance is $" << temp1.get_balance() << endl
		<< "The lowest balance is $" << temp2.get_balance() << endl
		<< "The standard deviation of the balances is $" << Standard_Deviation_Deposits() << endl << endl;

}

void BankAccountList::printListAsReport()
{
	ofstream out;
	string outputFileName;

	cin.sync();
	cout << "Please enter the path of the output file: ";
	getline(cin, outputFileName);
	out.open(outputFileName);
	if (!out)
	{
		cout << "Error! Couldn not open file \n\n";
		return;
	}

	out << left << fixed << showpoint << setprecision(2);

	out << "***************************************************" << endl
		<< "		Bank Accounts					  " << endl
		<< "***************************************************" << endl << endl

		<< setw(20) << "Name" << setw(20) << "Account Number" << setw(15) << "Balance ($)" << endl
		<< "---------------------------------------------------" << endl;

	for (int j = 1; j < 5; j++)
	{
		if (j == 2)
		{
			out << "---------------------------------------------------" << endl;
			out << endl << "Sorted based on Account Number\n\n";
			sort(1);
		}
		else if (j == 3)
		{
			out << "---------------------------------------------------" << endl;
			out << endl << "Sorted based on last name\n\n";
			sort(2);
		}

		else if (j == 4)
		{
			out << "---------------------------------------------------" << endl;
			out << endl << "Sorted based on balance\n\n";
			sort(3);
		}
		for (int i = 0; i < num_elements; i++)
		{
			out << setw(15) << LIST[i].get_full_name() << right << setw(15) << LIST[i].get_account_number() << setw(18) << LIST[i].get_balance() << endl << left;
		}
	}

	out << endl << endl;
	printStatistics(out);
	out << endl << endl;


}

void BankAccountList::print(ostream & out)
{
	out << toString();
}

//Get functions

int BankAccountList::getNumberOfElements()
{
	return num_elements;
}

int BankAccountList:: getListState()
{
	return list_state;
}

double BankAccountList::getBalance(const string & actNum)
{
	for (int i = 0; i < num_elements; i++)
	{
		if (LIST[i].get_account_number() == actNum)
		{
			return LIST[i].get_balance();
		}
	}

	throw "Could not find account\n\n";
}

int BankAccountList:: getCapacity()
{
	return MAX;
}

const string BankAccountList:: getFirstName(const string & actNum)
{
	for (int i = 0; i < num_elements; i++)
	{
		if (LIST[i].get_account_number() == actNum)
			return LIST[i].get_fname();
	}

	throw "Could not find account \n\n";
}

const string BankAccountList::getFullName(const string & actNum)
{
	for (int i = 0; i < num_elements; i++)
	{
		if (LIST[i].get_account_number() == actNum)
			return LIST[i].get_full_name();
	}

	throw "Could not find account \n\n";
}

const string BankAccountList::getLastName(const string & actNum)
{
	for (int i = 0; i < num_elements; i++)
	{
		if (LIST[i].get_account_number() == actNum)
			return LIST[i].get_lname();
	}

	throw "Could not find account \n\n";
}

void BankAccountList:: getHighestBalanceAccount(BankAccount & BA) const
{
	double temp;
	if (num_elements == 0)
	{
		cout << "List is empty\n\n";
		return;
	}

	temp = LIST[0].get_balance();
	for (int i = 1; i < num_elements; i++)
	{
		if (LIST[i].get_balance() > temp)
		{ 
			temp = LIST[i].get_balance();
			BA=LIST[i];
		}
	}
}

int BankAccountList:: getLengthOfLongestFirstName()
{
	size_t temp;
	if (num_elements == 0)
	{
		throw "List is empty\n\n";
	}

	temp = LIST[0].get_fname().length();
	for (int i = 1; i < num_elements; i++)
	{
		if (LIST[i].get_fname().length() > temp)
		{ 
			temp = LIST[i].get_fname().length();
		}
	}
	return temp;
}

int BankAccountList:: getLengthOfLongestLastName()
{
	size_t temp;
	if (num_elements == 0)
	{
		throw "List is empty\n\n";
	}

	temp = LIST[0].get_lname().length();
	for (int i = 1; i < num_elements; i++)
	{
		if (LIST[i].get_lname().length() > temp)
		{ 
			temp = LIST[i].get_lname().length();
		}
	}
	return temp;
}

bool BankAccountList:: getAccountAt(BankAccount & BA, unsigned int & index)
{
	if (index > (num_elements - 1) || index < 0)
	{
		throw ("No such index exists.");
	}

	BA = LIST[index];
	return true;

}

void BankAccountList:: getSmallestBalanceAccount(BankAccount&BA)const
{
	double temp;
	int position=0;
	if (num_elements == 0)
	{
		cout << "List is empty\n\n";
		return;
	}

	temp = LIST[0].get_balance();
	for (unsigned int index = 1; index < num_elements; index++)
	{
		if (temp> LIST[index].get_balance())
		{ 
			position = index;
			temp = LIST[index].get_balance();
		}

	}
	BA=LIST[position];
}

double BankAccountList::Standard_Deviation_Deposits()
{
	double temp, sum=0;
	double mean = getMeanOfAllDeposits();
	for (int i = 0; i < num_elements; i++)
	{
		temp = pow((LIST[i].get_balance() - mean), 2.0);
		sum += temp;
	}

	return pow((sum / num_elements), 0.5);
}

double BankAccountList::getMeanOfAllDeposits()
{
	double sum = 0;
	for (size_t i = 0; i < num_elements; i++)
	{
		sum += LIST[i].get_balance();
	}
	return sum / num_elements;
}

unsigned int BankAccountList::numberOfDepositsAboveMean()
{
	int numberOfDeposits = 0;
	int mean = getMeanOfAllDeposits();
	for (int i = 0; i < num_elements; i++)
	{
		if (LIST[i].get_balance()>mean)
		{
			numberOfDeposits++;
		}
	}

	return numberOfDeposits;

}

unsigned int BankAccountList::numberOfDepositsAtOrBelowMean()
{
	int numberOfDeposits = 0;
	int mean = getMeanOfAllDeposits();
	for (int i = 0; i < num_elements; i++)
	{
		if (LIST[i].get_balance() <= mean)
		{
			numberOfDeposits++;
		}
	}

	return numberOfDeposits;

}

//Set functions

void BankAccountList:: setLastName(const string & lname, const string & actNum)
{
	int i;
	bool found = findAccount(actNum, i);
	if (found)
	{
		LIST[i].set_lname(lname);
	}

	if (list_state==2)
	{
		list_state=1;
	}

}

void BankAccountList:: setAccountAt(BankAccount & BA, unsigned int index)
{
	if (index >= num_elements)
	{
		cout << "Index is out of range\n\n";
		return;
	}

	list_state = 1;
	LIST[index] = BA;
}

double BankAccountList:: sumAllDeposits() const
{
	double total=0;
	for (int i = 0; i < num_elements; i++)
	{
		total+=LIST[i].get_balance();
	}
	return total;

}

bool BankAccountList::depositMoney(const string & actNum, double money)
{
	for (int i = 0; i < num_elements; i++)
	{
		if (actNum == LIST[i].get_account_number())
		{
			LIST[i].deposit(money);
			list_state = 1;
			return true;
		}
	}
	cout << "\n\nCould not find account\n\n";
	return false;
}

bool BankAccountList::withDrawMoney(const string & actNum, double money)
{
	for (int i = 0; i < num_elements; i++)
	{
		if (actNum == LIST[i].get_account_number())
		{
			LIST[i].withdraw(money);
			list_state = 1;
			return true;
		}
	}
	cout << "Could not find account \n\n";
	return false;
}