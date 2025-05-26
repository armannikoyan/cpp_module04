/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:39:49 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:02:22 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AMateria;

class ICharacter
{
  protected:
    ICharacter();
    ICharacter(ICharacter const& other);
    ICharacter& operator=(ICharacter const& other);

  public:
    virtual ~ICharacter();

    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
