/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:44:09 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/24 10:19:09 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>
#include <iomanip>
//Constructor
Contact::Contact(void) : _firstName(""),
					_lastName(""),
					_nickName(""),
					_phoneNumber(""),
					_darkestSecret("") {
	return;
}
//destructor
Contact::~Contact(void){
	return;
}

//******************************************************************************
//GETTERS
//************************************************************************
std::string const Contact::getFirstName(void) const {
	return (this->_firstName);
}

std::string const Contact::getLastName(void) const {
	return (this->_lastName);
}

std::string const Contact::getNickName(void) const {
	return (this->_nickName);
}

std::string const Contact::getPhoneNumber(void) const {
	return (this->_phoneNumber);
}

std::string const Contact::getSecret(void) const {
	return (this->_darkestSecret);
}
//*****************************************************************
//						SETTERS
// Les champs d’un contact enregistré ne peuvent être vides
//*****************************************************************

int			Contact::setFirstName(std::string name)
{
	if (name.empty())
		return (0);
	else if (!_containsOnlyAlpha(name)) {
		std::cout << "Error Name should only be composed of letters, '-' and spaces" << std::endl;
		return (0);
	}
	name[0] = std::toupper(name[0]);
	this->_firstName = name;
	return (1);
}

int			Contact::setLastName(std::string lastname)
{
	if (lastname.empty())
		return (0);
	else if (!_containsOnlyAlpha(lastname))
	{
		std::cout << "Error lastname should only be composed of letters, - and spaces" << std::endl;
		return (0);
	}
	lastname[0] = std::toupper(lastname[0]);
	this->_lastName = lastname;
	return (1);
}

int			Contact::setNickName(std::string nickname)
{
	if (nickname.empty())
		return (0);
	else if (!_containsOnlyAlpha(nickname))
	{
		std::cout << "Error nickname should only be composed of letters, - and spaces" << std::endl;
		return (0);
	}
	nickname[0] = std::toupper(nickname[0]);
	this->_nickName = nickname;
	return (1);
}

int			Contact::setPhoneNumber(std::string number)
{
	if (number.empty())
		return (0);
	else if (!_containsOnlyDigits(number))
	{
		std::cout << "Error, phone number should only be composed by digits" << std::endl;
		return 0;
	}
	this->_phoneNumber = number;
	return 1;
}

int			Contact::setSecret(std::string secret)
{
	if (secret.empty())
		return 0;
	this->_darkestSecret = secret;
	return 1;
}

//***********************************************************************
//						Private function
//**********************************************************************

int			Contact::_containsOnlyAlpha(std::string const input) const//const signifie qu'on ne modifie pas linstance this
{
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isalpha(*it) && *it != ' ' && *it != '-')
			return (0);
	}
	return (1);
}

int			Contact::_containsOnlyDigits(std::string const input) const
{
	for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it) && *it != ' ' && *it != '-')
			return (0);
	}
	return (1);
}

void		Contact::printContact(void) const//a appelr pour chaque element du tableau de contact
{
	std::cout << "Firstname\t: " << this->_firstName << std::endl;
	std::cout << "Lastname\t: " << this->_lastName << std::endl;
	std::cout << "Nickname\t: " << this->_nickName << std::endl;
	std::cout << "Phone number\t: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret\t: " << this->_darkestSecret << std::endl;
}
