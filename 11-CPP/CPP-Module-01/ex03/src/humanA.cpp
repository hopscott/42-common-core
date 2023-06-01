/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:23:17 by swillis           #+#    #+#             */
/*   Updated: 2022/09/23 21:02:30 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA( const std::string& name, Weapon& weapon ) 
: _name(name), _weapon( weapon ) {

	std::cout << "Constructor called - HumanA called " << getName();
	std::cout << " armed with " << getWeapon().getType() << std::endl;
}

HumanA::~HumanA( void ) {
	
	std::cout << "Destructor called - HumanA called " << getName() << std::endl;
}

// =========
//  Setters
// =========

void	HumanA::setName( std::string name ) {

	_name = name;
}

// =========
//  Getters
// =========

const std::string&	HumanA::getName( void ) const {

	const std::string&	nameREF = _name;
	return nameREF;
}

const Weapon&	HumanA::getWeapon( void ) const {

	const Weapon&	weaponREF = _weapon;
	return weaponREF;
}

// =========
//  Others
// =========

void	HumanA::attack( void ) const {

	std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}
