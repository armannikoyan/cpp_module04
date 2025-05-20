/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:52:49 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 18:17:12 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
  protected:
    std::string type_;

  public:
    Animal();
    virtual ~Animal();
    Animal(const Animal&);
    Animal& operator=(const Animal&);

    const std::string& getType() const;

    virtual void makeSound() const = 0;
};
