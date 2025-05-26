/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:50:54 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 15:38:43 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
  std::cout << "Ice Default Constructor called" << std::endl;
}

Ice::~Ice()
{
  std::cout << "Ice Destructor called" << std::endl;
}

Ice::Ice(Ice const& other) : AMateria(other)
{
  std::cout << "Ice Copy Constructor called" << std::endl;
}

Ice& Ice::operator=(Ice const& other)
{
  std::cout << "Ice Copy Assignment Operator called" << std::endl;
  if (this != &other)
  {
    AMateria::operator=(other);
  }
  return (*this);
}

AMateria* Ice::clone() const
{
  std::cout << "Ice clone() called" << std::endl;
  return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
  std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
