#include <iostream>
#include <vector>

using namespace std;

int findLengthMaxSubSeq(vector<int>& A){
    vector<int> u = {};
    int L_max = 0;
    
    for (int k = 0; k < A.size(); k++){
        int j = -1;
        while (j + 1 < u.size() && A[k] > u[j + 1]){ j++;}
        if (j == u.size() - 1){
            u.push_back(A[k]);
            L_max++;
        }
        else if (j > -1){
            u[j + 1] = A[k];   
        }
    }
    
    return L_max;
} 


int main()
{
    vector<int> A = {1, 2, 3, 2, 4, 3, 5, 6, 7, 1, 1, 2, 8, 9, 2};
    
    cout << findLengthMaxSubSeq(A);
    
    return 0;
}