#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class  Bureaucrat
{
  private:
    const std::string  _name;
    int                _grade;
  public:
    Bureaucrat(),
    Bureaucrat(std::string name);
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();

    Bureaucrat & operator = (const Bureaucrat &src);
    
    std::string  getName(void) const;
    int          getGrade(void) const;

    void         incrementGrade(void);
    void         decrementGrade(void);
    void         signForm(Form &form);

    class  GradeTooHighException : public std::exception
    {
      public:
        const char *what(void) const throw();
    };
    class  GradeTooLowException : public std::exception
    {
      public:
        const char *what(void) const throw();
    };
};

std::ostream & operator << (std::ostream &out, Bureaucrat brc);
#endif
