/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:53:53 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:02:01 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
  public:
    Cure();
    virtual ~Cure();
    Cure(Cure const& other);
    Cure& operator=(Cure const& other);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};
