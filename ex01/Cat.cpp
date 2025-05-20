/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:12:51 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 18:13:25 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
  std::cout << "Cat Default Constructor called" << std::endl;
  type_ = "Cat";
  brain_ = new Brain();
  if (brain_ == NULL)
  {
    perror("Cat Brain allocation failed");
    std::cerr << "Exiting the process now." << std::endl;
    exit(1);
  }
}

Cat::~Cat()
{
  std::cout << "Cat Destructor called" << std::endl;
  delete(brain_);
}

Cat::Cat(const Cat& other) : Animal(other)
{
  std::cout << "Cat Copy Constructor called" << std::endl;
  type_ = other.type_;
  brain_ = new Brain(*other.brain_);
}

Cat& Cat::operator=(const Cat& other)
{
  std::cout << "Cat Copy Assignment Operator called" << std::endl;
  if (this != &other) 
  {
    Animal::operator=(other);
    type_ = other.type_;
    delete brain_;
    brain_ = new Brain(*other.brain_);
  }
  return *this;
}

void	Cat::getIdeas() const
{
	for (size_t i = 0; i < 100; ++i)
		std::cout << "\tIdea " << i << " of the Cat is: \"" << brain_->getIdea(i) << "\" at the address " << brain_->getIdeaAddress(i) << std::endl;
}

void	Cat::setIdea(size_t i, std::string idea)
{
		brain_->setIdea(i, idea);
}

void Cat::makeSound() const
{
  std::cout << "Mew!" << std::endl;
}

