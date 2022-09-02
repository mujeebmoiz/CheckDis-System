// CMGK (Test).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <ctime>
#include <string>
#include <iomanip>
#include <fstream>
#include<sstream>
#include <Windows.h>
#include <iostream>
#include <vector> 
#include <stdlib.h>
#pragma warning(disable : 6385)
#pragma warning(disable: 4996)
using namespace std;

string userName[] = { "macysadmin", "rfadmin", "afadmin" };
string userPass[] = { "password", "password1", "password2" };



const int ARRAYSIZE = 5;
int numattempts = 0;
string entuser = "";
string entpass = "";
string selcomp = "";
int i = 0;
bool isPassValid = false;
bool isUserValid = false;
int index = -1;
double finaltotal = 0.0;
string login();
void menu(string selcomp, int numshipdays);
void calcprice(string selcomp, int orderNum);
void Readout(int orderNum, double quant, double price, string mdnum, string item, double finalp);
void calcdays(int shipdays);
char moreFurniture = 0;
int main()
{
    system("color 1F");
    cout << "Welcome to CheckDis System by Checkmate Distribution!\n";

    selcomp = login();
    int numshipdays = 26;
    menu(selcomp,numshipdays);
    
    


    

}

/*******************************Login Function***********************************/
string login()
{

    fstream fout;
    fout.open("Invoice.txt", ios::out | ios::app);
    fout << "****************************************************************************************\n";
    fout << "CheckDis System Invoice: ";
    fout << "\n****************************************************************************************\n";

    string entuser = "";
    int numattempts = 0;
    bool isUserValid = true;
    int i = -1;
    string companyName[] = { "Macys", "Raymour & Flannigan", "Ashleys Furniture" };
    //Gets the Username and password of the company 
    while (!isPassValid && numattempts <= 3)
    {
        cout << "\nPlease enter Username: ";
        getline(cin, entuser);
        cout << "Please enter your Password: ";
        getline(cin, entpass);
        for (i = 0; i < ARRAYSIZE; i++)
        {
            if (entuser == userName[i] && entpass == userPass[i])
            {
                isPassValid = true;
                cout << "\nLogin Successful!\n";
                cout << "\nWelcome " << companyName[i] << " administrator!" << endl;
                cout << "-----------------------------------------------------";
                // IF it is correct it allows the user to enter the account 
                break;
            }
        }
        if (!isPassValid)
        {
            cout << "\nUsername or Password invalid, please try again!\n" << endl;
            //IF its false then after 3 tries the program cancels 
        }
        numattempts++;
        if (numattempts == 3 && !isPassValid) {
            cout << "\nNumber of attempts exceeded, program terminated!\n" << endl;
            exit(0);

        }
    }
    fout << "\nCLIENT: " << companyName[i] << endl; 
    string comp = companyName[i];
    return comp;
}
/****************************End of login Function*******************************/

