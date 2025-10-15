/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:46:54 by asemykin          #+#    #+#             */
/*   Updated: 2025/10/15 22:00:43 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    while(1)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, command);
        
        if(command == "ADD")
            phonebook.addContact();
        else if(command == "SEARCH")
            phonebook.searchContact();
        else if(command == "EXIT")
            break;
        else
            std::cout << "  > Invalid Input <" << "\n" << std::endl;
    }
    return 0;
}

