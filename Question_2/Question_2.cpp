
//  Name        : ORIAZOWAN EMMANUEL
//  Student ID  : 2523224
//  Assignment 1 (Question 2)

/*  
Brief Description of Code:
 This program enables the user to calculate their monthly mobile phone bill.
 With landline call rate set at 15p per minute and Mobileline call rate at 30p per minutes, The program allows users to type in the total number of minutes used 
 and then calculate the total billed amount.
 The program also introduces discounts levels on the different ranges of minutes (for both land line and mobile line subscribers)
 Discount types:
 1. 100 minutes below - No Discounts
 2. Above 100 mins up to 200 mins - 5% discount
 3. Above 200 mins up to 400 mins - 10% discount
 4. Above 400 mins - 15% discount

 Other extra features:
 1. The program gives subscriber the choice to run it multiple times.
 2. It redirects the customer when a wrong option is selected
*/

// Functions used in the the program 
//   1. A discount Function to set the different discounts for the call bill 
//   2. Time converter function to convert the minutes user enters to Hours and Minutes format
//   3. A mobile line function to calculate the call bill (including discounts) for mobile line subscribers customer
//   4. A land line function to calculate the call bill (including discounts) for land line subscribers customer


#include <iostream>
#include <iomanip>
using namespace std;

//A Function to calculate the discount of the call bill ('perc' is the percentage discount)
float discount(float perc, float value)
{
    float Newvalue = (100.0 - perc) * value / 100.0;

    return Newvalue;
}

//A function to convert Minutes to Hours and Minutes format
void timeconverter(int minutesvalue)
{
    cout << "You spent " << minutesvalue / 60 << "Hour(s) and " << minutesvalue % 60 << "minutes on the call." << endl;
}

//A function to calculate the call bill for land line subscribers
void landline()
{
    float landrate = 15.0;
    float callminutes = 0.0;
    float callbill = 0.0;

    cout << "--------------------------------------------------------------\n";
    cout << "Kindly note that the current rate Landline calls is: " << landrate << "p/minutes" << endl;
    cout << "Enter no of minutes used on the call below: " << endl;
    cin >> callminutes;
    cout << "--------------------------------------------------------------\n";

    //Code to check if minutes entered is up to or greater than an Hour and then converted to Hours and Minutes format
    if (callminutes >= 60) {
        timeconverter(callminutes); 
    }
    else {
      cout << "You spent " << callminutes << " minutes on the call" << endl;
    }
   
        callbill = callminutes * (landrate / 100.0); //This line calculates the bill in Pounds format
    
   //Multiple conditions to check and apply discounts to subscriber bills (setprecision function is used to bill value within the 2 decimal Pounds format)
    if (callminutes <= 100)
    {
        cout << "Your Landline bill is: " << char(156) << fixed << setprecision(2) << callbill << endl;
    }
    if (callminutes > 100 && callminutes <= 200)
    {
        cout << "Congratulations! You got a 5% discount \nYour Landline bill is now: " << char(156) << fixed << setprecision(2) << discount(5, callbill) << endl;
    }
    if (callminutes > 200 && callminutes <= 400)
    {
        cout << "Congratulations! You got a 10% discount \nYour Landline bill is now: " << char(156) << fixed << setprecision(2) << discount(10, callbill) << endl;
    }
    else if (callminutes > 400)
    {
        cout << "Congratulations! You got a 15 % discount \nYour Landline bill is now: " << char(156) << fixed << setprecision(2) << discount(15, callbill) << endl;
    }

}

//A function to calculate the call bill for mobile line subscribers
void mobileline()
{
    float mobilerate = 30.0;
    float callminutes = 0;
    float callbill = 0;

    cout << "--------------------------------------------------------------\n";
    cout << "Kindly note that the current rate for Mobile line calls is: " << mobilerate << "p per minutes" << endl;
    cout << "Enter no of minutes used on the call below: " << endl;
    cin >> callminutes;
    cout << "--------------------------------------------------------------\n";

    //Code to check if minutes entered is up to or greater than an Hour and then converted to Hours and Minutes format
    if (callminutes >= 60) {
        timeconverter(callminutes); 
    }
    else {
        cout << "You spent " << callminutes << " minutes on the call" << endl;
    }

    callbill = (callminutes * mobilerate) / 100.0; //This line calculates the bill in Pounds format

    //Multiple conditions to check and apply discounts to subscriber bills (setprecision function is used to keep it within 2 decimal Pounds format)
    if (callminutes <= 100)
    {
        cout << "Your Mobile line bill is: " << char(156) << fixed << setprecision(2) << callbill << endl;
    }
    if (callminutes > 100 && callminutes <= 200)
    {
        cout << "Congratulations! You got a 5% discount \nYour Mobile line bill is now: " << char(156) << fixed << setprecision(2) << discount(5, callbill) << endl;
    }
    if (callminutes > 200 && callminutes <= 400)
    {
        cout << "Congratulations! You got a 10% discount \nYour Mobile line bill is now: " << char(156) << fixed << setprecision(2) << discount(10, callbill) << endl;
    }
    else if (callminutes > 400)
    {
        cout << "Congratulations! You got a 15 % discount \nYour Mobile line bill is now: " << char(156) << fixed << setprecision(2) << discount(15, callbill) << endl;
    }

}



int main()
{
    int option = 0;
    int repeat;
    do
    {
        do
        {
            cout << "Dear Subscriber,\nWelcome to The Emma Communications Intl!" << endl;
            cout << "--------------------------------------------------------------\n";
            cout << "BILLING CHECKER" << endl;
            cout << "Enter option '1' if you use a landline \nEnter option '2' if you use a mobile line " << endl;
            cin >> option;

            if (option != 1 && option != 2)
            {
                cout << "You entered a wrong option" << endl;
            }
            cout << endl;
        }
        while (option != 1 && option != 2); //This do-while loop prompts user to re-enter subscriber choice, if user enters an option apart from 1 and 2 

        switch (option)

        {
        // Case 1 calls the landline function
        case 1:

            landline();
            cout << endl;

        break;

        //Case 2 calls the mobile line function
        case 2:

            mobileline();
            cout << endl;

        break;

        }

        cout << "Are you satisfied? \nEnter '1' to Check another billing or enter '2' to Exit" << endl;
        cin >> repeat;
        cout << endl;
    } while (repeat == 1);//This do-while loop prompts user to re-run the billing program (1 for re-run and 2 for end)

    cout << "Thank you for using our services, bye";

    return 0;
}
    

