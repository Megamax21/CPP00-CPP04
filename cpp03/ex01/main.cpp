/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:33:33 by ml-hote           #+#    #+#             */
/*   Updated: 2026/03/27 01:15:53 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void	printSection(const std::string& title)
{
	std::cout << "\n========== " << title << " ==========" << std::endl;
}

int	main(void)
{
	printSection("1. CLAPTRAP CREATION");
	ClapTrap clap1("ClapTrap_Base");
	std::cout << "Initial stats: 10 HP, 10 EP, 0 ATK" << std::endl;

	printSection("2. SCAVTRAP CREATION");
	ScavTrap scav1("ScavTrap_Unit");
	std::cout << "Initial stats: 100 HP, 50 EP, 20 ATK (overridden in constructor)" << std::endl;

	printSection("3. CLAPTRAP BASIC ACTIONS");
	clap1.attack("enemy");
	clap1.attack("enemy");
	clap1.attack("enemy");
	clap1.attack("enemy");
	clap1.attack("enemy");
	clap1.attack("enemy");
	clap1.attack("enemy");
	clap1.attack("enemy");
	clap1.attack("enemy");
	clap1.attack("enemy");
	clap1.attack("enemy");	// Should fail - out of energy

	printSection("4. SCAVTRAP INHERITED METHODS (attack)");
	ScavTrap scav2("ScavTrap_Attacker");
	for (int i = 0; i < 5; i++)
		scav2.attack("target");
	std::cout << "After 5 attacks, should have 45 EP left" << std::endl;

	printSection("5. SCAVTRAP INHERITED METHODS (takeDamage)");
	scav2.takeDamage(25);	// 100 - 25 = 75 HP
	scav2.takeDamage(40);	// 75 - 40 = 35 HP
	scav2.takeDamage(50);	// 35 - 50 = 0 HP (clamped)

	printSection("6. SCAVTRAP INHERITED METHODS (beRepaired)");
	ScavTrap scav3("ScavTrap_Medic");
	scav3.beRepaired(30);	// 100 + 30 HP, 49 EP
	scav3.beRepaired(20);	// 130 HP, 48 EP
	scav3.takeDamage(50);	// 80 HP

	printSection("7. SCAVTRAP SPECIFIC METHOD (guardGate)");
	ScavTrap gatekeeper("GateKeeper");
	gatekeeper.guardGate();
	gatekeeper.guardGate();
	gatekeeper.guardGate();

	printSection("8. SCAVTRAP - MIXED OPERATIONS");
	ScavTrap mixed("Mixed_Operations");
	mixed.attack("foe");
	mixed.takeDamage(15);
	mixed.beRepaired(10);
	mixed.guardGate();
	mixed.attack("foe");

	printSection("9. INHERITANCE - POLYMORPHIC BEHAVIOR");
	std::cout << "Testing pointers and base references:" << std::endl;
	ClapTrap* base_ptr = &scav1;
	base_ptr->attack("via_pointer");	// Calls ClapTrap::attack (not virtual)
	base_ptr->takeDamage(5);
	base_ptr->beRepaired(2);

	printSection("10. COPY OPERATIONS ON SCAVTRAP");
	ScavTrap original("Original");
	ScavTrap copy = original;			// Copy constructor
	copy = original;					// Copy assignment
	std::cout << "Copy operations executed" << std::endl;

	printSection("11. DESTRUCTION ORDER");
	std::cout << "Exiting scope to test destructor order:" << std::endl;
	{
		ScavTrap temp_scav("Temporary_ScavTrap");
		ClapTrap temp_clap("Temporary_ClapTrap");
	}
	std::cout << "Both destructors called" << std::endl;

	std::cout << "\n========== FINAL CLEANUP ==========" << std::endl;
	return (0);
}