#include <iostream>
#include <string>
#include <fstream>

#define DEBUG true;

using namespace std;

class Customer {
    private:
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
                    }
                    else {
                        temp += c;
                    }
                }
                year = stringToInt(data.substr(yearAt, data.length() -  yearAt));
                }
            }
        } date;
        
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
        
        /* Used to simplify the stoi call
        * Will not compile in MinGW v 1.7-1.9
        */
        int stringToInt(string data) {
            size_t *size = 0;
            return stoi(data, size, 10);
        }

        /* Used to simplify the stof call
        * Will not compile in MinGW v 1.7-1.9
        */
        float stringToFloat(string data) {
            size_t *size = 0;
            return stof(data, size);
        }
    public:
        /*  Withdraws <amount> with <type>
            type: 0 is savings, 1 is checking
        */
        void withdraw(float amount, int account_type){
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
        
        /*  Deposits <amount> with <type>
            type: 0 is savings, 1 is checking
        */
        void deposit(float amount, int account_type){
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
        
        /*  Displays <type> to the user
            type: 0 is savings, 1 is checking
        */
        void deposit(int account_type){
            switch (account_type){
                case 0:
                    cout << "Savings Balance is: $" << Balance_saving << endl;
                    break;
                case 1:
                    cout << "Checking Balance is: $" << Balance_checking << endl;
                    break;
                default:
                    if (DEBUG)
                        cout << "Wrong account type" << endl;
                    break;
            }
        }
        
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
        
        Customer (Customer customer){
            Birth_date.month = customer.Birth_date.month;
            Birth_date.day = customer.Birth_date.day;
            Birth_date.year = customer.Birth_date.year;
            Name.First_name = customer.Name.First_name;
            Name.Middle_name = customer.Name.Middle_name;
            Name.Last_name = customer.Name.Last_name;
            Balance_saving = customer.Balance_saving;
            Balance_checking = customer.Balance_checking;
        }
}

int main() {
    
    return 0;
}