//CCC '14 S2 - Assigning Partners, Alex Gomes
//https://dmoj.ca/problem/ccc14s2
#include <iostream>
#include <string>
#include <deque>
 
using namespace std;
 
int main()
{
    int students;
    string line1;
    string line2;
    string buffer;
    deque<string> partnerA;
    deque<string> partnerB;
    deque<string> groupA;
    deque<string> groupB;
    bool good;
    
    cin >> students;
    cin.ignore();
    if (students >= 1 && students <= 30){
        getline(cin, line1);
        getline(cin, line2);
    }
    else{
        cout << "Out of bounds; 1 <= Students <= 30, please try again." << endl;
        return 0;
    }
    if (students % 2 != 0){
        cout << "bad" << endl; //case of uneven students, one will always be alone
        return 0;
    }
    //seperating and indexing partner A
    for (int i = 0; i < line1.length(); i++){
        if (line1[i] != ' '){
            buffer += line1[i];
        }
        else{
            partnerA.push_back(buffer);
            buffer = "";
        }
    }
    partnerA.push_back(buffer); //still a value left in buffer, put the last name in deque
    buffer = ""; //clear
    //Repeat for partner B
        for (int i = 0; i < line2.length(); i++){
        if (line2[i] != ' '){
            buffer += line2[i];
        }
        else{
            partnerB.push_back(buffer);
            buffer = "";
        }
    }
    partnerB.push_back(buffer); //still a value left in buffer, put the last name in deque
    
    for (int i = 0; i < students; i++){
        if (partnerA.at(i) == partnerB.at(i)){
            cout << "bad" << endl; //case of same student paired
            return 0;
        }
        groupA.push_back(partnerA.at(i) + partnerB.at(i));
        groupB.push_back(partnerB.at(i) + partnerA.at(i));
    }
    
    for (int i = 0; i < groupA.size(); i++){
        for (int j = 0; j < groupB.size(); j++){
            if (groupA.at(i) == groupB.at(j)){
                good = true;
                break;
            }
            else{
                good = false;
            }
        }
		if (!good){ //If it's not good here, it's not going to be good overall
			cout << "bad" << endl;
			return 0;
		}
    }
    
    if (good){
        cout << "good" << endl;
    }
    else{
        cout << "bad" << endl;
    }
    return 0;
}


