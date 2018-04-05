//CCC '14 S1 - Party Invitation, Alex Gomes
//https://dmoj.ca/problem/ccc14s1
#include <iostream>
#include <string>
#include <deque>
 
using namespace std;
 
int main()
{
    int friends;
    int rounds;
    deque<int> elimFactors;
    deque<int> candidates;
    deque<int> invitations;
    
    cin >> friends; //Get how many friends
    if (friends < 1 || friends > 100){ //Make sure it's within domain
        cout << "Out of bounds: 1 <= Friends <= 100" << endl;
        return 1;
    }
    
    cin >> rounds; //Get how many rounds
    if (rounds < 1 || rounds > 10){ //Make sure it's within domain
        cout << "Out of bounds: 1 <= Rounds <= 10" << endl;
        return 1;
    }
    
    for (int i = 0; i < rounds; i++){ //Get the elimination factors
        int buffer; //need to use a buffer to transfer cin into a value to push into the deque
        cin >> buffer;
        elimFactors.push_back(buffer);
    }
    
    for (int i = 1; i <= friends; i++){ //Populate the friends list 
        candidates.push_back(i);
    }
    
    for (int i = 0; i < rounds; i++){ // Loop for each round of eliminations
        int buffer = elimFactors.at(i); //Grab the elim factor of round i from deque
        int match = 2; //since no less than 2, start at 2
        int removed = 0; //keep track
        for (int j = 1; j <= (candidates.size()+removed-1); j++){ //account for 0-based shift, size differential and offset of 1 for j
            if(match == buffer){ //if number is a factor, trapped since it resets if true
                candidates.erase(candidates.begin()+j-removed);
                match = 0; //reset incrementer
                removed++;
            }
            match++; //increment to next number
        }
    }
    for (int i = 0; i < candidates.size(); i++){ //Display the invitees
        cout << candidates.at(i) << endl;
    }
    
    return 0;
}

