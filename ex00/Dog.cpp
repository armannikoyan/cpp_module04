/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:55:33 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 17:16:32 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
  std::cout << "Dog Default Constructor called" << std::endl;
  type_ = "Dog";
}

Dog::~Dog()
{
  std::cout << "Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
  std::cout << "Dog Copy Constructor called" << std::endl;
  *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
  std::cout << "Dog Copy Assignment Operator called" << std::endl;

  if (this != &other)
  {
    type_ = other.type_;
  }

  return *this;
}

void Dog::makeSound() const
{
  std::cout << "Bark!" << std::endl;
}
