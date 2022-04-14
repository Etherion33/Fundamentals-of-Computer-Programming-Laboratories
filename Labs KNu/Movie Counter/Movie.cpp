#include "Movie.h"
#include <cstring>
#include <cstdlib>
#define MAX_STRING_LENGTH 1000

void Movie::set_Title(std::string Title)
{
    std::strcpy(m_Title,Title.c_str());
}
void Movie::set_ProductionYear(unsigned int Year)
{
    m_ProductionYear=Year;
}
void Movie::set_Rating(unsigned int Rate)
{
    m_Rating=Rate;
}
void Movie::show_ALL()
{
    std::cout<<"Title: "<<m_Title<<std::endl;
    std::cout<<"Year: "<<m_ProductionYear<<std::endl;
    std::cout<<"Rating: "<<m_Rating<<std::endl;
}

unsigned int Movie::swap_Rating(unsigned int Rate)
{
    //std::swap(m_Rating,Rate);
    m_Rating^=Rate;
    Rate^=m_Rating;
    Rate^=m_Rating;
    return Rate;
}
Movie::Movie()
{



}
Movie::Movie(char* Title, unsigned int Year, unsigned int Rate)
{
    char * m_Title = new char[MAX_STRING_LENGTH]();
    m_ProductionYear=Year;
    m_Rating=Rate;

}

Movie::~Movie()
{

}

