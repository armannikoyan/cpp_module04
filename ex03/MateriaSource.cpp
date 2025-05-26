/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:44:51 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:05:35 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() : count_(0)
{
  std::cout << "MateriaSource Constructor called" << std::endl;
  for (int i = 0; i < 4; i++)
    this->learned_materias_[i] = NULL;
}

MateriaSource::~MateriaSource()
{
  std::cout << "MateriaSource Destructor called" << std::endl;
  for (int i = 0; i < this->count_; i++)
  {
    if (this->learned_materias_[i])
    {
      delete this->learned_materias_[i];
      this->learned_materias_[i] = NULL;
    }
  }
}

MateriaSource::MateriaSource(MateriaSource const& other) : IMateriaSource(other), count_(other.count_)
{
  std::cout << "MateriaSource Copy Constructor called" << std::endl;
  for (int i = 0; i < 4; i++)
    this->learned_materias_[i] = NULL;

  for (int i = 0; i < other.count_; i++)
  {
    if (other.learned_materias_[i])
      this->learned_materias_[i] = other.learned_materias_[i]->clone();
  }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other)
{
  std::cout << "MateriaSource Copy Assignment Operator called" << std::endl;
  if (this != &other)
  {
    IMateriaSource::operator=(other);

    for (int i = 0; i < this->count_; i++)
    {
      if (this->learned_materias_[i])
      {
        delete this->learned_materias_[i];
        this->learned_materias_[i] = NULL;
      }
    }
    this->count_ = 0;

    for (int i = 0; i < other.count_; i++)
    {
      if (other.learned_materias_[i])
      {
        this->learned_materias_[i] = other.learned_materias_[i]->clone();
      }
    }
    this->count_ = other.count_;

    for (int i = this->count_; i < 4; ++i) {
      this->learned_materias_[i] = NULL;
    }
  }
  return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
  if (!m)
  {
    std::cout << "MateriaSource cannot learn a null Materia." << std::endl;
    return;
  }
  if (this->count_ < 4)
  {
    for (int i = 0; i < this->count_; ++i) {
      if (this->learned_materias_[i]->getType() == m->getType()) {
        std::cout << "MateriaSource already learned " << m->getType() << "." << std::endl;
        delete m;
        return;
      }
    }
    this->learned_materias_[this->count_] = m;
    std::cout << "MateriaSource learned " << m->getType() << " in slot " << this->count_ << std::endl;
    this->count_++;
  }
  else
  {
    std::cout << "MateriaSource cannot learn more Materias (inventory full). Materia " << m->getType() << " not learned." << std::endl;
    delete m;
  }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
  for (int i = 0; i < this->count_; i++)
  {
    if (this->learned_materias_[i] && this->learned_materias_[i]->getType() == type)
    {
      std::cout << "MateriaSource created a new " << type << " Materia." << std::endl;
      return (this->learned_materias_[i]->clone());
    }
  }
  std::cout << "MateriaSource does not know type " << type << ". Cannot create." << std::endl;
  return (NULL);
}
