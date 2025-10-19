/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:38:03 by asemykin          #+#    #+#             */
/*   Updated: 2025/10/17 23:55:51 by asemykin         ###   ########.fr       */
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
            std::cout << "--- Input must be filled ---" << std::endl;
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

    index++;
    if(index > 7)   
        index = 0;
    if(count < 8)
        count++;
    
    std::cout << "+++ Contact added successfully +++" << "\n" << std::endl;
}

int PhoneBook::displayContacts() const
{
    if(count > 0)
    {
        for(int i = 0; i < count; i++)
            contacts[i].displaySummary(i);
        return 1;
    }
    std::cout << "|-----------------  EMPTY  -----------------|" << "\n" << std::endl; 
    return 0;
}

int validIndex(std::string str, int count)
{
    int index;
    
    if(str.length() == 1 )
    {
        if(std::isdigit(str[0]))
        {
            index = str[0] - '0';
            if(index >= 0 && index < count)
                return index;
        }
    }
    return -1;
}

void PhoneBook::displayIndex() const
{
    int         index;
    std::string command;
    
    std::cout << "\n" << "Enter Index if you want more information" << std::endl;
    std::getline(std::cin, command); 
    index = validIndex(command, count);
    
    if(index >= 0)
        contacts[index].displayIndex();
    else
        std::cout << std::endl;
}

void PhoneBook::displayPhonebook() const
{
    std::cout   << "\n" 
                << "|---------------  PHONEBOOK  ---------------|" << "\n"
                << "|-------------------------------------------|" << "\n"
                << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << "\n"
                << "|-------------------------------------------|" << std::endl;
    if(displayContacts())
        displayIndex(); 
}
