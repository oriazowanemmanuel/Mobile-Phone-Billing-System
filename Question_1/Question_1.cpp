//  Name        : ORIAZOWAN EMMANUEL
//  Student ID  : 2523224
//  Assignment 1 (Question 1)

/*  Brief Description of Code :
This program is designed to produce a series of triangles pointing to the right, drawn with a keyboard character such as the *,
which, when the program runs, will imitate 'waves'.
The program allows the user to specify the size of the waves to be drawn and how many waves are to be drawn altogether.
The user can also specify if the wave size stays the same or gets bigger and bigger.


 Other extra Features:
 1. The program allows gives user the choice to run it multiple times.
 2. It redirects the customer when a wrong option is selected

*/

// Functions used in the the program 
//   1. Delay Function to adjust the speed of the wave ( delay (const int MILLISECONDS))
//   2. A function to generate a single wave (void wave (int n))
//   3. A function to generate incremental waves (void incrementalwaves ())
//   4. A function to generate the same size waves (void samesizeWave())




#include<iostream>

#include<time.h> //#include <time.h> header file allowing the functions used in time delay

using namespace std;

//A function to determine the speed of the wave
void delay(const int MILLISECONDS)
{
    clock_t goal = MILLISECONDS + clock();

    while (goal > clock()); 
}

//A function to generate a single wave (Full Pyramid)
void wave(int n)
{
    //Code for first half pyramid of the wave (n is the wave size)
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)

        {
            delay(100); //The value of the delay funciton argument can be adjusted to increase or decrease the wave speed
            cout << "*";
        }
        cout << endl;

    }
    //Code for second half pyramid of the wave (n is the wave size)
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 1; j <= i; j++)

        {
            delay(100);
            cout << "*";
        }
        cout << endl;
    }

}

//A function to generate growing wave sizes. w is number of waves
void incrementalWave()

{
    int w; 

    cout << "How many waves will you like see? (Since it is incremental, the wave size starts at 2)" << endl;
    cin >> w;
    cout << "--------------------------------------------------------------\n";
    cout << "Your wave starts now, Enjoy!" << endl;

    for (int l = 2; l <= w + 1; l++) //This loop's initial value is 2 because the wave size increases as the wave iterates.
    {

        wave (l); //size of wave is automatically set to the value of 'l' beacuse the size of this wave grows as the loop iterates
   
    }
}


//A function to generate the same wave sizes (w is preferred number of waves)
void samesizeWave()

{
    int w; 
    int n;

    cout << "How many waves will you like see?" << endl;
    cin >> w;
    cout << "Enter the size of wave" << endl;
    cin >> n; 
    cout << "--------------------------------------------------------------\n";
    cout << "Your wave starts now, Enjoy!" << endl;

    for (int l = 1; l <= w ; l++) //This loop iterates the waves multiple times
    {

        wave(n);

    }
}

int main()

{
    int option = 0;
    int repeat = 0;
    do
    {
        do
        {
            cout << "WAVE SIMULATOR \nSelect your wave type" << endl;
            cout << "Enter option '1' if you want the wave to grow bigger \nEnter option '2' if you want the wave stay same size " << endl;
            cin >> option;
            cout << "--------------------------------------------------------------";
            if (option != 1 && option != 2)
            {
                cout << "You entered a wrong option!" << endl;
            }
            cout << endl;

        } while (option != 1 && option != 2); //This do-while loop prompts user to re-enter choice of wave type, if user enters an option apart from 1 and 2  

        switch (option)
        {
        //Case 1 calls the incremental wave function
        case 1: 

            incrementalWave();
            cout << endl;
        break;

        //Case 2 calls the same wave size function
        case 2: 

            samesizeWave();
            cout << endl;
        break;

        }

        cout << "Enjoyed it??\nEnter '1' to Start again or enter '2' to Exit" << endl;
        cin >> repeat;
        cout << endl;
    } while (repeat == 1); //This do-while loop prompts user to re-run the wave simulator (1 for re-run and 2 for end)


    return 0;

}
