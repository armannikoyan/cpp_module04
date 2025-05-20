/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 08:52:31 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/20 18:19:56 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cassert>
#include <string>
#include "Dog.hpp"
#include "Cat.hpp"

static std::string captureDogIdeas(Dog& d)
{
  std::ostringstream oss;
  std::streambuf* oldBuf = std::cout.rdbuf(oss.rdbuf());
  d.getIdeas();
  std::cout.rdbuf(oldBuf);
  return oss.str();
}

static std::string captureCatIdeas(Cat& c)
{
  std::ostringstream oss;
  std::streambuf* oldBuf = std::cout.rdbuf(oss.rdbuf());
  c.getIdeas();
  std::cout.rdbuf(oldBuf);
  return oss.str();
}

int main()
{
  {
    std::cout << "===== STARTING Subject Tests =====\n\n";

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "===== ENDING Subject Tests =====\n\n";
  }
  {
    std::cout << "===== STARTING Dog Tests =====\n\n";

    Dog d1;
    std::cout << "[Test] d1.makeSound() → ";
    d1.makeSound();
    std::cout << "\n\n";

    d1.setIdea(0, "Chase cat");
    d1.setIdea(42, "Dig hole");
    std::string d1_all_ideas = captureDogIdeas(d1);
    assert(d1_all_ideas.find("Chase cat") != std::string::npos);
    assert(d1_all_ideas.find("Dig hole") != std::string::npos);
    std::cout << "[Pass] d1.getIdeas() contains both \"Chase cat\" and \"Dig hole\"\n\n";

    Dog d2(d1);
    std::cout << "[Info] After Dog d2(d1), d2.getIdeas() output:\n";
    std::cout << "-----\n";
    std::cout << captureDogIdeas(d2);
    std::cout << "-----\n";
    std::string d2_initial_ideas = captureDogIdeas(d2);
    assert(d2_initial_ideas.find("Chase cat") != std::string::npos);
    assert(d2_initial_ideas.find("Dig hole") != std::string::npos);
    std::cout << "[Pass] d2 initially has the same ideas as d1\n\n";

    d2.setIdea(0, "Bark at mailman");
    std::string d2_after_mod = captureDogIdeas(d2);
    std::string d1_after_d2_mod = captureDogIdeas(d1);
    assert(d2_after_mod.find("Bark at mailman") != std::string::npos);
    assert(d1_after_d2_mod.find("Chase cat") != std::string::npos);
    assert(d1_after_d2_mod.find("Bark at mailman") == std::string::npos);
    std::cout << "[Pass] Changing d2’s idea does NOT affect d1 (deep‐copy confirmed)\n\n";

    Dog d3;
    d3.setIdea(0, "Initial idea");
    d3 = d1;
    std::string d3_initial = captureDogIdeas(d3);
    assert(d3_initial.find("Chase cat") != std::string::npos);
    assert(d3_initial.find("Dig hole") != std::string::npos);
    std::cout << "[Pass] After d3 = d1, d3 has the same ideas as d1\n\n";

    d3.setIdea(42, "Sleep on couch");
    std::string d3_after_mod = captureDogIdeas(d3);
    std::string d1_after_d3_mod = captureDogIdeas(d1);
    assert(d3_after_mod.find("Sleep on couch") != std::string::npos);
    assert(d1_after_d3_mod.find("Dig hole") != std::string::npos);
    assert(d1_after_d3_mod.find("Sleep on couch") == std::string::npos);
    std::cout << "[Pass] Changing d3’s idea does NOT affect d1 (deep‐copy confirmed)\n\n";

    std::cout << "===== Dog Tests Complete =====\n\n";
    std::cout << "===== STARTING Cat Tests =====\n\n";

    Cat c1;
    std::cout << "[Test] c1.makeSound() → ";
    c1.makeSound();
    std::cout << "\n\n";

    c1.setIdea(1, "Climb tree");
    c1.setIdea(99, "Nap in sun");
    std::string c1_ideas = captureCatIdeas(c1);
    assert(c1_ideas.find("Climb tree") != std::string::npos);
    assert(c1_ideas.find("Nap in sun") != std::string::npos);
    std::cout << "[Pass] c1.getIdeas() contains both \"Climb tree\" and \"Nap in sun\"\n\n";

    Cat c2(c1);
    std::cout << "[Info] After Cat c2(c1), c2.getIdeas() output:\n";
    std::cout << "-----\n";
    std::cout << captureCatIdeas(c2);
    std::cout << "-----\n";
    std::string c2_initial = captureCatIdeas(c2);
    assert(c2_initial.find("Climb tree") != std::string::npos);
    assert(c2_initial.find("Nap in sun") != std::string::npos);
    std::cout << "[Pass] c2 initially has the same ideas as c1\n\n";

    c2.setIdea(1, "Pounce mouse");
    std::string c2_after_mod = captureCatIdeas(c2);
    std::string c1_after_c2_mod = captureCatIdeas(c1);
    assert(c2_after_mod.find("Pounce mouse") != std::string::npos);
    assert(c1_after_c2_mod.find("Climb tree") != std::string::npos);
    assert(c1_after_c2_mod.find("Pounce mouse") == std::string::npos);
    std::cout << "[Pass] Changing c2’s idea does NOT affect c1 (deep‐copy confirmed)\n\n";

    Cat c3;
    c3.setIdea(1, "Initial cat idea");
    c3 = c1;
    std::string c3_initial = captureCatIdeas(c3);
    assert(c3_initial.find("Climb tree") != std::string::npos);
    assert(c3_initial.find("Nap in sun") != std::string::npos);
    std::cout << "[Pass] After c3 = c1, c3 has the same ideas as c1\n\n";

    c3.setIdea(99, "Knock over lamp");
    std::string c3_after_mod = captureCatIdeas(c3);
    std::string c1_after_c3_mod = captureCatIdeas(c1);
    assert(c3_after_mod.find("Knock over lamp") != std::string::npos);
    assert(c1_after_c3_mod.find("Nap in sun") != std::string::npos);
    assert(c1_after_c3_mod.find("Knock over lamp") == std::string::npos);
    std::cout << "[Pass] Changing c3’s idea does NOT affect c1 (deep‐copy confirmed)\n\n";

    std::cout << "===== Cat Tests Complete =====\n\n";
    std::cout << "All tests passed successfully. Destructors will now run as program exits.\n";
  }
  // {
  //   Animal a = new Animal();
  // }
  return 0;
}
