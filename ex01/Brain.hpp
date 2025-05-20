/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:51:31 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 17:00:26 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain
{
  private:
    std::string ideas_[100];

  public:
    Brain();
    ~Brain();
    Brain(const Brain&);
    Brain& operator=(const Brain&);

    const std::string& getIdea(size_t) const;
    const std::string* getIdeaAddress(size_t) const;
    
    void setIdea(size_t, const std::string&);
};
