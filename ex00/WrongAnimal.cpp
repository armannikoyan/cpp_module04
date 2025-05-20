/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:55:40 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/15 09:29:42 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("DefaultWrongAnimal")
{
  std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
  std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
  std::cout << "WrongAnimal Copy Constructor called" << std::endl;

  *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
  std::cout << "WrongAnimal Copy Assignment Operator called" << std::endl;

  if (this != &other)
    type_ = other.type_;

  return *this;
}

const std::string& WrongAnimal::getType() const
{
  return type_;
}

void WrongAnimal::makeSound() const
{
  std::cout << "Default WrongAnimal Sound" << std::endl;
}
