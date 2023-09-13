#include "../inc/titleRating.hh"

std::istream& operator>>( std::istream& input, titleRating& newRecord )
{
    input >> newRecord.get_tconst();
    input >> newRecord.get_averageRating();
    input >> newRecord.get_numVotes();
    
    return input;
}