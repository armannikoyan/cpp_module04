/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:55:33 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 18:13:33 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
  std::cout << "Dog Default Constructor called" << std::endl;
  type_ = "Dog";
  brain_ = new Brain();
  if (brain_ == NULL)
  {
    perror("Dog Brain allocation failed");
    std::cerr << "Exiting the process now." << std::endl;
    exit(1);
  }
}

Dog::~Dog()
{
  std::cout << "Dog Destructor called" << std::endl;
  delete(brain_);
}

Dog::Dog(const Dog& other) : Animal(other)
{
  std::cout << "Dog Copy Constructor called" << std::endl;
  type_ = other.type_;
  brain_ = new Brain(*other.brain_);
}

Dog& Dog::operator=(const Dog& other)
{
  std::cout << "Dog Copy Assignment Operator called" << std::endl;
  if (this != &other) 
  {
    Animal::operator=(other);
    type_ = other.type_;
    delete brain_;
    brain_ = new Brain(*other.brain_);
  }
  return *this;
}

void	Dog::getIdeas() const
{
	for (size_t i = 0; i < 100; ++i)
		std::cout << "\tIdea " << i << " of the Dog is: \"" << brain_->getIdea(i) << "\" at the address " << brain_->getIdeaAddress(i) << std::endl;
}

void	Dog::setIdea(size_t i, std::string idea)
{
		brain_->setIdea(i, idea);
}


void Dog::makeSound() const
{
  std::cout << "Woof!" << std::endl;
}
