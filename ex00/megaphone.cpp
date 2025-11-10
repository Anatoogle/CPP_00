/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:16:39 by asemykin          #+#    #+#             */
/*   Updated: 2025/11/10 09:55:18 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char **argv)
{
	if(argc > 1)
	{
		for(int i = 1; argv[i]; i++)
		{
			if(i > 1)
				std::cout << " ";
			for(int j = 0; argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
