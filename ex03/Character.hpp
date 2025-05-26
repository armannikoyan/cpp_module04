/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:07:18 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:04:49 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
  private:
    std::string name_;
    AMateria* inventory_[4];

  public:
    Character(std::string const& name);
    virtual ~Character();
    Character(Character const& other);
    Character& operator=(Character const& other);

    virtual std::string const& getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};
