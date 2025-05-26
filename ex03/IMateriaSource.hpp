/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:39:27 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:05:17 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AMateria;

class IMateriaSource
{
  protected:
    IMateriaSource();
    IMateriaSource(IMateriaSource const& other);
    IMateriaSource& operator=(IMateriaSource const& other);

  public:
    virtual ~IMateriaSource();

    virtual void learnMateria(AMateria* m) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};
