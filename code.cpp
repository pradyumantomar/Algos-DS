//------------------1st question-------------------// 

#include<bits/stdc++.h>

int fragments(string &A , string &B){
    int c=0;

    for(int i =0;i<A.length();i++){
        string sub1="" , sub2="";
        for(int j=i;j<B.length();j++){
            sub1+=A[j];
            sub2+=B[j];
            sort(sub1.begin(),sub1.end());
            sort(sub2.begin(),sub2.end());
            if(sub1!=sub2)continue;
            c++;
        }
    }

    return c;

}




int solution(string &A , string &B){

    return fragments(A,B);


}



//---------2nd question--------------------//

#include<bits/stdc++.h>



int largest(vector<int>& Arr) {
    set<int> set1;
        string result = ""; 
        do{
            result ="";
            int h_format = Arr[0]*10 + Arr[1];
            int m_format = Arr[2]*10 + Arr[3];
            if( h_format >= 24 || m_format >= 60 ) continue;
            result = to_string(Arr[0]) + to_string(Arr[1])
            result+= ":" + to_string(Arr[2]) + to_string(Arr[3]);
            set1.insert(result);
        } while (std::next_permutation(Arr.begin(), Arr.end()));
        return set1.size() ;
    }

int solution(int A, int B, int C, int D){

    vector<int> Arr;
    Arr.push_back(A);
    Arr.push_back(B);
    Arr.push_back(C);
    Arr.push_back(D);

    return largest(Arr);


}