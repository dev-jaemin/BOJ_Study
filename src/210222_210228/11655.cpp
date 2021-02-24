#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
string str;


int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    getline(cin, str);
    
    for(int i=0;i<str.length();i++){
        if(str[i] >= 65 && str[i] <= 77){
            str[i] += 13;
        }
        else if(str[i] >= 78 && str[i] <= 90){
            str[i] -= 13;
        }
        else if(str[i] >= 97 && str[i] <= 109){
            str[i] += 13;
        }
        else if(str[i] >= 110 && str[i] <= 122){
            str[i] -= 13;
        }
    }
    
    cout << str << '\n';
	
	return 0;
}