/****************************START Menu Function*******************************/
void menu(string selcomp, int numshipdays) {
    fstream fin;
    vector<string> row;
    string line;
    string words[4];
    int i = 0;
    int count = 0;

    srand(time(NULL));
    int orderNum = rand() % 72474;


    //Inputing of the text files with the menu 
    if (selcomp == "Macys") {

        fin.open("Macys.txt", ios::in);
        cout << "\n   Model #\t Furniture Type \t Price/Unit ($)\n";
        cout << "-----------------------------------------------------" << endl;
        while (!fin.eof()) {
            row.clear();
            while (getline(fin, line)) {
                stringstream s(line);

                while (getline(s, words[i], ','))
                {
                    row.push_back(line);
                    i++;
                }


                for (int i = 0; i < 4; i++) {
                    cout << words[i] << "           ";
                }
                cout << endl;
                i = 0;
                s.clear();
            }
        }
        do {
            calcprice(selcomp, orderNum);
            cout << "\nWould you like to order more furniture? (y/n): ";
            
            
            cin >> moreFurniture;

        } while ((moreFurniture == 'y') || (moreFurniture == 'Y'));
        cout << "\n****************************************************************************************\n";
        cout << "THANK YOU FOR USING OUR SYSTEM!" << endl;
        cout << "****************************************************************************************\n";

        fstream fout;
        fout.open("Invoice.txt", ios::out | ios::app);
        fout << "GRANDTOTAL: $" << fixed << setprecision(2) << finaltotal << endl;
        calcdays(numshipdays);

    }
    else if (selcomp == "Raymour & Flannigan") {
        fin.open("RFfurniture.txt", ios::in);
        cout << "\n   Model #\t Furniture Type\t Price/Unit ($)\n";
        cout << "-----------------------------------------------------" << endl;
        while (!fin.eof()) {
            row.clear();
            while (getline(fin, line)) {
                stringstream s(line);

                while (getline(s, words[i], ','))
                {
                    row.push_back(line);
                    i++;
                }


                for (int i = 0; i < 4; i++) {
                    cout << words[i] << "           ";
                }
                cout << endl;
                i = 0;
                s.clear();
            }
        }
        do {
            calcprice(selcomp, orderNum);
            cout << "\nWould you like to order more furniture? (y/n): ";

            cin >> moreFurniture;

        } while ((moreFurniture == 'y') || (moreFurniture == 'Y'));
        
        cout << "\n****************************************************************************************\n";
        cout << "THANK YOU FOR USING OUR SYSTEM!" << endl;
        cout << "****************************************************************************************\n";

        fstream fout;
        fout.open("Invoice.txt", ios::out | ios::app);
        fout << "GRANDTOTAL: $" << fixed << setprecision(2) << finaltotal << endl;
        calcdays(numshipdays);

    }
    else if (selcomp == "Ashleys Furniture") {
        fin.open("Ashleys furniture.txt", ios::in);
        cout << "\n   Model #\t Furniture Type\t Price/Unit ($)\n";
        cout << "-----------------------------------------------------" << endl;
        while (!fin.eof()) {
            row.clear();
            while (getline(fin, line)) {
                stringstream s(line);

                while (getline(s, words[i], ','))
                {
                    row.push_back(line);
                    i++;
                }


                for (int i = 0; i < 4; i++) {
                    cout << words[i] << "           ";
                }
                cout << endl;
                i = 0;
                s.clear();
            }
        }
        do {
            calcprice(selcomp, orderNum);
            cout << "\nWould you like to order more furniture? (y/n): ";

            cin >> moreFurniture;

        } while ((moreFurniture == 'y') || (moreFurniture == 'Y'));
        cout << "\n****************************************************************************************\n";
        cout << "THANK YOU FOR USING OUR SYSTEM!" << endl;
        cout << "****************************************************************************************\n";

        fstream fout;
        fout.open("Invoice.txt", ios::out | ios::app);
        fout << "GRANDTOTAL: $" << fixed << setprecision(2) << finaltotal << endl;
        calcdays(numshipdays);

    }



}
/****************************End Menu Function*******************************/


/****************************Calc Function*******************************/

