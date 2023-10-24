/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:00:41 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/24 02:18:29 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include "Contact.hpp"
# define PROMPT_ONE "+---------------- Main Menu ----------------+"
# define PROMPT_TWO "What do you want to do > "

/*
• PhoneBook
◦ Représente le répertoire.
◦ Contient un tableau de contacts.
◦ Peut enregistrer 8 contacts maximum. Si l’utilisateur tente d’ajouter un 9ème
contact, remplacez le plus ancien par celui-ci.
◦ Notez que l’allocation dynamique est interdite
*/

class PhoneBook
{
private:
	int				_numberOfContacts;//servira a sqvoir combien on a de contact
	int				_break;
	Contact			_contacts[8];

	std::string		_getInput(std::string const prompt);
public:
	PhoneBook(void);
	~PhoneBook(void);
	int	addContact(void);//demandera a luser de rentrer le nom du gqrs et tout
	int	showContact(void);
}; 

#endif

