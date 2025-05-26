/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:49:55 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:05:03 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
  public:
    Ice();
    virtual ~Ice();
    Ice(Ice const& other);
    Ice& operator=(Ice const& other);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};
