#include "BankAccountList.h"

int main()
{
	bool flag = false;
	int menu;
	BankAccountList BAL, BAL2;
	ifstream fin;

	while (!flag)
	{
		cout << "\n\n1. Add new account using keybord\n"
			<< "2. Add new account using an input file\n"
			<< "3. Update account (changes last name)\n"
			<< "4. Delete an account\n"
			<< "5. Write account list to an output file\n"
			<< "6. Print account list to monitor\n"
			<< "7. Withdraw money from an account\n"
			<< "8. Deposit money from an account\n"
			<< "9. Get account balance\n"
			<< "10. Search for account and print details to monitor\n"
			<< "11. Print list description to monitor\n"
			<< "12. Print list sorted according to account number\n"
			<< "13. Print list sorted according to last name\n"
			<< "14. Print list sorted according to balance\n"
			<< "15. Print statistics to monitor\n"
			<< "16. Print report in table form to a report file\n"
			<< "17. Print list to an output file readable as a new input file\n"
			<< "18. Exit\n\n";
		cin >> menu;

		if (menu == 1)
		{
			cout << endl << endl;
			BankAccountList::getInstance(BAL);
			cout << endl << endl;
		}

		else if (menu == 2)
		{
			string inputFileName;
			cin.sync();
			cout << "Enter the file path: ";
			getline(cin, inputFileName);
			fin.open("Text.txt");

			if (fin)
			{
				BankAccountList::getInstance(BAL, fin);
			}
			else
				cout << "\n\nCould not open file\n\n";
		}
		else if (menu == 3)
		{
			BAL.updateAccount();
		}
		else if (menu == 4)
		{
			string actNum;
			cout << "Please enter the account number: ";
			cin >> actNum;
			BAL.deleteAccount(actNum);
		}

		else if (menu == 5)
		{
			ofstream fout;
			string outputName;
			cin.sync();
			cout << "\n\nPlease enter the path of the output file: ";
			getline(cin, outputName);
			fout.open(outputName, ios::app);
			cout << endl << endl;
			BAL.print(fout);
		}

		else if (menu == 6)
		{
			cout << endl << endl;
			BAL.print(cout);
			cout << endl << endl;
		}
		//Withdraw 
		else if (menu == 7)
		{
			double money;
			string actNum;
			cout << "Please enter the account number: ";
			cin >> actNum;
			cout << "Please enter the amount you want to withdraw:$";
			cin >> money;
			BAL.withDrawMoney(actNum, money);
		}
		//Deposit
		else if (menu == 8)
		{
			double money;
			string actNum;
			cout << "Please enter the account number: ";
			cin >> actNum;
			cout << "Please enter the amount you want to deposit:$";
			cin >> money;
			BAL.depositMoney(actNum, money);
		}
		//Balance enquiry
		else if (menu == 9)
		{
			int i;
			string actNum;
			cout << "Please enter the account number: ";
			cin >> actNum;
			if (BAL.findAccount(actNum, i))
			{
				cout << "Current balance is: $" << BAL.getBalance(actNum) << endl << endl;
			}

		}
		//Search amount and show details on console only
		else if (menu == 10)
		{
			int index;
			unsigned int i;
			string actNum;
			BankAccount temp;
			cout << "Please enter the account number: ";
			cin >> actNum;
			if (BAL.findAccount(actNum, index))
			{
				i = index;
				if (BAL.getAccountAt(temp, i))
					temp.print();
			}
		}
		//Print current list description to console only
		else if (menu == 11)
		{
			cout << BAL.listDescription();
		}
		//Print list sorted by account number to console
		else if (menu == 12)
		{
			BAL.sort(1);
			cout << BAL.toString();
		}
		//Print list sorted by last name to console
		else if (menu == 13)
		{
			BAL.sort(2);
			cout << BAL.toString();
		}
		//Print list sorted by balance to console
		else if (menu == 14)
		{
			BAL.sort(3);
			cout << BAL.toString();
		}
		//Print statistics to console
		else if (menu == 15)
		{
			cout << endl << endl;
			BAL.printStatistics(cout);
		}
		//Print report in table form to a report file
		else if (menu == 16)
		{
			BAL.printListAsReport();
		}
		//Print list to an output file readable as new input file
		else if (menu == 17)
		{
			ofstream fout;
			string outputName;
			cin.sync();
			cout << "\n\nPlease enter the path of the output file: ";
			getline(cin, outputName);
			fout.open(outputName);
			BAL.writeToNewInputFile(fout);
		}
		//exits
		else if (menu == 18)
		{
			cout << "\n\nThank you for using the program\n\n";
			flag = true;
		}
	}
	return 0;
}
int testing()
{
	BankAccountList BAL,BAL2;
	BankAccount BA;
	BA = BankAccount("2742","Jess","Brennan",5400);
	string search,outputfilename;
	int index;

	//Opening input and output files
	ifstream in;
	ofstream out;
	in.open("text.txt");
	out.open("output.txt");
	BankAccountList::getInstance(BAL,in); 
	
	/*BAL.printListAsReport();*/

	BankAccount BA4;
	BAL.getSmallestBalanceAccount(BA4);
	BA4.print();


	/*BAL.print(out);
	BAL.print(cout);
	BAL.printListAsReport();*/


	/*cout << BAL.calculateMean() << endl << endl;

	cout << BAL.numberOfDepositsAboveMean() << endl << endl;

	cout << BAL.numberOfDepositsAtOrBelowMean() << endl << endl;

	cout << BAL.Standard_Deviation_Deposits() << endl << endl;
*/

	//BAL.toString();
	//BAL.sort(1);
	//cout << "Sorted according to account number \n\n";
	//BAL.toString();
	//cout << "Sorted according to last name \n\n";
	//BAL.sort(2);
	//BAL.toString();
	//cout << "Sorted according to balance \n\n";
	//BAL.sort(3);
	//BAL.toString();

	//cout << BAL.getBalance("1234");

	/*cout << BAL.getCapacity();*/

	//cout << BAL.getFirstName("1234");
	//cout << endl << endl;
	//cout << BAL.getFullName("1234");
	//cout << endl << endl;
	//cout << BAL.getLastName("1234");

	//cout <<endl<<endl<< BAL.listDescription();

	//cout << "The longest first name is " << BAL.getLengthOfLongestFirstName() <<endl;
	//cout << "The longest last name is " << BAL.getLengthOfLongestLastName() << endl;

	//BAL.makeEmpty();

	//cout <<endl<<endl<< BAL.listDescription();

	
	/*cout << BAL.toString()<<endl<<endl;
	BAL.setAccountAt(BA,2);
	cout << BAL.toString();*/

	//BAL.setLastName("Marsupico","1234");
	//BAL.toString();

	//unsigned int i=2;
	//bank_account BA2;
	//BAL.getAccountAt(BA2,i);
	//BA2.print();

	/*BAL.writeToNewInputFile(out);*/

	//testing get highest balance
	/*bank_account BA3;
	BAL.getHighestBalanceAccount(BA3);
	BA3.print();

	/*cout << BAL.toString() << endl << endl;
	BAL.deleteAccount("1234");
	BAL.print(out);
	BAL.print(cout);*/

	/*BAL.updateAccount();
	BAL.print(out);*/

	/*string outputfilename;
	ofstream fout;
	cout << "Enter output file name:";
	getline(cin, outputfilename);
	fout.open(outputfilename);
	BAL.writeToNewInputFile(fout);*/

	return 0;
}

