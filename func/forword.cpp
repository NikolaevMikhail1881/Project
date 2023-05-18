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

int defSumRows(double** arr, int max, int colum){
    int result = 0;
    for (int row = 0; row < max; row++){
        result = result + arr[colum][row];
    }
    return result;
}

void defSecondPos(double** arr, int max){
    int sumRows;
    for (int column = 0; column < max; column++){
        sumRows = defSumRows((double**)arr, max, column);
        for (int row = 0; row < max; row++){   
            arr[column][row] = arr[column][row] / sumRows;
        }
    }
}

void defForwordSum(double** speech,double** words, int max){
    double sum = 0;

    for (int column = 0; column<max; column++){
        for (int row = 0; row < max; row++){
            sum = sum + (speech[column][row] * words[column][row]);
            std::cout << sum << ' ';
        }
        for (int row; row < max; row++){
        words[column][row] = words[column][row] * sum;
    }
    }

    
}


void defForword(double** words, int lenmax, int himax){



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
    

    defArrEntering(speech, 2);
    std::cout << '\n';    
    defArrShowing(speech, 2);
    std::cout << '\n';
    defArrEntering(words, 2);
    std::cout << '\n';
    defArrShowing(words, 2);
    std::cout << '\n';
    defForwordSum(speech,words, 2);
    std::cout << '\n';
    defArrShowing(words, 2);
    
    




    for(int index = 0; index < speechmax; index++){
        delete[] speech[index];
    }
    delete[] speech;

    for(int index = 0; index < countWords; index++){
        delete[] words[index];
    }
    delete[] words;
}









/*int *noun {new int[n]};
    int *verb {new int[n]};
    int *adj {new int[n]};
    int *pretext {new int[n]};
    int *article {new int[n]};
    int *period {new int[n]};
    int *sign {new int[n]};
    int *pronoun {new int[n]};
    int *and_but {new int[n]};
    int *els {new int[n]};
    enteringArr(noun, n);
    enteringArr(verb, n);
    enteringArr(adj, n);
    enteringArr(pretext, n);
    enteringArr(article, n);
    enteringArr(period, n);
    enteringArr(sign, n);
    enteringArr(pronoun, n);
    enteringArr(and_but, n);
    enteringArr(els, n);
    */