void calcprice(string selcomp, int orderNum) {

    // Calculates the price of the item x quantity
    fstream fin;
    vector<string> row;
    string line;
    string words[4];

    int i = 0;
    int mnum = 0;
    double quant = 1;
    int counter = 0;
    bool loginSuccess = false;

    cout << "\n Enter the Model Number: ";
    cin >> mnum;

    string selnumb = to_string(mnum);

    cout << "\n Enter the Desired Quantity: ";
    cin >> quant;


    



    if (selcomp == "Macys") {
        fin.open("Macys.txt", ios::in);

        while (!fin.eof()) {
            row.clear();
            while (getline(fin, line)) {
                stringstream s(line);

                while (getline(s, words[i], ','))
                {
                    row.push_back(line);
                    i++;
                }


                if (words[0] == selnumb) {

                    double price = stod(words[2]);
                    double finalp = price * quant;

                    cout << "-----------------------------------------------------" << endl;
                    cout << "The price is " << "$" << fixed << setprecision(2) << finalp << endl;
                    cout << "-----------------------------------------------------" << endl;
                    string mdnum = words[0];
                    string item = words[1];
                    Readout(orderNum, quant, price, mdnum, item, finalp);
                    return;
                }

                cout << endl;
                i = 0;
                s.clear();
            }
        }
        cout << "Model number doesn't exist! Please try again" << endl;
        calcprice("Macys", orderNum);
    }

    if (selcomp == "Raymour & Flannigan") {
        fin.open("RFfurniture.txt", ios::in);
        while (!fin.eof()) {
            row.clear();
            while (getline(fin, line)) {
                stringstream s(line);

                while (getline(s, words[i], ','))
                {
                    row.push_back(line);
                    i++;
                }

                if (words[0] == selnumb) {
                    double price = stod(words[2]);
                    double finalp = price * quant;

                    cout << "-----------------------------------------------------" << endl;
                    cout << "The price is " << "$" << fixed << setprecision(2) << finalp << endl;
                    cout << "-----------------------------------------------------" << endl;
                    string mdnum = words[0];
                    string item = words[1];
                    Readout(orderNum, quant, price, mdnum, item, finalp);
                    return;
                }
                cout << endl;
                i = 0;
                s.clear();
            }
        }
        cout << "Model number doesn't exist! Please try again" << endl;
        calcprice("Raymour & Flannigan", orderNum);
    }
    if (selcomp == "Ashleys Furniture") {
        fin.open("Ashleys furniture.txt", ios::in);
        while (!fin.eof()) {
            row.clear();
            while (getline(fin, line)) {
                stringstream s(line);

                while (getline(s, words[i], ','))
                {
                    row.push_back(line);
                    i++;
                }

                if (words[0] == selnumb) {
                    double price = stod(words[2]);
                    double finalp = price * quant;

                    cout << "-----------------------------------------------------" << endl;
                    cout << "The price is " << "$" << fixed << setprecision(2) << finalp << endl;
                    cout << "-----------------------------------------------------" << endl;
                    string mdnum = words[0];
                    string item = words[1];
                    Readout(orderNum, quant, price, mdnum, item, finalp);
                    return;
                }
                cout << endl;
                i = 0;
                s.clear();
            }
        }
        cout << "Model number doesn't exist! Please try again" << endl;
        calcprice("Ashleys Furniture", orderNum);
    }


}

void calcdays(int shipdays)
{
    //Get the current date/time based on current system
    time_t now = time(0);
    char* dt = ctime(&now);		// convert now to string form
    tm* date = gmtime(&now); 	// convert now to tm struct for UTC
    dt = asctime(date);
    fstream fout;
    fout.open("Invoice.txt", ios::out | ios::app);
    fout << "\nOrder Date: " << dt << endl;


    const time_t TODAY = 24 * 60 * 60;						//today in seconds
    time_t date_seconds = mktime(date) + (shipdays * TODAY);	//add days in seconds
    *date = *localtime(&date_seconds);						//update the date structure

    //Convert seconds to date and display the month, day and year only
    struct tm t = *localtime(&date_seconds);
    fout << "Your order requires " << shipdays << " days" << endl;
    fout << "The estimated arrival date is: " << t.tm_mon + 1 << "-" << t.tm_mday << "-" << t.tm_year + 1900 << endl;
    fout << endl;
    fout << endl;
    fout << endl;
}

void Readout(int orderNum, double quant, double price, string mdnum, string item, double finalp) {
    fstream fout;
    fout.open("Invoice.txt", ios::out | ios::app);

    finaltotal += finalp;
    
    fout << "\nORDER NUMBER : " << orderNum << endl;
    fout << "----------------------------------------------------------------------------------------\n";
    fout << "MODEL #\t" << "\tITEM OF FURNITURE\t" << "\tQUANITIY\t" << "PRICE\t" << "\tTOTAL\t" << endl;
    fout << mdnum << "\t" << "\t" << item << "\t" << "\t" << "\t" << quant << "\t" << "\t" << "\t"  << "$" << price << "\t" "\t" << "$" << fixed << setprecision(2) << finalp << endl;
    fout << "----------------------------------------------------------------------------------------\n";
 }