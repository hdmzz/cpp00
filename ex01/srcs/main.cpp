/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:43:44 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/25 15:19:06 by hdamitzi         ###   ########.fr       */
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

	for (std::string::iterator it = input.begin(); it != input.end(); it++)
		*it = toupper(*it);

	return (input);
}

int	main(void)
{
	PhoneBook	book;
	std::string	input;

	while (1)
	{
		std::cout << std::endl << PROMPT_ONE << std::endl << PROMPT_TWO;
		input = getInput();
		if (input == "ADD")
			book.addContact();
		if (input == "SEARCH") 
			book.showContact();
		if (input == "EXIT") 
			return (0);
	}
}
