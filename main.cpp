/** Lab 13 - The prime number generator
 *  Martina Nunvarova
 *  24/01/2018
 */

 ///includes
#include <iostream>
#include <fstream>

///namespace
using namespace std;

///main
int main()
{
    ///variables
    ofstream of;
    int maxNo,noCount;
    ///request user input
    cout <<"Find primes - exhaustive search (Brute force)"<<endl<<endl;
    cout << "Enter the max number: ";
    ///get user input
    cin>>maxNo;
    ///open output file;
    of.open("primeNumbers.txt");

    ///print neatly on screen
    cout << endl<<"Here are the primes:"<<endl;
    ///and into the file
    of << endl<<"Here are the primes:"<<endl;
    noCount=0;
    for (int i=2;i<=maxNo;i++) {    ///exhaustively - check all the numbers smaller or equal to what the user requested
        for (int j=2;j<(i/2);j++)   ///and check all the numbers from 2 to ((1/2)*N -1)
            if (i%j==0)
                goto NotAPrime;     ///if it was divisible without reminder,it is not a prime and do not list the number
        noCount++;
        cout << i<<", ";            ///it was found to be a prime, print it
        of << i<<", ";              ///and write it into the file

        if (!(noCount%10)) {        ///Format the output - 10 primes per line
            cout <<endl;
            of << endl;
        }

NotAPrime:                          ///point to jump to if not a prime (skips printing) - IF statement would take more processor time
    asm("nop");                     ///label can not point to a "}" an instruction is needed.
    }
    of.close();                     ///close the output file
    return 0;                       ///return to OS no errors
}
