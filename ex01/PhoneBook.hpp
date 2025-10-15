/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:19:47 by asemykin          #+#    #+#             */
/*   Updated: 2025/10/15 21:55:47 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
private:
    Contact contacts[8];
    void displayContacts() const;
    int     index;
    int     count;

public:
    PhoneBook();
    void addContact();
    void searchContact()const;    
};

#endif