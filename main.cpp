#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

// A debug flag used to toggle debugging mode
#define DEBUG true

/* The maximum number of accounts
 * If you increase this number, the array of classes is increased
 */
#define MAX_ACCT 20

using namespace std;

/* Used to simplify the atoi call
 */
int stringToInt(string data) {
    const char *c = data.c_str();
    return atoi(c);
}

/* Used to simplify the atof call
 */
float stringToFloat(string data) {
   const char *c = data.c_str();
   return atof(c);
}

class Customer {
    private:
        /* Struct for birth date, includes month, day, and year
         * has clear, convert, and isFull functions
         * variable is called: date
         */
        struct Birth_date {
            int month;
            int day;
            int year;
            
            // Inate function used to test if each variable in the struct have been set
            bool isFull() {
                if ((month >= 0) && (day >= 0) && (year >= 0))
                    return true;
                else {
                    return false;
                }   
            }
    
            //reset the struct values
            void clear() {
                month = -1;
                day = -1;
                year = -1;
            }
    
            // rip the integers from the string data
            void convertBirthDate(string data) {
                string temp;
                char c;
                int count = 0;
                int yearAt = 0;
                for (unsigned int i = 0; i < data.length(); i++) {
                    c = data.at(i);
                    if (c == ' ') {
                        switch (count) {
                        case 0:
                            month = stringToInt(temp);
                            break;
                        case 1:
                            day = stringToInt(temp);
                            yearAt = i;
                            break;
                        default:
                            cout << "Error in Birth_date format" << endl;
                            break;
                        }
                        temp.clear();
                        count++;
                    } else {
                        temp += c;
                    }
                }
                year = stringToInt(data.substr(yearAt, data.length() -  yearAt));
            }
        } date;
        /* Struct for name, includes first, middle, and last
         * has clear, convert, and isFull functions
         * variable is called: name
         */
        struct Name {
            string First_name;
            string Middle_name;
            string Last_name;
    
            // Inate function to determine if all of the values inside this struct have been set
            bool isFull() {
                if ((First_name.length() > 0) && (Middle_name.length() > 0)
                    && (Last_name.length() > 0))
                    return true;
                else
                    return false;
            }
    
            // Reset the struct values
            void clear() {
                First_name.clear();
                Middle_name.clear();
                Last_name.clear();
            }
    
            // Used to extract the authors first, middle, and last name
            void convertName(string data) {
                string temp;
                char c;
                int count = 0;
                for (unsigned int i = 0; i < data.length(); i++) {
                    if ((c = data.at(i)) == ' ') {
                        switch (count) {
                        case 0:
                            First_name = temp;
                            break;
                        case 1:
                            Middle_name = temp;
                            break;
                        default:
                            cout << "Error in Author name format" << endl;
                        }
                        count++;
                        temp.clear();
                    }
                    else {
                        temp += c;
                    }
                }
                Last_name = temp;
            }
        } name;
        float Balance_saving;
        float Balance_checking;

    public:        
        void clear() {
            name.clear();
            date.clear();
            Balance_checking = -1;
            Balance_saving = -1;            
        }
        
        // Function inside of the class to test if all the
        // variables have been set, default values are negative and .clear()
        bool isFull(){
            if (name.isFull() && date.isFull() && Balance_checking >= 0 
                && Balance_saving >= 0) {
                    if (DEBUG)
                        cout << "Is Full is true" << endl;
                    return true;
            } else {
                if (DEBUG) {
                    cout << "Name: " << name.isFull() << " Date: " << date.isFull() << endl;
                    cout << "Checking: " << fixed << Balance_checking << " Savings: " << fixed << Balance_saving << endl;
                }
                return false;
            }
        }
        
        /*  Withdraws <amount> with <type>
            type: 0 is savings, 1 is checking
        */
        void withdraw(float amount, int account_type){
            if (amount > 1000000)
                cout << "!-- WARNING --!" << endl << "  AMOUNT TOO LARGE  " << endl;
            else {
                switch (account_type){
                    case 0:
                        Balance_saving -= amount;
                        break;
                    case 1:
                        Balance_checking -= amount;
                        break;
                    default:
                        if (DEBUG)
                            cout << "Wrong account type" << endl;
                        break;
                }
            }
        }
        
