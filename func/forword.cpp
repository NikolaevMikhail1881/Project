// Welcome to the piece of code 
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

std::string defArrShowing(double** arr, int hmax, int wmax)
{  
    std::string res = "";
    for (int column = 0; column < hmax; column++){
        for (int row = 0; row < wmax; row++){
            res = res + arr[column][row] + ' ';
        }
        res=res+ '\n';
    }
    res=res+ '\n';
    std::cout << res;
    return res;
}

double defSumRows(double** arr, int max, int colum){
    double result = 0;
    for (int row = 0; row < max; row++){
        result = result + arr[colum][row];
    }
    return result;
}

double defMultiplyCols(double** arr, double** arr_2, int hmax, int row){
    double result = 0;
    for (int column = 0; column < hmax; column++){
        result = result + arr[column][row] * arr_2[column][row];
        // std::cout << arr[column][row] << '*' << arr_2[column][row] << '\n';
        // std::cout << result << ' ';
    }
    return result;
}

void defSecondPos(double** arr, int hmax, int wmax){
    int sumRows = 0;
    for (int column = 0; column < hmax; column++){
        sumRows = defSumRows(arr, wmax, column);
        for (int row = 0; row < wmax; row++){   
            arr[column][row] = arr[column][row] / sumRows;
        }
    }
}




void defForword(double** speech, double** words, int hmax, int wmax){
    double sum = 0;
    for(int row = 0; row < wmax; row++){
        sum = defMultiplyCols(speech, words, hmax, row);
        for (int column = 0; column < hmax; column++){
            words[column][row] = words[column][row] * sum;
        }
    }
    std::cout << '\n';
}
//forward[i][j+1] = summa{k=0, num of chasti rechi} (forward[k][j]*speech[k,i]*words[j+1][i])
//forward[i][j+1] = max{k=0, num of chasti rechi} (forward[k][j]*speech[k,i]*words[j+1][i])
//speech[chast_rechi_prew][chast_rechi_next]
//words[word][chast_rechi]

int main(){
    int const speechmax = 9;
    int countWords = 0;
    std::cout << "Enter width of Words array: ";
    std::cin >> countWords;
    double** speech;
    double** words;
    speech = new double*[speechmax];
    for (int index = 0; index < speechmax; index++){
        speech[index] = new double[speechmax];
    }
    words = new double*[countWords];
    for (int index = 0; index < speechmax; index++){
        words[index] = new double[speechmax];
    }
    
/*  std::cout<< "Enter speech array (1 2 3...): ";
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
    defForword(speech, words, countWords, speechmax);
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




