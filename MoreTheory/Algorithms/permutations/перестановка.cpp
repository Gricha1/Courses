#include<iostream>
#include<vector>
#include<algorithm>

bool compare_asc(int a, int b) {
    return a < b;
}

bool compare_desc(int a, int b) {
    return a > b;
}

int main() {
    using namespace std;

    // test 1 
    vector<int> seq_1 = {1, 2, 3, 4};
    // test 2 
    vector<int> seq_2 = {4, 3, 2 ,1};
    // test 3
    vector<int> seq_3 = {1, 5, 3, 2, -1, 0, 32432, 43};
    // test 4
    vector<int> seq_4;
    for (int i = 0; i < 100; i++) {
        seq_4.push_back(i + 1);
    }
    
    vector<int> seq = seq_3;
    vector<int> last_seq = seq_3;
    sort(seq.begin(), seq.end(), compare_asc);
    sort(last_seq.begin(), last_seq.end(), compare_desc);
    bool equal;
    int t, j, temp;
    while (true) {

        // вывод
        for (int i = 0; i < seq.size(); i++) {
            cout << seq[i] << " ";
        }
        cout << endl;

        equal = true;
        for (int i = 0; i < seq.size(); i++) {
            if (seq[i] != last_seq[i]) {
                equal = false;
                break;
            }
        }
        if (equal) {
            break;
        }

        t = seq.size() - 2; // size >= 2
        while (t >= 0 && seq[t] >= seq[t + 1]) {
            t--;
        }   
        j = t + 1;
        while (j < seq.size() - 1 && seq[j + 1] >= seq[t]) {
            j++;
        }
        temp = seq[t];
        seq[t] = seq[j];
        seq[j] = temp;

        sort(seq.begin() + t + 1, seq.end(), compare_asc);
    }


    return 0;
}