/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:43:44 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/24 02:37:54 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

//il faut un autre getInput mais qui ne soit pas en private
std::string	getInput(void)
{
	std::string	input;

	if (!std::getline(std::cin,input))
	{
		std::cout << "Error" << std::endl;
		return ("EXIT");//si loperation echoue on exit
	}
	//mettre les commande en majuscule 
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = toupper(*it);
	return (input);
}

int	main(void)
{
	
	PhoneBook	book;
	//il faut recuperer le userinput et agir en fonctione de de l'input
	std::string	input;

	while (1)
	{
		std::cout << std::endl << PROMPT_ONE << std::endl << PROMPT_TWO;
		input = getInput();
		if (input == "ADD") {
			book.addContact();
		}//tout se les contacts s'enregistre bien manque plus qu'une fonction qui en cas de SEARCH
		//afficher tout les contacts par ordre dentrée 4 colonnes index , firstnam, last, nickname
		//chaque collone doit faire 10 caractere de long
		if (input == "SEARCH") {
			book.showContact();
		}
	}
}
