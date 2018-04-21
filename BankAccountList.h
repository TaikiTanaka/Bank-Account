#pragma once
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "bank_account.h"

class BankAccountList{
private:
	int list_state;
	int num_elements;
	BankAccount LIST[MAX];
public:
		BankAccountList(); 
		const string toString();	
		bool findAccount(const string & actNum, int & i) const;
		void addAccount(const BankAccount & BA);
		static void getInstance(BankAccountList & BAL, istream & in);
		static void getInstance(BankAccountList & BAL);
		int getNumberOfElements();
		bool depositMoney(const string & actNum, double money);
		bool withDrawMoney(const string & actNum, double money);
		void sort(int flag);
		bool deleteAccount(const string & actNum);
		void makeEmpty();
		const string listDescription();
		void writeToNewInputFile(ostream & out);
		bool updateAccount();
		void printListAsReport();
		void print(ostream & out);
		void printStatistics(ostream & out);
		

		//Calculation functions
		double getMeanOfAllDeposits();
		double Standard_Deviation_Deposits();


		
		//Get functions
		bool isEmpty() const;
		bool isFull()const;
		int getListState();
		double getBalance(const string & actNum);
		static int getCapacity();
		const string getFirstName(const string & actNum);
		const string getLastName(const string & actNum);
		const string getFullName(const string & actNum);
		void getHighestBalanceAccount(BankAccount & BA)const;
		int getLengthOfLongestFirstName();
		int getLengthOfLongestLastName();
		bool getAccountAt(BankAccount & BA, unsigned int & index);
		double sumAllDeposits() const;
		void getSmallestBalanceAccount(BankAccount&BA)const;
		unsigned int numberOfDepositsAboveMean();
		unsigned int numberOfDepositsAtOrBelowMean();
		

		//Set functions
		void setLastName(const string & lname, const string & actNum);
		void setAccountAt(BankAccount & BA, unsigned int index);

		
};
#endif