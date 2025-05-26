/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:36:35 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 15:35:16 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : type_(type)
{
  std::cout << "AMateria Constructor called for type: " << this->type_ << std::endl;
}

AMateria::~AMateria()
{
  std::cout << "AMateria Destructor called for type: " << this->type_ << std::endl;
}

AMateria::AMateria(AMateria const& other)
{
  std::cout << "AMateria Copy Constructor called" << std::endl;
  *this = other;
}

AMateria& AMateria::operator=(AMateria const& other)
{
  std::cout << "AMateria Copy Assignment Operator called" << std::endl;
  if (this != &other)
  {
    this->type_ = other.type_;
  }
  return (*this);
}

std::string const& AMateria::getType() const
{
  return (this->type_);
}
