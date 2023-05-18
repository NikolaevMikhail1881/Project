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

