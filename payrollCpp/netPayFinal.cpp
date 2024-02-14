/*
Name: Michele Roosje
Date: Nov 11, 2023
Modified Dec 03, 2023
File Name: netPayfinal.cpp
Purpose: To create a payroll program to input First and last name, employee number, weekly hours worked, and skill level.
To calculate gross weekly pay, taxes, and net pay based on given information.
Include instructions, titles, and headers.
Print information to screen and to a file named weeklyPayroll.txt. End the program when terminated by user.
Additional info Junior Programmer: (0-4 years) $25/hr- tax 20%, Intermediate Programmer: (5-9 years) $45/hr- tax 25%, and
Senior Programmer: (10+ years) $65/hr- tax 30%.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void introduction();
int instructions();
void employeeInfo(string &empNum, string &fName, string &lName);
char employeeSkillLvl();
void weeklyPay(float payRt, float taxRate, string empNum, float &grossPay, float &taxRemit, float &netPay);
float calcGrossPay(float hours, float payRt);
void payRate(char skLvl, float &payRt, float &taxRate);
void saveToFile(string empNum, float grossPay, float taxRemit, float netPay);
void calcWeekTotal(float grossPay, float taxRemit, float netPay, float &ttlGrossPay, float &ttlTaxRemit, float &ttlNetPay);

int main() {
    string empNum, fName, lName;
    char skLvl;
    float payRt, grossPay, taxRemit, netPay, taxRate, ttlGrossPay, ttlTaxRemit, ttlNetPay;
    //sets the floats to two decimal places when they print out to the screen
    cout << fixed << setprecision(2);
    
    introduction();
    int contin = instructions();
    while(contin != -1){
        employeeInfo(empNum, fName, lName);

        skLvl = employeeSkillLvl(); 

        payRate(skLvl, payRt, taxRate);

        weeklyPay(payRt, taxRate, empNum, grossPay, taxRemit, netPay);

        calcWeekTotal(grossPay, taxRemit, netPay, ttlGrossPay, ttlTaxRemit, ttlNetPay);
        
        cout << " Payroll information for employee " << empNum << ".\n\n"; 
        cout << " Employee Number: " << empNum << " Gross Pay $" << grossPay << " Taxes Remitted $" << taxRemit << " Net Pay $" << netPay << endl;

        saveToFile(empNum, grossPay, taxRemit, netPay);
    
        cout << " \nEnter 1 to calculate the next employee's pay or -1 to quit the program \n\n";
        cin >> contin;
    }
    //print total weekly information to the screen
    cout << " Weekly Totals: Gross Pay $" << ttlGrossPay << " Taxes Remitted $" << ttlTaxRemit << " Net Pay $" << ttlNetPay << endl;
}

void introduction() {
    cout << "****************************************************************************************************** \n";
    cout << "                                Welcome to Employee Payroll Tracker. \n";
    cout << " Please enter the required information to calculate gross pay, tax remittance, and net pay for each employee.\n";
    cout << "****************************************************************************************************** \n\n";
}

int instructions() {
    int cont;

    cout << " Would you like to enter payroll information for an employee? \n";
    cout << " Enter 1 to continue and -1 to exit the program. \n";
    cin >> cont;

    return cont;
}
//gets the employee number, first name, and last name from the user
void employeeInfo(string &empNum, string &fName, string &lName) {
   
    cout << " Enter the employee's number. \n";
    cin >> empNum;
    cout << " Enter the employees first name. \n";
    cin >> fName;
    cout << " Enter the employees last name. \n";
    cin >> lName;
}
//gets the employee skill level from the user
char employeeSkillLvl() {
    char skill;

    cout << "\n Enter the employees skill level. Enter a j for junior, an i for intermediate, or an s for senior. \n";
    cin >> skill;

    return skill;
}
//function to determin gross pay, tax remitance, and net pay.
void weeklyPay(float payRt, float taxRate, string empNum, float &grossPay, float &taxRemit, float &netPay) { 
    float hours;
           
    cout << " How many hours did employee " << empNum << " work this week?\n";
    cin >> hours;

    //call function to calculate gross pay
    grossPay = calcGrossPay(hours, payRt);        
    taxRemit = grossPay * taxRate;
    netPay = grossPay - taxRemit;
    }

//Function to determin if overtime was worked and calculate regular pay, overtime pay, and gross pay. returns gross pay.
float calcGrossPay(float hours, float payRt) {
    float gross, overtime, overtimePay;
    //determins if hours worked are greater than regular hours. If there are overtime hours it 
    //calculates the amount of overtime worked and the amount paid
    if (hours > 40) {
        overtime = (hours - 40);
        overtimePay = overtime * (payRt * 1.5);
        gross = overtimePay + (40 * payRt);
    }else {
        gross = hours * payRt;
    }
    return gross;
}

//function that saves weekly employee number, gross pay, tax remittance, and net pay to a file
void saveToFile(string empNum, float grossPay, float taxRemit, float netPay){
    
        // create (if it doesnt exist) and open the file. Append to the end of the file
        ofstream payrollFile("weeklyPayroll.txt", ios::out | ios::app);
        //sets the floats to two decimal places in the file
        if(payrollFile.is_open()){
            payrollFile << fixed << setprecision(2);
            //write this to the file
            payrollFile << empNum << " " << grossPay << " " << taxRemit << " " << netPay << "\n";
            //close file
            payrollFile.close();
        }else cout << "Unable to open file";
}

//function calculates the total gross pay, tax remittance, and net pay for all employees entered each week.
void calcWeekTotal(float grossPay, float taxRemit, float netPay, float &ttlGrossPay, float &ttlTaxRemit, float &ttlNetPay){
    ttlGrossPay += grossPay;
    ttlTaxRemit += taxRemit;
    ttlNetPay += netPay; 
}

// change the skill level char to the pay rate and tax rate
void payRate(char skLvl, float &payRt, float &taxRate) {
    
    switch(skLvl) {
    case 'j' :
    case 'J' :
    {
        payRt = 25.00;
        taxRate = 0.20;
       // return payRt, taxRate;
        break;
    }
    case 'i' :
    case 'I' :
    {
        payRt = 45.00;
        taxRate = 0.25;
       // return payRt, taxRate;
        break;
    }
    case 's' :
    case 'S' :
    {
        payRt = 65.00;
        taxRate = 0.30;
       // return payRt, taxRate;
        break;
    }
    } 
}

