#include <iostream>
#include <vector>
using namespace std;


void create_set(int i, int* parents, int* rank){
    parents[i] = i;
    rank[i] = 0;
}

int find_id(int i, int* parents){
    while (parents[i] != i){
        i = parents[i];
    }

    return i;
}

void set_union(int i, int j, int* parents, int* rank){
    int root_i = find_id(i, parents);
    int root_j = find_id(j, parents);
    if (root_i != root_j){
        if (rank[root_i] > rank[root_j]){
            parents[root_j] = root_i;
        }
        else if (rank[root_i] < rank[root_j])
        {
            parents[root_i] = root_j;
        }
        else{
            parents[root_j] = root_i;
            rank[root_i] += 1;
        }
    }
}


int main(){
    vector<vector<int>> data = {};
    vector<int> row_vector = {};

    //generate poligon
    for (int i = 0; i < 10; i++){
        row_vector = {};
        for (int j = 0; j < 10; j++){
            if (i == 0) row_vector.push_back(0);
            if (i == 1){
                if (j == 0) row_vector.push_back(0);
                else row_vector.push_back(1);
            }
            if (i == 2) row_vector.push_back(0);
            if (i == 3) row_vector.push_back(1);
            if (i == 4) {
                if (j < 5) row_vector.push_back(0);
                else if (j == 5) row_vector.push_back(1);
                else row_vector.push_back(0);                
            }
            if (i == 5) {
                if (j < 5) row_vector.push_back(0);
                else if (j == 5) row_vector.push_back(1);
                else row_vector.push_back(0);                
            }
            if (i == 6) {
                if (j < 5) row_vector.push_back(0);
                else if (j == 5) row_vector.push_back(1);
                else row_vector.push_back(0);                
            }
            if (i == 7) {
                if (j < 5) row_vector.push_back(0);
                else if (j == 5) row_vector.push_back(1);
                else row_vector.push_back(0);                
            }
            if (i == 8) {
                if (j < 5) row_vector.push_back(0);
                else if (j == 5) row_vector.push_back(1);
                else row_vector.push_back(0);                
            }
            if (i == 9) {
                if (j < 5) row_vector.push_back(0);
                else if (j == 5) row_vector.push_back(1);
                else row_vector.push_back(0);                
            }
        }

        data.push_back(row_vector);
    }


    //DEBUG
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    
    //initialization
    int parents[10 * 10];
    int rank[10 * 10];

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (data[i][j] == 1) continue;
            create_set(i * 10 + j, parents, rank);
        }
    }


    //union
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (data[i][j] == 1) continue;
            if (j + 1 < 10 && data[i][j + 1] == 0){
                set_union(i * 10 + j, i * 10 + j + 1, parents, rank);
            }
            if (i + 1 < 10 && data[i + 1][j] == 0){
                set_union(i * 10 + j, (i + 1) * 10 + j, parents, rank);
            }
        }
    }
    

    //get paths
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (data[i][j] == 1) continue;
            data[i][j] = find_id(i * 10 + j, parents);
        }
    }

    
    //print
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}