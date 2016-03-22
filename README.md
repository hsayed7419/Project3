You have been asked to write a program to organize accounts in a bank. Suppose all the accounts are stored in a data file called account.dat. Your program should read in the information from this data file and then provide on-line instructions for a user’s
transactions including withdraw, deposit, and check balance.  Your program should also allow users to create a new account for a new customer. Finally, your program should save the updated information to an output file called updated_account.dat.
You should use a class to store the information for each customer, which contains private data members:

Birth_date  (data type: a struct)
Name (data type: a struct) 
Balance_saving ( data type: float) 
Balance_checking (data type: float)

public data members:
void withdraw( float amount, int  account_type); 
void deposit (float amount, int  account_type);  
void check_balance( );  // print out the balance on screen 

customer(  );   // default constructor          
customer(Date birth_date,  Name  name, float initial_saving, float
initial_checking);  // parameterized constructor

The record for birth date should contain the following information:
Day (data type: integer) 
Month (data type: integer) 
Year (data type: integer)

The customer’s name is followed by balances in saving and checking accounts.
A typical input data file looks like:
1 8 1943 
Margaret Dana Mitchell 
1000.00 
5000.00 
1 12 1955 
Mario C. Puzo
9930.00 
0.00

An array of class should be used to hold the information of all the accounts in the data file.

When your program writes the information of updated accounts to the output file, you
don’t need to sort them. However, you need to include any new account that was created
interactively by using your program.  

Hints:
What you need to do is to read in all the information in the data file and assign the information to a Customer array. Each array element is one customer, and each customer has the information of Birth Date, Name, and balances. In this question, you are not requested to create an account number for each customer. You may do so if you like. But, it is not required. When you access a customer, you may use birth date or name as a search key to find the record in the Customer array. Essentially, you just do a for loop through all the customers and find a match of the key to locate that particular customer. To provide solutions to this project, you need to deliver the following components on the basis of principles in software engineering.

Component 1:   Software System Design
Use the object-oriented approach to design this banking system and use the Unified Modeling Language (UML) to describe the system that you will implement in this project. In particular, provide a use case diagram and a class diagram.

Component 2:   Software Debugging
Record the major debugging history when you implement your design.  The following table is a format that you need to use in this project.
