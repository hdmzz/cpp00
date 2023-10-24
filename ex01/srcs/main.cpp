/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 23:43:44 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/24 16:28:10 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

//c++98 function that deletes all white spaces from a string
void	trim_white_spaces(std::string &str)
{
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
}

std::string	getInput(void)
{
	std::string	input;

	if (!std::getline(std::cin,input) || std::cin.eof())
	{
		std::cout << "Exit" << std::endl;
		return ("EXIT");
	}
	trim_white_spaces(input);
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
