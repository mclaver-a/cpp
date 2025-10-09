#include "Bureaucrat.hpp"
#include <ostream>

Bureaucrat::~Bureaucrat()
{
  return ;
}

Bureaucrat::Bureaucrat()
{
  _grade = 0;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
  _grade = 0;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
  _grade = grade;
}

std::string  Bureaucrat::getName();
{
  return _name;
}

int  Bureaucrat::getGrade();
{
  return _grade;
}

std::ostream & operator << (std::ostream &out, Bureaucrat brc)
{
  out << brc.getName() << " , bureaucrat grade " << brc.getGrade() << std::endl;
  return (out);
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &other)
{
  if (this == &other)
    return (*this);
  _grade = other._grade;
  return (*this);
}

void Bureaucrat::incrementGrade(void)
{
  if (_grade <= MAX_GRADE)
    throw(GradeTooHighException());
  _grade--;
}

void Bureaucrat::decrementGrade(void)
{
  if (_grade >= MIN_GRADE)
    throw(GradeTooLowException());
  _grade++;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
  return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
  return ("Grade too low!");
}

void Bureaucrat::signForm(Form &form)
{
  try
  {
    form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
  }
}
    
