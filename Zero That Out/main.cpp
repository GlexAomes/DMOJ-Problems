//CCC '15 S1 - Zero That Out, Alex Gomes 
//https://dmoj.ca/problem/ccc15s1
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    deque<int> statement;
    int numbers = 1;
    int counter = 0;
    int total = 0;
    int buffer;
    cin >> numbers;
    if (numbers >= 1 && numbers <= 100000){
        while(counter != numbers){
            cin >> buffer;
            if (buffer == 0 && counter != 0){
                statement.pop_back();
            }
            else{
                statement.push_back(buffer);
            }
            counter++;
        }
    }
    else{
        cout << "Out of bounds; 1 <= Number <= 100000, please try again." << endl;
        return 1;
    }
    for (int i = 0; i < statement.size(); i++){
        //cout << statement.at(i) << endl;
        total += statement.at(i);
    }
    cout << total;
    return 0;
}
