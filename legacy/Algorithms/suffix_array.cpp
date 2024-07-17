/*
접미사 배열 -> 문자열 문제의 맥가이버 칼
한 문자열의 접미사들을 사전순으로 배열한 것
맨버-마이어스 알고리즘 사용 시 O(nlog^2n)
*/


//각 접미사들의 첫 t글자를 기준으로 한 그룹 번호가 주어질 때,
//주어진 두 접미사를 첫 2*t글자를 기준으로 비교한다.
//group[]은 길이가 0인 접미사도 포함한다.
struct Comparator{
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t): group(_group), t(_t){
        group = _group; t = _t;
    }
    bool operator () (int a, int b){
        //첫 t글자가 다르면 이들을 이용해 비교한다.
        if(group[a] != group[b]) return group[a] < group[b];
        //아니라면 S[a+t..]와 S[b+t..]의 첫 t글자를 비교한다.
        return group[a+t] < group[b+t];
    }
};


//s의 접미사 배열을 계산한다.
vector<int> getSuffixArray(const string& s){
    int n = s.size();
    //group[i]=접미사들을 첫 t글자를 기준으로 정렬했을 때,
    //         S[i..]가 들어가는 그룹 번호.
    //t=1일 때는 정렬할 것 없이 S[i..]의 첫 글자로 그룹 번호를
    //정해 줘도 같은 효과가 있다.
    int t = 1;
    vector<int> group(n+1);
    for(int i=0;i<n;i++) group[i] = s[i];
    group[n] = -1;
    //결과적으로 접미사 배열이 될 반환 값. 이 배열을 lg(n)번 정렬한다.
    vector<int> perm(n);
    for(int i=0;i<n;i++) perm[i] = i;
    while(t < n){
        //group[]은 첫 t글자를 기준으로 계산해 뒀다.
        //첫 2t글자를 기준으로 perm을 다시 정렬한다.
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);
        //2t글자가 n을 넘는다면 이제 접미사 배열 완성!
        t *= 2;
        if(t >= n) break;
        //2t글자를 기준으로 한 그룹정보를 만든다.
        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for(int i=1;i<n;i++)
            if(compareUsing2T(perm[i-1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i-1]];
        group = newGroup;
    }
    return perm;
}