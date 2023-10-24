/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:01:17 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/24 04:03:17 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

//******************************************************************************
//					Public function
//******************************************************************************
//que fait le constructor de cette classe??
//rien a part initialiser l'index
PhoneBook::PhoneBook(void) : _numberOfContacts(-1),
							_break(0) {
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

//******************************************************************************
					//privt function
//******************************************************************************

std::string PhoneBook::_getInput(std::string const prompt)
{
	std::string	input;

	std::cout << prompt << std::endl;//prompt sera au format Rentrer le nom/prnom/numero :
	if (!std::getline(std::cin, input))
		return (std::string());
	return (input);
}


int	PhoneBook::addContact(void)
{
	std::string	input;

	_numberOfContacts++;
	if (_numberOfContacts > 7)
		_numberOfContacts = 0;
	while (!_break) {
		input = _getInput("FirstName: ");
		if (_break || _contacts[_numberOfContacts].setFirstName(input))
			break ;
	}
	while (!_break) {
		input = _getInput("Lastname: ");
		if (_break || _contacts[_numberOfContacts].setLastName(input))
			break ;
	}
	for (int i = 0; i <= _numberOfContacts; i++)
	{
		std::cout << _contacts[i].getFirstName() << std::endl;
		std::cout << _contacts[i].getLastName() << std::endl;
	}
	return (1);
}


int		PhoneBook::showContact(void)
{
	for (int i = 0; i <= _numberOfContacts; i++) {
		std::cout << std::setw(10) << i << '|';
		std::cout << _contacts[i].getFirstName() << '|';
		std::cout << _contacts[i].getFirstName() << '|';
		std::cout << _contacts[i].getNickName() << '|';
		std::cout << std::endl;
	}
	return (1);
}

//function that print a string with a width and everything else
