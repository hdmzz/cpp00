/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:24:01 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/19 15:51:30 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact
{
private:
	std::string FirstName;
	std::string LastName;
	std::string Nickname;
	std::string PhoneNumber;
	std::string DarkestSecret;
public:
	Contact(std::string& first, std::string&last, std::string& nick, std::string& phone, std::string darkest)
		: FirstName(first)
	~Contact();
};

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}
