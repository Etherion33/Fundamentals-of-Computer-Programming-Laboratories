#ifndef __LIBRARY_H_
#define __LIBRARY_H_
#define MAX_NO_MOVIES 100
#include "Movie.h"

class Library{
public:
        Library();
        ~Library();
        Insert_to_Library(int,char*, unsigned int, unsigned int);
        Show_Library();
        Movie * Pop();
        bool Push(Movie* movie);
        bool IsFull() const;
        Library & operator=(const Library & element);
private:
    Movie* m_arrayOfMovies;
    unsigned int m_count;
};

#endif // __LIBRARY_H_
