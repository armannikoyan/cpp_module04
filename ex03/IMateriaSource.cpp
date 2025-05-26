/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:37 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:05:23 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

IMateriaSource::IMateriaSource()
{
  std::cout << "IMateriaSource Default Constructor called" << std::endl;
}

IMateriaSource::~IMateriaSource()
{
  std::cout << "IMateriaSource Destructor called" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const& other)
{
  std::cout << "IMateriaSource Copy Constructor called" << std::endl;
  (void)other;
}

IMateriaSource& IMateriaSource::operator=(IMateriaSource const& other)
{
  std::cout << "IMateriaSource Copy Assignment Operator called" << std::endl;
  (void)other;
  return (*this);
}
