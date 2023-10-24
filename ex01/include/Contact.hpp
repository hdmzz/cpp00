/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:24:01 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/24 09:17:23 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

	int			_containsOnlyAlpha(std::string const input) const;
	int			_containsOnlyDigits(std::string const input) const;
	//une fonction qui affiche les details du contact qui puisse etre appeller pour chaque element d'un tableau de contact
public:
	Contact();
	~Contact();
	//un getter pour firstname
	std::string	const getFirstName(void) const;//le const ici indique que la fonction ne peux pas modifier this
	//un getter pour lastname
	std::string	const getLastName(void) const;
	//un getter pour nickname
	std::string	const getNickName(void) const;
	//un getter pour phonenumber
	std::string	const getPhoneNumber(void) const;
	//un getter pour darksecret
	std::string	const getSecret(void) const;
	
	//un setters pour assigner une valeur au nom 
	int			setFirstName(std::string name);
	int			setLastName(std::string lastname);
	int			setNickName(std::string nickname);
	int			setPhoneNumber(std::string number);
	int			setSecret(std::string secret);

	void		printContact(void) const;
};

#endif