        /*  Deposits <amount> with <type>
            type: 0 is savings, 1 is checking
        */
        void deposit(float amount, int account_type){
            if (DEBUG)
                cout << "Deposits: " << fixed << setprecision(2) << amount << endl;
            if (amount > 1000000)
                cout << "!-- WARNING --!" << endl << "  AMOUNT TOO LARGE  " << endl;
            else {
                switch (account_type){
                    case 0:
                        Balance_saving += amount;
                        break;
                    case 1:
                        Balance_checking += amount;
                        break;
                    default:
                        if (DEBUG)
                            cout << "Wrong account type" << endl;
                        break;
                }
            }
        }
        
        /*  Displays <type> to the user
            type: 0 is savings, 1 is checking
        */
        void check_balance(int account_type){
            switch (account_type){
                case 0:
                    cout << "Savings Balance is: $" << fixed << setprecision(2) << Balance_saving << endl;
                    break;
                case 1:
                    cout << "Checking Balance is: $" << fixed << setprecision(2) << Balance_checking << endl;
                    break;
                default:
                    if (DEBUG)
                        cout << "Wrong account type" << endl;
                    break;
            }
        }
        
        // Reads private first name
        string readFirstName() {
            return name.First_name;
        }
        
        // Reads private last name
        string readLastName() {
            return name.Last_name;
        }
        
        // Saves data to file
        void saveToFile(ofstream& out_file){
            out_file << date.month << " " << date.day << " " << date.year << endl;
            if (DEBUG)
                cout << date.month << " " << date.day << " " << date.year << endl;
            out_file << name.First_name << " " << name.Middle_name << " " << name.Last_name << endl;
            out_file << fixed << setprecision(2) << Balance_saving << endl;
            out_file << fixed << setprecision(2) << Balance_checking << endl;
        }
        
        /* Stores data in the format of specification
            default notifies the user that there was an error
         */
        void storeData(string data, int type){
            switch (type){
                case 0:
                    date.convertBirthDate(data);
                    break;
                case 1:
                    name.convertName(data);
                    break;
                case 2:
                    Balance_saving = stringToFloat(data);
                    break;
                case 3:
                    Balance_checking = stringToFloat(data);
                    break;
                default:
                    cout << "Error in Account Structure" << endl;
            }
        }
        
        // Constructor class for copying one class into another
        Customer (Customer *customer){
            date.month = customer->date.month;
            date.day = customer->date.day;
            date.year = customer->date.year;
            name.First_name = customer->name.First_name;
            name.Middle_name = customer->name.Middle_name;
            name.Last_name = customer->name.Last_name;
            Balance_saving = customer->Balance_saving;
            Balance_checking = customer->Balance_checking;
        }
        
        // Default constructor class used to initialize the temp class
        Customer(){
            clear();
            if (DEBUG) {
                cout << "Default Constructor was used." << endl;
            }
        }
};

/* Prompts user for account to modify
 * default returns error value_comp
 */
int checkingOrSaving(){ 
    string line;
    char c;
    cout << "Checking \'0\', savings \'1\', or escape \'2\'" << endl;
    cin >> line;
    c = line.at(0);
    switch(c){
        case '0':
        return 0;
        case '1':
        return 1;
        case '2':
        return 2;
        default:
        return -1;
    }
}

/* Prompts user to Enter the first name
 * if Frst name is unique, returns its position
 * if First name has duplicate, prompts for Last name
 * returns Last name position regardless of number of duplicates
 */
int searchUser(Customer *accounts[], int numUsers){
    string line;
    int numHits = 0;
    int i = 0;
    int position;
    cout << "Enter the User's First Name" << endl;
    cin >> line;
    if (DEBUG) {
        cout << "Entered Name" << line << endl;
        cout << "MAX account" << numUsers << endl;
        cout << "Garbage i " << i << endl;
    }
    
    for (i = 0; i < numUsers; i++){
        if (accounts[i]->readFirstName() == line){
            position = i;
            numHits++;
        }
    }
    
    if (DEBUG){
        cout << "Num Hits: " << numHits << endl;
    }
    
    if (numHits > 0) {
        if (numHits > 1){
            cout << "Enter the User's Last Name" << endl;
            cin >> line;
            for (i = 0; i < numUsers; i++){
                if (accounts[i]->readLastName() == line){
                    return i;
                }
            }
        } else {
            if (DEBUG)
                cout << "Position: " << position << endl;
            return position;
        }
    } else {
        cout << "No such user with that first name" << endl;
        return -1;
    }
}

