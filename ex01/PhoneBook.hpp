/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:19:47 by asemykin          #+#    #+#             */
/*   Updated: 2025/10/16 14:39:13 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
private:
    Contact contacts[8];
    int     index;
    int     count;

public:
    PhoneBook();
    void addContact();
    void displayPhonebook()const;
    int displayContacts()const; 
    void displayIndex()const; 
};

#endif