#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int main()
{
    int num;
    int guess;
    int tries = 0;
    int low = 1, high = 100; // Initial range

    srand(time(NULL));
    num = (rand() % 100) + 1;

    cout << "Number Guessing Game" << endl;

    do
    {
        cout << "Enter a number between " << low << " and " << high << ": ";
        cin >> guess;
        tries++;

        if (guess > num)
        {
            cout << "Too High" << endl;
            high = guess - 1; // Narrow the range downwards
        }
        else if (guess < num)
        {
            cout << "Too Low" << endl;
            low = guess + 1; // Narrow the range upwards
        }
        else
        {
            cout << "\nCorrect! You guessed it in " << tries << " tries." << endl;
        }

    } while (guess != num);

    return 0;
}
