/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:12:51 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 17:17:02 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
  std::cout << "Cat Default Constructor called" << std::endl;
  type_ = "Cat";
}

Cat::~Cat()
{
  std::cout << "Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
  std::cout << "Cat Copy Constructor called" << std::endl;
  *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
  std::cout << "Cat Copy Assignment Operator called" << std::endl;

  if (this != &other)
  {
    type_ = other.type_;
  }

  return *this;
}

void Cat::makeSound() const
{
  std::cout << "Mew!" << std::endl;
}

