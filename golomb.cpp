#include<iostream>
#include<vector>

int golombf_verifier(int k, std::vector<int> f_vector, std::vector<int> golomb_vector){
    for(int i=golomb_vector.size()-1; golomb_vector.size()-1 < k; i++){
        golomb_vector.push_back( 1+golomb_vector[i-golomb_vector[golomb_vector[i-1]]] );
    }

    return golomb_vector[k];
}

int golombf(int k, std::vector<int> f_vector, std::vector<int> golomb_vector){
    for(int i=f_vector.size()-1; f_vector[f_vector.size()-1] <= k; i++){
        f_vector.push_back(f_vector[i-1] + golombf_verifier(i, f_vector, golomb_vector));
    }
    
    int j=1;
    while(f_vector[j] <= k){
        j++;
    }

    return j;
}

int main(void){

    std::vector<int> input_vector, function_f_vector, golomb_vector;
    int input = 0;
    golomb_vector.push_back(1);
    function_f_vector.push_back(2);

    std::cin >> input;
    while( input > 0){
        input_vector.push_back(input);
        std::cin >> input;
    }

    for(int i=0; i<input_vector.size(); i++){
        std::cout << golombf(input_vector[i], function_f_vector, golomb_vector) << std::endl;
    }

    return 0;
}

