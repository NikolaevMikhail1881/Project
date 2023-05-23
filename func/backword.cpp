#include <iostream>


void defArrEntering(double** arr, int hmax, int wmax)
{    
    for (int column = 0; column < hmax; column++){
        for (int row = 0; row < wmax; row++){
            std::cin >> arr[column][row];
        }
    }
    std::cout << '\n';
}

void defArrShowing(double** arr, int hmax, int wmax)
{    
    for (int column = 0; column < hmax; column++){
        for (int row = 0; row < wmax; row++){
            std::cout << arr[column][row] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int defSumRows(double** arr, int max, int colum){
    int result = 0;
    for (int row = 0; row < max; row++){
        result = result + arr[colum][row];
    }
    return result;
}

void defSecondPos(double** arr, int hmax, int wmax){
    int sumRows;
    for (int column = 0; column < hmax; column++){
        sumRows = defSumRows((double**)arr, wmax, column);
        for (int row = 0; row < wmax; row++){   
            arr[column][row] = arr[column][row] / sumRows;
        }
    }
}

void defBackward(double** speech, double** words, int hmax, int wmax){
    double sum = 0;
    double result = 0;
    for(int row = wmax; row > 0; row--){
        for (int column = hmax; column > 0; column--){
            sum = sum + words[column][row] * speech[column][row];
            words[column][row] = words[column][row] * sum;
            std::cout << sum << ' ';
        }
    }
    std::cout << '\n';
    
}



int main(){
    int const speechmax = 10;
    int countWords = 0;
    std::cout << "Enter width of Words array: ";
    std::cin >> countWords;
    double** speech;
    double** words;
    speech = new double*[speechmax];
    for (int index = 0; index < speechmax; index++){
        speech[index] = new double[speechmax];
    }
    words = new double*[speechmax];
    for (int index = 0; index < speechmax; index++){
        words[index] = new double[countWords];
    }
    
/*    std::cout<< "Enter speech array (1 2 3...): ";
    defArrEntering(words, countWords, speechmax);
    std::cout << "\n";
    defArrShowing(words, countWords, speechmax);
    defSecondPos(words, countWords, speechmax);
    std::cout << "\n";
    defArrShowing(words, countWords, speechmax);
*/



    std::cout<< "Enter speech array (1 2 3...): " << '\n';
    defArrEntering(speech, speechmax, speechmax);
    std::cout << "Your's speech array: " <<'\n';    
    defArrShowing(speech, speechmax, speechmax);
    std::cout<< "Enter words array (1 2 3...): "<< '\n';
    defArrEntering(words, countWords, speechmax);
    std::cout << '\n';
    std::cout << "Your's speech array: " <<'\n';  
    defArrShowing(words, countWords, speechmax);
    defSecondPos(speech, speechmax, speechmax);
    std::cout << "Second pos of array SPEACH: "<< '\n';
    defArrShowing(speech, speechmax, speechmax);
    defSecondPos(words, countWords, speechmax); 
    std::cout << "Second pos of array WORDS: "<< '\n';
    defArrShowing(words, countWords, speechmax);
    defBackward(speech, words, speechmax, countWords);
    std::cout << '\n';
    std::cout << "Your's array WORDS after: "<<'\n';
    defArrShowing(words, countWords, speechmax);
    
    




    for(int index = 0; index < speechmax; index++){
        delete[] speech[index];
    }
    delete[] speech;

    for(int index = 0; index < speechmax; index++){
        delete[] words[index];
    }
    delete[] words;
}