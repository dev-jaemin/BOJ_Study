#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
typedef struct {
    string name;
    int kor;
    int eng;
    int math;
} STUDENT;

vector<STUDENT> v;

bool compare(STUDENT a, STUDENT b){
    if(a.kor == b.kor){
        if(a.eng == b.eng){
            if(a.math == b.math){
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.eng < b.eng;
    }
    return a.kor > b.kor;
}



int main(int argc, char* argv[]) {
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i=1;i<=n;i++){
        STUDENT s;
        cin >> s.name >> s.kor >> s.eng >> s.math;
        v.push_back(s);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i=0;i<n;i++){
        cout << v[i].name << '\n';
    }
    
    
	
	return 0;
}