/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:38:03 by asemykin          #+#    #+#             */
/*   Updated: 2025/10/15 22:17:29 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

// constructor
PhoneBook::PhoneBook() {
    index = 0;
    count = 0;
}

std::string getInput(std::string msg)
{
    std::string input;
    
    while(input.empty())
    {   
        std::cout << msg;
        std::getline(std::cin, input);
        if(input.empty())
            std::cout << "  --- Input must be filled ---" << std::endl;
    }
    return input;
}

void PhoneBook::addContact()
{
    std::cout << "\n";
     
    std::string first;
    std::string last;
    std::string nick;
    std::string phone;
    std::string secret;

    first = getInput("Enter First Name: ");
    last = getInput("Enter Last Name: ");
    nick = getInput("Enter Nickname: ");
    phone = getInput("Enter Phonenumber: ");
    secret = getInput("Enter Darkest Secret: ");

    contacts[index].set_first(first);
    contacts[index].set_last(last);
    contacts[index].set_nick(nick);
    contacts[index].set_phone(phone);
    contacts[index].set_secret(secret);

    index = (index + 1) % 8;
    if(count < 8)
        count++;
    
    std::cout << "  +++ Contact added successfully +++" << "\n" << std::endl;
}

void PhoneBook::displayContacts() const
{
    if(count > 0)
    {
        for(int i = 0; i < count; i++)
            contacts[i].displaySummary(i);
    }
    else
        std::cout << "|-----------------  EMPTY  -----------------|" << std::endl; 
}

void PhoneBook::searchContact() const
{
    std::cout   << "\n" 
                << "|---------------  PHONEBOOK  ---------------|" << "\n"
                << "|-------------------------------------------|" << "\n"
                << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << "\n"
                << "|-------------------------------------------|" << std::endl;
    displayContacts();    
    std::cout   << "|-------------------------------------------|" << "\n" << std::endl;                
}
