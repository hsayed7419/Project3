#include <iostream>
#include <string>
#include <fstream>

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
            void convertPubDate(string data) {
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
            void convertAuthor(string data) {
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
        
        /*  Deposits <amount> with <type>
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
}

int main() {
    
    return 0;
}