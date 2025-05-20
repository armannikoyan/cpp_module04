/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:12:51 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 17:17:20 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
  std::cout << "WrongCat Default Constructor called" << std::endl;
  type_ = "WrongCat";
}

WrongCat::~WrongCat()
{
  std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
  std::cout << "WrongCat Copy Constructor called" << std::endl;
  *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
  std::cout << "WrongCat Copy Assignment Operator called" << std::endl;

  if (this != &other)
  {
    type_ = other.type_;
  }

  return *this;
}

void WrongCat::makeSound() const
{
  std::cout << "Mew!" << std::endl;
}