/* After prompting the user if they would like to update the searched account,
 * The user enters data for the account.
 * Options include: deposit checking
 *                  deposit savings
 *                  withdraw checking
 *                  withdraw savings
 */
void updateAccount(Customer *customer){
    string line;
    char c;
    int i;
    customer->check_balance(0);
    customer->check_balance(1);
    cout << "Would you like to deposit  \'0\'," << endl;
    cout << "                  withdraw \'1\'," << endl;
    cout << "               or continue \'2\'?" << endl; 
    cin >> line;
    c = line.at(0);
    switch(c) {
        case '0':
            i = -1;
            if ((i = checkingOrSaving()) == -1 || i == 2) break;
            else if(i == 0){
                cout << "Amount: $";
                float amount;
                cin >> amount;
                customer->deposit(amount, 1);
                break;
            } else if(i == 1){
                cout << "Amount: $";
                float amount;
                cin >> amount;
                customer->deposit(amount, 0);
                break;
            } else break;
        case '1':
            i = -1;
            if ((i = checkingOrSaving()) == -1 || i == 2) break;
            else if(i == 0){
                cout << "Amount: $";
                float amount;
                cin >> amount;
                customer->withdraw(amount, 1);
                break;
            } else if(i == 1){
                cout << "Amount: $";
                float amount;
                cin >> amount;
                customer->withdraw(amount, 0);
                break;
            } else break;
        default:
                break;
    }
}

int main() {
    ifstream in_file;
    Customer *temp = new Customer();
    Customer *accounts[MAX_ACCT];
    temp->clear();
    // Opening the file to read the account data from
    in_file.open("account.dat");
    string line;
    int accountNum = 0;
    int count = 0;
    do {
        line.clear();
        getline(in_file, line);
        if (DEBUG)
            cout << line << endl;
        temp->storeData(line, count);
        count++;
        if (count == 4&&temp->isFull()){
            accounts[accountNum] = new Customer(temp);
            temp->clear();
            count = 0;
            accountNum++;
        }
    } while (line.length() > 0);
    in_file.close();
    // File has been read, data is now stored in RAM
    
    if (DEBUG) {
        cout << "Number of accounts" << accountNum << endl;
    }
    
    // Prompts user to edit account via name (withdraw/deposit)
    while (true) {
        cout << "Would you like to edit an account? (y/n)" << endl;
        line.clear();
        cin.clear();
        fflush(stdin);
        cin >> line;
        if (line.length() == 0){
            line.clear();
            cin >> line;
        }
        
        char c = line.at(0);
        if (c == 'y' | c == 'Y'){
            int user = searchUser(accounts, accountNum);
            if (DEBUG)
                    cout << "User position: " << user << endl;
                
            if (user == -1){
                cout << "Would you like to create a user with that name? (y/n)" << endl;
                cin >> line;
                c = line.at(0);
                if (c == 'y' | c == 'Y') break;
                else continue;
            } else {
                updateAccount(accounts[user]);
            }
            
        } else break;
    }
    
    // Reset variable/declare for adding a user
    count = 0;
    char response;
    char buffer[50];
    while (true) {
        cout << "Would you like to create a user? (y/n)" << endl;
        cin >> response;
        
        // We need to clear stdin from any '\n'
        cin.clear();
        fflush(stdin);
        if (response == 'y' || response == 'Y') {
            temp->clear();
            cout << "Enter birth date of user" << endl;
            cin.getline (buffer,50);
            line = string(buffer);
            temp->storeData(line, count);
            count++;
            cout << "Enter name" << endl;
            cin.getline (buffer,50);
            line = string(buffer);
            temp->storeData(line, count);
            count++;
            cout << "Enter savings amount" << endl;
            cin.getline (buffer,50);
            line = string(buffer);
            temp->storeData(line, count);
            count++;
            cout << "Enter checking amount" << endl;
            cin.getline (buffer,50);
            line = string(buffer);
            temp->storeData(line, count);
            count = 0;
            
            // Only update the array if the information entered is valid
            if (temp->isFull()) {
                accounts[accountNum] = new Customer(temp);
                accountNum++;
            } else {
                cout << "Error in entering a new user." << endl;
            }
        } else
            break;
    }
    
    // Save RAM data to ROM
    ofstream out_file;
    out_file.open("updated_account.dat");
    for (int i = 0; i < accountNum; i ++) {
        accounts[i]->saveToFile(out_file);
    }
    
    out_file.close();
    return 0;
}
