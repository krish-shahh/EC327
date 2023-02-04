/*
Write a program to randomly flips a fair coin until it sees a Heads followed immediately by a Tail Event 1]; 
Write a similar program that continues until it sees a Tail followed immediately by a Tail [Event 2]. 
Run your program 2622 times and report the total number of Heads and Tails for each two events.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int event1_heads = 0;
    int event1_tails = 0;
    int event2_heads = 0;
    int event2_tails = 0;

    srand(time(0));

    for (int i = 0; i < 2622; i++)
    {
        int previous_flip = 0;
        int current_flip = 0;
        bool event1_found = false;
        bool event2_found = false;

        while (!event1_found && !event2_found)
        {
            previous_flip = current_flip;
            current_flip = rand() % 2;

            if (previous_flip == 0 && current_flip == 1)
            {
                event1_found = true;
                event1_heads++;
                event1_tails++;
            }
            else if (previous_flip == 1 && current_flip == 1)
            {
                event2_found = true;
                event2_heads++;
                event2_tails++;  // add this line
            }
            else
            {
                if (current_flip == 0)
                {
                    event1_heads++;
                    event2_heads++;
                }
                else
                {
                    event1_tails++;
                    event2_tails++;
                }
            }
        }
    }

    cout << "Event 1 total heads: " << event1_heads << endl;
    cout << "Event 1 total tails: " << event1_tails << endl;
    cout << "Event 2 total heads: " << event2_heads << endl;
    cout << "Event 2 total tails: " << event2_tails << endl;

    return 0;
}
