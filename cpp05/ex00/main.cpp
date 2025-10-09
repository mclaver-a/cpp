#include "Bureaucrat.hpp"

int main(void)
{
  try
    {
      Bureaucrat jaume("Jaume", 3);
      std::cout << jaume << std::endl;
      jaume.incrementGrade();
      std::cout << jaume << std::endl;
      jaume.decrementGrade();
      std::cout << jaume << std::endl;
      jaume.decrementGrade();
      std::cout << jaume << std::endl;
      Bureaucrat manel("Manel");
      std::cout << manel << std::endl;
      Bureaucrat nobody;
      std::cout << nobody << std::endl;
      Bureaucrat intern("Fèlix", 150);
      std::cout << intern << std::endl;
      intern.decrementGrade();
      std::cout << intern << std::endl;
    }
  catch (const std::exception &er)
    {
      std::cout << err.what() << std::endl;
    }
  return (0);
}
