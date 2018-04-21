//
////Functions
//void menu();
//bool open_file(ifstream & fin);
//
////testing for bank_account functions
//int mainOld()
//{
//menu();
//return 0;
//}
//
//void menu()
//{
//bool flag = false;
//int menu_option;
//ifstream fin;
//ofstream fout;
//bank_account BA;
//
//
//while(!flag)
//{
//cout << "Please choose an option\n";
//cout << "1.Create a new account from keyboard\n"
//	<<"2.Create a new account from input file\n"
//	<<"3.Print account balance to monitor\n"
//	<<"4.Withdraw Money\n"
//	<<"5.Deposit money\n"
//	<<"6.Print account details to monitor\n"
//	<<"7.Print account details to file\n"
//	<<"8.Print account number\n"
//	<<"9.Exit\n";
//
//cin >> menu_option;
//cout << "\n";
//	if (menu_option==1)
//		bank_account::getinstance(BA);
//	else if (menu_option==2)
//	{
//		if(open_file(fin))
//			bank_account::getinstance(BA, fin);
//	}
//	else if (menu_option==3)
//	{
//		cout << "Current Balance: $" << BA.get_balance() << endl << endl;
//	}
//	else if (menu_option==4)
//	{
//		double withdraw_money;
//		cout << "How much money would you like to withdraw?: ";
//		cin >> withdraw_money;
//		BA.withdraw(withdraw_money);
//	}
//
//	else if (menu_option==5)
//	{
//	double deposit_money;
//	cout << "How much money would you like to deposit? : ";
//	cin >> deposit_money;
//	BA.deposit(deposit_money);
//	
//	}
//	else if (menu_option==6)
//	{
//	BA.print();
//	
//	}
//	else if (menu_option==7)
//	{
//		string output_file;
//		cout << "Please enter a name for the output file: ";
//		cin.sync();
//		getline(cin, output_file);
//		cout << endl << endl;
//		fout.open(output_file);
//		if(!fout)
//		{
//			cout << "Error! Could not open file\n\n";
//		}
//		if (fout)
//		{
//			BA.print(fout);
//		}
//	}
//	else if (menu_option==8)
//	{
//		cout << "Account number: " << BA.get_account_number() <<endl << endl;
//	}
//	else if (menu_option==9)
//	{
//		cout << "Thank you for using the program, have a nice day\n\n";
//		flag = true;
//	}
//
//}
//}
//
//bool open_file(ifstream & fin)
//{
//string input_file_name;
//
//cout << "Please enter the name of the input file: ";
//cin.sync();
//getline(cin, input_file_name);
//cout << endl << endl;
//fin.open(input_file_name);
//if (!fin)
//{
//	cout << "Error, could not open file\n\n";
//	return false;
//}
//return true;
//}
