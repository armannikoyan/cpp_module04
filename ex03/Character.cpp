/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:09:49 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:04:55 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(std::string const& name) : name_(name)
{
  std::cout << "Character Constructor called for: " << this->name_ << std::endl;
  for (int i = 0; i < 4; i++)
    this->inventory_[i] = NULL;
}

Character::~Character()
{
  std::cout << "Character Destructor called for: " << this->name_ << std::endl;
  for (int i = 0; i < 4; i++)
  {
    if (this->inventory_[i])
    {
      delete this->inventory_[i];
      this->inventory_[i] = NULL;
    }
  }
}

Character::Character(Character const& other) : ICharacter(other)
{
  std::cout << "Character Copy Constructor called for: " << other.name_ << std::endl;
  this->name_ = other.name_;
  for (int i = 0; i < 4; i++)
  {
    if (other.inventory_[i])
      this->inventory_[i] = other.inventory_[i]->clone();
    else
      this->inventory_[i] = NULL;
  }
}

Character& Character::operator=(Character const& other)
{
  std::cout << "Character Copy Assignment Operator called for: " << this->name_ << " from " << other.name_ << std::endl;
  if (this != &other)
  {
    ICharacter::operator=(other);

    this->name_ = other.name_;

    for (int i = 0; i < 4; i++)
    {
      if (this->inventory_[i])
      {
        delete this->inventory_[i];
        this->inventory_[i] = NULL;
      }
    }
    for (int i = 0; i < 4; i++)
    {
      if (other.inventory_[i])
        this->inventory_[i] = other.inventory_[i]->clone();
      else
        this->inventory_[i] = NULL;
    }
  }
  return (*this);
}

std::string const& Character::getName() const
{
  return (this->name_);
}

void Character::equip(AMateria* m)
{
  if (!m)
  {
    std::cout << this->name_ << " cannot equip a null Materia." << std::endl;
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    if (!this->inventory_[i])
    {
      this->inventory_[i] = m;
      std::cout << m->getType() << " equipped by " << this->name_ << " in slot " << i << std::endl;
      return;
    }
  }
  std::cout << "Inventory of " << this->name_ << " is full. Cannot equip " << m->getType() << "." << std::endl;
}

void Character::unequip(int idx)
{
  if (idx >= 0 && idx < 4)
  {
    if (this->inventory_[idx])
    {
      std::cout << this->inventory_[idx]->getType() << " unequipped by " << this->name_ << " from slot " << idx << std::endl;
      this->inventory_[idx] = NULL;
    }
    else
    {
      std::cout << this->name_ << " has no Materia in slot " << idx << " to unequip." << std::endl;
    }
  }
  else
  {
    std::cout << "Cannot unequip for " << this->name_ << ", invalid index: " << idx << std::endl;
  }
}

void Character::use(int idx, ICharacter& target)
{
  if (idx >= 0 && idx < 4 && this->inventory_[idx])
  {
    this->inventory_[idx]->use(target);
  }
  else
  {
    std::cout << this->name_ << " cannot use Materia from slot " << idx << ". Invalid index or slot empty." << std::endl;
  }
}
