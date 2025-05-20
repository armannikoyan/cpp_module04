/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:12:20 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 16:54:12 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
