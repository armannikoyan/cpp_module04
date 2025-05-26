/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:02:18 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 19:20:42 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
  std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::~Brain()
{
  std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
  std::cout << "Brain Copy Constructor called" << std::endl;
  *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
  std::cout << "Brain Copy Assignment Operator called" << std::endl;
  if (this != &other)
  {
    for (size_t i = 0; i < 100; ++i)
    {
      if (other.ideas_[i].length() > 0)
          ideas_[i] = other.ideas_[i];
    }
  }
  return *this;
}

const std::string& Brain::getIdea(const size_t i) const
{
  if (i > 99)
    throw std::runtime_error("There is only 100 ideas per brain => max index is 99.");
  return ideas_[i];
}

const std::string* Brain::getIdeaAddress(const size_t i) const
{
  if (i > 99)
    throw std::runtime_error("There is only 100 ideas per brain => max index is 99.");
  return &ideas_[i];
}

void Brain::setIdea(const size_t i, const std::string& idea)
{
  if (i > 99)
    throw std::runtime_error("There is only 100 ideas per brain => max index is 99.");
  ideas_[i] = idea;
}
