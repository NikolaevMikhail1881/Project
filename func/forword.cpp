#include <iostream>
#include <vector>

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
            std::cout << arr[column][row];
        }
    }
}

int defSumRows(double** arr, int max, int row){
    int result;
    for (int column = 0; column < max; column++){
        result = result + arr[row][column];
    }
    return result;
}

void defSecondPos(double** arr, int max){
    int sumRows;
    for (int column = 0; column < max; column++){
        for (int row = 0; row < max; row++){
            int sumRows = defSumRows((double**)arr, max);
            arr[column][row] = arr[column][row] / sumRows;
        }
    }
}

int main(){
    const int speechmax = 2;
    int countWords = 4;
    double** speech;
    double** words;
    speech = new double*[speechmax];
    for (int index = 0; index < speechmax; index++){
        speech[index] = new double[speechmax];
    }
    defArrEntering(speech, 2);    
    defArrShowing(speech, 2);






    for(int index = 0; index < speechmax; index++){
        delete[] speech[index];
    }
    delete[] speech;

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