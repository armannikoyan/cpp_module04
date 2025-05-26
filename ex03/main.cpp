/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:49:23 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/26 16:04:22 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
  std::cout << "--- Creating MateriaSource and learning Materias ---" << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  std::cout << std::endl;

  std::cout << "--- Creating Character 'me' ---" << std::endl;
  ICharacter* me = new Character("me");
  std::cout << std::endl;

  AMateria* tmp;
  AMateria* iceEquippedByMe = NULL;

  std::cout << "--- Equipping 'me' with ice ---" << std::endl;
  iceEquippedByMe = src->createMateria("ice");
  if (iceEquippedByMe)
  {
    me->equip(iceEquippedByMe);
  }
  else
  {
    std::cout << "Failed to create 'ice' Materia for 'me'." << std::endl;
  }
  std::cout << std::endl;

  std::cout << "--- Equipping 'me' with cure ---" << std::endl;
  tmp = src->createMateria("cure");
  if (tmp)
  {
    me->equip(tmp);
  }
  else
  {
    std::cout << "Failed to create 'cure' Materia for 'me'." << std::endl;
  }
  std::cout << std::endl;

  std::cout << "--- Creating Character 'bob' ---" << std::endl;
  ICharacter* bob = new Character("bob");
  std::cout << std::endl;

  std::cout << "--- 'me' using Materias on 'bob' ---" << std::endl;
  me->use(0, *bob);
  me->use(1, *bob);
  std::cout << std::endl;

  std::cout << "--- Testing unequip (slot 0: ice) ---" << std::endl;
  me->unequip(0); 
  std::cout << std::endl;

  std::cout << "--- 'me' trying to use unequipped slot ---" << std::endl;
  me->use(0, *bob);
  std::cout << std::endl;

  std::cout << "--- Testing Character copy and assignment ---" << std::endl;
  Character* charlie = new Character("Charlie");
  tmp = src->createMateria("ice");
  if (tmp)
  {
    charlie->equip(tmp);
  }
  else
  {
    std::cout << "Failed to create 'ice' Materia for 'Charlie'." << std::endl;
  }

  Character delta("Delta"); 
  delta = *charlie;

  Character echo(*charlie);

  std::cout << "Charlie uses slot 0 on Bob:" << std::endl;
  charlie->use(0, *bob);
  std::cout << "Delta uses slot 0 on Bob:" << std::endl;
  delta.use(0, *bob);
  std::cout << "Echo uses slot 0 on Bob:" << std::endl;
  echo.use(0, *bob);
  std::cout << std::endl;


  std::cout << "--- Cleaning up ---" << std::endl;
  delete bob;
  bob = NULL;

  delete me;
  me = NULL;

  delete src;
  src = NULL;

  delete charlie;
  charlie = NULL;

  if (iceEquippedByMe)
  {
    std::cout << "Cleaning up unequipped Ice Materia (iceEquippedByMe): " << iceEquippedByMe->getType() << std::endl;
    delete iceEquippedByMe;
    iceEquippedByMe = NULL;
  }

  std::cout << "--- Main finished ---" << std::endl;
  return 0;
}
