/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:00:41 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/24 10:27:28 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include "Contact.hpp"
# define PROMPT_ONE "+---------------- Main Menu ----------------+"
# define PROMPT_TWO "What do you want to do > "

class PhoneBook
{
private:
	int				_numberOfContacts;
	int				_break;
	Contact			_contacts[8];

	void			_printLine(std::string str);
	std::string		_getInput(std::string const prompt);
public:
	PhoneBook(void);
	~PhoneBook(void);
	int		addContact(void);
	int		showContact(void);
}; 

#endif

