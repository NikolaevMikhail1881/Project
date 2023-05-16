#include <iostream>


void defArrEntering(int** arr, int max)
{    
    for (int column = 0; column < max; column++){
        for (int row = 0; row < max; row++){
            std::cin >> arr[column][row];
        }
    }
}

void defArrShowing(int** arr, int max)
{    
    for (int column = 0; column < max; column++){
        for (int row = 0; row < max; row++){
            std::cout << arr[column][row];
        }
    }
}

int defSumRows(int** arr, int max){
    int result;
    for (int row = 0; row < max; row++){
        result = result + arr[0][row];
    }
    return result;
}

void defSecondPos(int** arr, int max){
    for (int column = 0; column < max; column++){
        for (int row = 0; row < max; row++){
            int sumRows = defSumRows((int**)arr, max);
            arr[column][row] = arr[column][row] / sumRows;
        }
    }
}

int main(){
    const int speechmax = 10;
    int countWords = 4;
    int speech[speechmax][speechmax];
    int words[countWords][speechmax];
    int test[2][2]{1, 2, 3, 4};
    std::cout << "hello world";
    // defArrEntering((int **)speech, speechmax);
    // defArrEntering((int **)words, countWords);
    defArrShowing((int**)test, 2);
    std::cout << "hello world";
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