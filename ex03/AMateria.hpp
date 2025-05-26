/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:32:48 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:01:35 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
  protected:
    std::string type_;

  public:
    AMateria(std::string const& type);
    virtual ~AMateria();
    AMateria(AMateria const& other);
    AMateria& operator=(AMateria const& other);

    std::string const& getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;
};
