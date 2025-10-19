/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:05:38 by asemykin          #+#    #+#             */
/*   Updated: 2025/10/16 15:28:18 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        void set_first(std::string str);
        void set_last(std::string str);
        void set_nick(std::string str);
        void set_phone(std::string str);
        void set_secret(std::string str);
        
        void displaySummary(int index)const;
        void displayIndex()const;
};

#endif
