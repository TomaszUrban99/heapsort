#include "../inc/titleRatingCollection.hh"


int titleRatingCollection::read(std::string &filename)
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
    char readCharacter;
        while ( readCharacter != '\n'){
            input >> readCharacter;
        }

    /* Read data */
    while (!input.eof())
    {
        /* Check if there is enough space to store records */
        if ( readRecords >=_titleRatingCollection.size() ){
            _titleRatingCollection.resize(_titleRatingCollection.size()+initialSize);
        }

        _titleRatingCollection[readRecords] = new titleRating();
        input >> *_titleRatingCollection[readRecords];

        if (input.fail()){
            std::cerr << "Failed to read data" << std::endl;
            return -1;
        }

        readRecords++;
    }

    return readRecords;
}
