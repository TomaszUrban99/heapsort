#include <iostream>

#include "../inc/titleRatingCollection.hh"

int main(int argc, char* argv[])
{
    titleRatingCollection newCollection;

    newCollection.read(argv[1]);

    newCollection.print(std::cout);
    
    return 0;
}