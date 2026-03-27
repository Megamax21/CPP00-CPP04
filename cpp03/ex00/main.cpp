/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:33:33 by ml-hote           #+#    #+#             */
/*   Updated: 2026/03/27 00:34:05 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void	printSection(const std::string& title)
{
	std::cout << "\n========== " << title << " ==========" << std::endl;
}

int	main(void)
{
	printSection("1. INITIALIZATION & COPY OPERATIONS");
	ClapTrap robot1("Clanker");
	ClapTrap robot2 = robot1;		// Copy constructor
	robot2 = robot1;				// Copy assignment
	std::cout << "Both robots initialized (10 HP, 10 EP, 0 ATK)\n" << std::endl;

	printSection("2. ATTACK - ENERGY DEPLETION");
	ClapTrap attacker("Attacker");
	for (int i = 0; i < 12; i++)
	{
		std::cout << "[Attack " << i + 1 << "] ";
		attacker.attack("target");
	}

	printSection("3. DAMAGE - HP DEPLETION");
	ClapTrap victim("Victim");
	victim.takeDamage(3);
	victim.takeDamage(5);
	victim.takeDamage(4);
	victim.takeDamage(10);	// Test damage > remaining HP (should clamp to 0)

	printSection("4. DAMAGE TO BROKEN ROBOT");
	ClapTrap broken("Already_Broken");
	broken.takeDamage(20);	// First hit breaks it
	broken.takeDamage(5);	// Try to damage already broken
	broken.takeDamage(100);	// Large damage to already broken

	printSection("5. REPAIR - ENERGY DEPLETION");
	ClapTrap repairer("Repairer");
	for (int i = 0; i < 12; i++)
	{
		std::cout << "[Repair " << i + 1 << "] ";
		repairer.beRepaired(2);
	}

	printSection("6. REPAIR BROKEN ROBOT (no energy left)");
	ClapTrap damaged("Damaged");
	damaged.takeDamage(15);	// Break it
	damaged.beRepaired(5);	// Won't work

	printSection("7. ATTACK WITH 0 HP");
	ClapTrap deadAttacker("Dead");
	deadAttacker.takeDamage(20);	// Kill it
	deadAttacker.attack("anyone");	// Try to attack while dead

	printSection("8. REPAIR WITH 0 ENERGY");
	ClapTrap exhausted("Exhausted");
	for (int i = 0; i < 10; i++)  // Deplete all 10 energy
		exhausted.beRepaired(1);
	exhausted.beRepaired(5);	// Try repair with no energy left

	printSection("9. MIXED SCENARIO - SURVIVE ON 1 HP");
	ClapTrap survivor("Survivor");
	survivor.takeDamage(9);		// 1 HP left
	std::cout << "Survivor at 1 HP" << std::endl;
	survivor.attack("enemy");		// Should work (HP > 0, EP > 0)
	survivor.beRepaired(10);		// Heal back up
	survivor.attack("enemy");		// Should work again

	printSection("10. EDGE CASE - ZERO DAMAGE");
	ClapTrap zeroTest("ZeroTest");
	zeroTest.takeDamage(0);		// 0 damage taken

	std::cout << std::endl;
	return (0);
}