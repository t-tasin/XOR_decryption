#include <iostream>


using namespace std;

void combinations();

int main() {
    //testing combinations function
    combinations();
    return 0;
}

// No parameters
// Generate and adds all possible combinations of the ASCII char a-z (lowercase only) as strings to an array called keyCombinations
// The function also currently prints out all the combinations with the number of combination that it is.
// The combinations are added alphabetically to the keyCombinations array.
void combinations(){
    string arr [] = {"a","b","c","d","e","f","g",
                     "h","i","j","k","l","m","n",
                     "o","p","q","r","s","t","u",
                     "v","w","x","y","z"};

    //I forgot how to dynamically increase the size of an array in c++ so I used the count variable to find out
    // how many combinations there were and then used that to declare and initialize the keyCombinations array.
    string keysCombinations [17575];
    int count = 0;

    //for loop for the first letter in combinations
    for (int i = 0; i <= 25; i++)
    {
        //for loop for the second letter in combinations
        for (int j = 0; j <= 25; j++)
        {
            //for loop for the third letter in combinations
            //This is where the combinations are appended to the keyCombinations array
            for (int h = 0; h <= 25; h++)
            {

                keysCombinations [count] = arr[i] + arr[j] + arr[h];
                count ++;
            }
        }
    }
    // for loop to print out keyCombinations array
    for (int i = 0; i <= 17575; i++)
    {
        cout << i << ": " << keysCombinations[i] << endl;
    }
}