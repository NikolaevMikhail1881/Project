#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

void defArrEntering(double** arr, int hmax, int wmax)
{
    for (int column = 0; column < hmax; column++) {
        for (int row = 0; row < wmax; row++) {
            std::cin >> arr[column][row];
        }
    }
    std::cout << '\n';
}

void defArrShowing(double** arr, int hmax, int wmax)
{
    for (int column = 0; column < hmax; column++) {
        for (int row = 0; row < wmax; row++) {
            std::cout << arr[column][row] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void PrintAnswer(double** arr, int hmax, int wmax) {
    std::cout << std::fixed << std::setprecision(6);
    for (int column = 0; column < wmax; column++) {
        for (int row = 0; row < hmax; row++) {
            std::cout << arr[row][column] << std::setw(10);
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

double defSumRows(double** arr, int max, int colum) {
    double result = 0;
    for (int row = 0; row < max; row++) {
        result = result + arr[colum][row];
    }
    return result;
}

double defMultiplyCols(double** arr, double** arr_2, int hmax, int row) {
    double result = 0;
    for (int column = 0; column < hmax; column++) {
        result = result + arr[column][row] * arr_2[column][row];
        // std::cout << arr[column][row] << '*' << arr_2[column][row] << '\n';
        // std::cout << result << ' ';
    }
    return result;
}

void defSecondPos(double** arr, int hmax, int wmax) {
    int sumRows = 0;
    for (int column = 0; column < hmax; column++) {
        sumRows = defSumRows(arr, wmax, column);
        for (int row = 0; row < wmax; row++) {
            arr[column][row] = arr[column][row] / sumRows;
        }
    }
}




double Max(std::vector<double> row) {
    double max = 0;
    for (int i = 0; i < row.size(); i++) {
        if (row[i] > max) {
            max = row[i];
        }
    }
    return max;
}

void defViterbi(double** speech, double** words, int hmax, int wmax) {
    double** temp;
    temp = new double* [hmax];
    for (int i = 0; i < wmax; i++) {
        temp[i] = new double[wmax];
    }
    for (int i = 0; i < hmax; i++) {
        for (int j = 0; j < wmax; j++) {
            if (i == 0) {
                temp[i][j] = words[i][j];
            }
            else {
                temp[i][j] = 0;
            }
        }
    }
    std::vector<double> row;
    int counter = 0;
    for (int i = 1; i < hmax; i++) {
        for (int j = 0; j < wmax; j++) {
            if (i != 1) {
                counter = i;
            }
            if (i == 4) {
                counter = 2;
            }
            double max = 0;
            for (int k = 0; k < wmax; k++) {
                row.push_back(temp[i - 1][k] * words[i][j] * speech[k][counter]);
            }
            temp[i][j] = Max(row);
            row.clear();
        }
    }

    for (int i = 0; i < hmax; i++) {
        for (int j = 0; j < wmax; j++) {
            words[i][j] = temp[i][j];
        }
    }
}


int main() {
    int const speechmax = 10;
    int countWords = 0;
    std::cout << "Enter width of Words array: ";
    std::cin >> countWords;
    double** speech;
    double** words;
    speech = new double* [speechmax];
    for (int index = 0; index < speechmax; index++) {
        speech[index] = new double[speechmax];
    }
    words = new double* [countWords];
    for (int index = 0; index < speechmax; index++) {
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
    std::cout << "Enter speech array (1 2 3...): " << '\n';
    defArrEntering(speech, speechmax, speechmax);
    std::cout << "Your's speech array: " << '\n';
    defArrShowing(speech, speechmax, speechmax);
    std::cout << "Enter words array (1 2 3...): " << '\n';
    defArrEntering(words, countWords, speechmax);
    std::cout << '\n';
    std::cout << "Your's speech array: " << '\n';
    defArrShowing(words, countWords, speechmax);
    defSecondPos(speech, speechmax, speechmax);
    std::cout << "Second pos of array SPEACH: " << '\n';
    defArrShowing(speech, speechmax, speechmax);
    defSecondPos(words, countWords, speechmax);
    std::cout << "Second pos of array WORDS: " << '\n';
    defArrShowing(words, countWords, speechmax);


    defViterbi(speech, words, countWords, speechmax);

    std::cout << '\n';
    std::cout << "Your's array WORDS after: " << '\n';
    PrintAnswer(words, countWords, speechmax);

    for (int index = 0; index < speechmax; index++) {
        delete[] speech[index];
    }
    delete[] speech;

    for (int index = 0; index < speechmax; index++) {
        delete[] words[index];
    }
    delete[] words;
}