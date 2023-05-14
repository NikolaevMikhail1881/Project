#include <iostream>

void table(int n){
    int *noun {new int[n]};
    int *verb {new int[n]};
    int *adj {new int[n]};
    int *pretext {new int[n]};
    int *article {new int[n]};
    int *period {new int[n]};
    int *sign {new int[n]};
    int *pronoun {new int[n]};
    int *and_but {new int[n]};
    int *els {new int[n]};

    
}

int entering_arr(int *arr[], int n){
    for (int i = 0; i < n; i++){
        std::cin >> arr[i] >> std::endl;
    }
    return;
}

int main(){
    int *noun {new int[2]};
    std::cout << entering_arr(noun[2], 2)<<'\n';

}