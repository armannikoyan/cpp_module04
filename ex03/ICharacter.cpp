/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:47:28 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:02:28 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter()
{
  std::cout << "ICharacter Default Constructor called" << std::endl;
}

ICharacter::~ICharacter()
{
  std::cout << "ICharacter Destructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const& other)
{
  std::cout << "ICharacter Copy Constructor called" << std::endl;
  (void)other;
}

ICharacter& ICharacter::operator=(ICharacter const& other)
{
  std::cout << "ICharacter Copy Assignment Operator called" << std::endl;
  if (this != &other)
  {
  }
  (void)other;
  return (*this);
}
