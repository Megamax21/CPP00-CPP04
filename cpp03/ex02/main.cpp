/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:33:33 by ml-hote           #+#    #+#             */
/*   Updated: 2026/03/27 01:40:57 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void	printSection(const std::string& title)
{
	std::cout << "\n========== " << title << " ==========" << std::endl;
}

int	main(void)
{
	printSection("1. CREATE ALL THREE CLASSES");
	ClapTrap base("ClapTrap");
	ScavTrap scav("ScavTrap");
	FragTrap frag("FragTrap");
	std::cout << "Base: 10 HP, 10 EP, 0 ATK" << std::endl;
	std::cout << "Scav: 100 HP, 50 EP, 20 ATK" << std::endl;
	std::cout << "Frag: 100 HP, 100 EP, 30 ATK" << std::endl;

	printSection("2. CLAPTRAP - BASE CLASS ACTIONS");
	base.attack("enemy");
	base.takeDamage(3);
	base.beRepaired(2);

	printSection("3. SCAVTRAP - INHERITED + SPECIALIZED");
	scav.attack("target");
	scav.attack("target");
	scav.takeDamage(10);
	scav.beRepaired(5);
	scav.guardGate();
	scav.guardGate();

	printSection("4. FRAGTRAP - INHERITED + SPECIALIZED");
	frag.attack("opponent");
	frag.attack("opponent");
	frag.takeDamage(15);
	frag.beRepaired(10);
	frag.highFivesGuys();
	frag.highFivesGuys();

	printSection("5. SCAVTRAP - DEPLETE ENERGY");
	ScavTrap energy_test("Scav_Energy");
	for (int i = 0; i < 51; i++)
	{
		if (i % 10 == 0)
			std::cout << "After " << i << " repairs:" << std::endl;
		energy_test.beRepaired(1);
	}

	printSection("6. FRAGTRAP - DEPLETE ENERGY");
	FragTrap frag_energy("Frag_Energy");
	for (int i = 0; i < 101; i++)
	{
		if (i % 25 == 0)
			std::cout << "After " << i << " repairs:" << std::endl;
		frag_energy.beRepaired(1);
	}

	printSection("7. SCAVTRAP - DAMAGE AND GUARDIAN MODE");
	ScavTrap guardian("Guardian");
	guardian.takeDamage(50);
	guardian.takeDamage(30);
	guardian.takeDamage(25);	// Should break
	guardian.guardGate();		// Should still work even if broken
	guardian.attack("intruder");

	printSection("8. FRAGTRAP - DAMAGE AND HIGH FIVES");
	FragTrap high_fiver("HighFiver");
	high_fiver.takeDamage(30);
	high_fiver.takeDamage(40);
	high_fiver.takeDamage(35);	// Should break
	high_fiver.highFivesGuys();	// Should still work even if broken
	high_fiver.attack("enemy");

	printSection("9. COPY OPERATIONS ON DERIVED CLASSES");
	ScavTrap s_original("S_Original");
	ScavTrap s_copy = s_original;	// Copy constructor
	s_copy = s_original;			// Copy assignment

	FragTrap f_original("F_Original");
	FragTrap f_copy = f_original;	// Copy constructor
	f_copy = f_original;			// Copy assignment

	printSection("10. POLYMORPHIC TEST WITH POINTERS");
	std::cout << "Testing base class pointers:" << std::endl;
	ClapTrap* ptr1 = &base;
	ClapTrap* ptr2 = &scav;
	ClapTrap* ptr3 = &frag;

	ptr1->attack("via_base");
	ptr2->attack("via_base");
	ptr3->attack("via_base");

	ptr1->takeDamage(2);
	ptr2->takeDamage(5);
	ptr3->takeDamage(10);

	printSection("11. MIXED SCENARIO - ALL CLASSES ACTIVE");
	ClapTrap fighter1("ClapBot");
	ScavTrap fighter2("GuardBot");
	FragTrap fighter3("FireBot");

	for (int round = 1; round <= 3; round++)
	{
		std::cout << "\n--- Round " << round << " ---" << std::endl;
		fighter1.attack("monsters");
		fighter2.attack("monsters");
		fighter3.attack("monsters");

		fighter1.takeDamage(2);
		fighter2.takeDamage(5);
		fighter3.takeDamage(8);

		if (round == 2)
		{
			fighter2.guardGate();
			fighter3.highFivesGuys();
		}
	}

	printSection("12. DESTRUCTION ORDER TEST");
	std::cout << "About to exit scope - watch destructor order:" << std::endl;
	{
		ClapTrap temp_clap("TempClap");
		ScavTrap temp_scav("TempScav");
		FragTrap temp_frag("TempFrag");
	}
	std::cout << "All temporary objects destroyed" << std::endl;

	std::cout << "\n========== FINAL CLEANUP ==========" << std::endl;
	return (0);
}
