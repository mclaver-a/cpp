#ifndef "FORM_HPP"
# define "FORM_HPP"

# include "Bureaucrat.hpp"
# include <iostream>

class Form
{
  private:
    const std::string _name;
    const bool        _is_signed;
    const int         _signGrade;
    const int         _execGrade;
  
  public:
    Form(void);
    Form(const std::string &name, int sign_grade, int exec_grade)
    Form(const Form &other);
    Form & operator=(const Form &other);
    ~Form(void);

    const std::string &getName(void) const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);
    
		class GradeTooHighException : public std::exception
		{
			public:
			const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
			const char *what(void) const throw();
		};

}
std::ostream & operator<<(std::ostream &os, const Form &form);

#endif
