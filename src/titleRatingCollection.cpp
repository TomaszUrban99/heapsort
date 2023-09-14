#include "../inc/titleRatingCollection.hh"
#include <cstdio>

int titleRatingCollection::reallocate()
{
    /* Allocate new memory */
    titleRating** tmpPointer = new titleRating*[_vectorSize + initialSize];
    titleRating** pointer;

    for ( int i = 0; i < _vectorSize; ++i ){
        tmpPointer[i] = _titleRatingCollection[i];
    }

    _vectorSize = _vectorSize + initialSize;

    pointer = _titleRatingCollection;
    _titleRatingCollection = tmpPointer;

    delete [] pointer;
    
    return _vectorSize;
}

int titleRatingCollection::read(char *filename)
{
    /* Variable storing number of read records */
    int readRecords = 0;

    /* Create input handle to the file with given filename */
    std::ifstream input ( filename );
    
    if (input.fail()){
        std::cerr << "Failed to open the file";
        return -1;
    }
    
    /* Omit headers */
    char readCharacter = 'o';
        while ( readCharacter != '\n'){
           input.get(readCharacter);
        }

    /* Read data */
    while (!input.eof())
    { 
        /* Check if there is enough space to store records */
        if ( readRecords >=_vectorSize ){ 
            reallocate();     
        }

        _titleRatingCollection[readRecords] = new titleRating (); 
        input >> *_titleRatingCollection[readRecords];

        if (input.fail() && !input.eof()){
            std::cerr << "Failed to read data" << std::endl;
            return -1;
        }
        
        readRecords++;  
    }

    _recordsNumber = _recordsNumber + readRecords;

    return readRecords;
}

void titleRatingCollection::print(std::ostream& outputStream)
{
    for ( int i = 0; i < _recordsNumber; ++i){
        outputStream << *_titleRatingCollection[i] << std::endl;
    }
}
