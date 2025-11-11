/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:46:54 by asemykin          #+#    #+#             */
/*   Updated: 2025/11/11 16:21:37 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    while(1)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        
        if(std::cin.eof())
            break;
        if(command == "ADD")
            phonebook.addContact();
        else if(command == "SEARCH")
            phonebook.displayPhonebook();
        else if(command == "EXIT")
            break;
        else
            std::cout << ">> Invalid Input <<"  << std::endl;
    }
    return 0;
}
