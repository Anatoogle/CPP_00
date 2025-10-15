/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:27:52 by asemykin          #+#    #+#             */
/*   Updated: 2025/10/15 23:23:10 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void Contact::set_first(std::string str)
{
    firstName = str;
}

void Contact::set_last(std::string str)
{
    lastName = str;
}

void Contact::set_nick(std::string str)
{
    nickName = str;
}

void Contact::set_phone(std::string str)
{
    phoneNumber = str;
}

void Contact::set_secret(std::string str)
{
    darkestSecret = str;
}

std::string entryFormat(std::string entry)
{    
    if(entry.length() > 10)
        return (entry.substr(0,9) + ".");
        
    return entry;
}

int validDigit(std::string str)
{
    int index;
    
    if(str.length() == 1 )
    {
        if(std::isdigit(str[0]))
        {
            index = str[0] - '0';
            if(index >= 0 && index <= 7)
                return index;
        }
    }
    return -1;
}

void Contact::displayIndex() const
{
    std::string index;
    
    std::cout << "Enter Index for more information" << std::endl;
    std::getline(std::cin, index);  

    if(validDigit(index))
        std::cout << "VALID" << std::endl;
}

    
void Contact::displaySummary(int index) const
{
    std::cout   << "|"
                << std::setw(10) << index << "|"
                << std::setw(10) << entryFormat(firstName) << "|"
                << std::setw(10) << entryFormat(lastName) << "|"
                << std::setw(10) << entryFormat(nickName) << "|" << std::endl;
    
    displayIndex();
}
