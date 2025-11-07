/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:27:52 by asemykin          #+#    #+#             */
/*   Updated: 2025/11/07 12:29:53 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
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
    std::string subs;
    
    if(entry.length() > 10)
    {
        subs = entry.substr(0,9);
        subs += '.';
        return (subs);
    }
        
    return entry;
}

void Contact::displayIndex() const
{
    std::cout   << "First Name:     " << firstName << "\n"
                << "Last Name:      " << lastName << "\n"
                << "Nickname:       " << nickName << "\n"
                << "Phonenumber:    " << phoneNumber << "\n"
                << "Darkest Secret: " << darkestSecret << "\n" << std::endl;
}

void Contact::displaySummary(int index) const
{
    std::cout   << "|"
                << std::setw(10) << index << "|"
                << std::setw(10) << entryFormat(firstName) << "|"
                << std::setw(10) << entryFormat(lastName) << "|"
                << std::setw(10) << entryFormat(nickName) << "|" << std::endl;
}
