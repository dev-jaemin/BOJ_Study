#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

string input;
bool isFirst = true;

void printBinary(char c){
    switch(c){
        case '0' :
            cout << (isFirst ? "0" : "000");
            break;
        case '1':
            cout << (isFirst ? "1" : "001");
            break;
        case '2' :
            cout << (isFirst ? "10" : "010");
            break;
        case '3':
            cout << (isFirst ? "11" : "011");
            break;
        case '4' :
            cout << "100";
            break;
        case '5':
            cout << "101";
            break;
        case '6' :
            cout << "110";
            break;
        default:
            cout << "111";
            break;
    }
}


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> input;
    
    printBinary(input[0]);
    isFirst = false;
    
    for(int i=1;i<input.length();i++){
        printBinary(input[i]);
    }

    cout << '\n';
    
	return 0;
}