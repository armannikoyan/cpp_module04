/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:43:36 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:05:40 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
  private:
    AMateria* learned_materias_[4];
    int count_;

  public:
    MateriaSource();
    virtual ~MateriaSource();
    MateriaSource(MateriaSource const& other);
    MateriaSource& operator=(MateriaSource const& other);

    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const& type);
};
