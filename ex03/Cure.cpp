/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:55:49 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:02:06 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
  std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::~Cure()
{
  std::cout << "Cure Destructor called" << std::endl;
}

Cure::Cure(Cure const& other) : AMateria(other)
{
  std::cout << "Cure Copy Constructor called" << std::endl;
}

Cure& Cure::operator=(Cure const& other)
{
  std::cout << "Cure Copy Assignment Operator called" << std::endl;
  if (this != &other)
  {
    AMateria::operator=(other);
  }
  return (*this);
}

AMateria* Cure::clone() const
{
  std::cout << "Cure clone() called" << std::endl;
  return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
