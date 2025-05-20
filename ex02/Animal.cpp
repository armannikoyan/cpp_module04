/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:55:40 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 18:16:50 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type_("DefaultAnimal")
{
  std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::~Animal()
{
  std::cout << "Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
  std::cout << "Animal Copy Constructor called" << std::endl;

  *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
  std::cout << "Animal Copy Assignment Operator called" << std::endl;

  if (this != &other)
    type_ = other.type_;

  return *this;
}

const std::string& Animal::getType() const
{
  return type_;
}

void Animal::makeSound() const
{
}
