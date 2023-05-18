#include <iostream>

void defArrEntering(double** arr, int max)
{    
    for (int column = 0; column < max; column++){
        for (int row = 0; row < max; row++){
            std::cin >> arr[column][row];
        }
    }
}

void defArrShowing(double** arr, int max)
{    
    for (int column = 0; column < max; column++){
        for (int row = 0; row < max; row++){
            std::cout << arr[column][row] << ' ';
        }
        std::cout << '\n';
    }
}

void defViterbi(double** words, double** speech, int max){
    double result;    
    double holder;
    for(int column; column < max; column++){
        for(int row; row < max; row++){
            holder = words[column][row] * speech[column][row];
            if (result < holder){
                result = holder;
            }
        }
    }
}



int main(){
const int speechmax = 10;
    int countWords = 2;
    double** speech;
    double** words;
    speech = new double*[speechmax];
    for (int index = 0; index < speechmax; index++){
        speech[index] = new double[speechmax];
    }
    words = new double*[countWords];
    for (int index = 0; index < countWords; index++){
        words[index] = new double[speechmax];
    }
    

    
    




    for(int index = 0; index < speechmax; index++){
        delete[] speech[index];
    }
    delete[] speech;

    for(int index = 0; index < countWords; index++){
        delete[] words[index];
    }
    delete[] words;
}