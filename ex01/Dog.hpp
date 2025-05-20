/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:02:45 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 16:54:27 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
    Brain* brain_;

  public:
    Dog();
    ~Dog();
    Dog(const Dog&);
    Dog& operator=(const Dog&);

    void getIdeas() const;

		void setIdea(size_t i, std::string idea);

    void makeSound() const;
};
