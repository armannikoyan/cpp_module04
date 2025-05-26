/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:12:20 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:16:17 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  private:
    Brain* brain_;

  public:
    Cat();
    ~Cat();
    Cat(const Cat&);
    Cat& operator=(const Cat&);

    void getIdeas() const;

		void setIdea(size_t i, std::string idea);

    void makeSound() const;
};
