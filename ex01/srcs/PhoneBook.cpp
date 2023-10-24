/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:01:17 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/24 10:13:01 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <string>
#include <iostream>

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

	std::cout << prompt;
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
	while (!_break) {
		input = _getInput("Nickname: ");
		if (_break || _contacts[_numberOfContacts].setNickName(input))
			break ;
	}
	while (!_break) {
		input = _getInput("Number: ");
		if (_break || _contacts[_numberOfContacts].setPhoneNumber(input))
			break ;
	}
	while (!_break) {
		input = _getInput("Darkest secret: ");
		if (_break || _contacts[_numberOfContacts].setSecret(input))
			break ;
	}
	return (1);
}


int		PhoneBook::showContact(void)//en premier lieux affiche la liste des contacts 1 firstn lastn nick
{
	std::string	inputIndex;
	int			index;

	for (int i = 0; i <= _numberOfContacts; i++) {
		std::cout	<< "+----------+----------+----------+----------+" << std::endl
				<< "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl
				<< "+----------+----------+----------+----------+" << std::endl;
		std::cout << '|' << std::setw(10) << i << '|';
		_printLine(this->_contacts[i].getFirstName());
		_printLine(this->_contacts[i].getLastName());
		_printLine(this->_contacts[i].getNickName());
		std::cout << std::endl << "+----------+----------+----------+----------+" << std::endl;
	}

	inputIndex = _getInput("Enter the index of the contact you want to display: ");
	if (!inputIndex.empty()) {
		//verifier que l'index soit bien un nombre entre 0 et 9 donc de len 1 et que ce soit bien un digit
		if (inputIndex.length() == 1 && isdigit(inputIndex[0]))
			index = inputIndex[0] - '0';
		else
			return (0);
		this->_contacts[index].printContact();
	}
	return (1);
}

//function that print a string with a width and everything else
void	PhoneBook::_printLine(std::string str)
{
	if (str.length() > 10) {
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << '|';
}
