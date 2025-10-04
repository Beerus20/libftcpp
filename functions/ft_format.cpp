/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42antananarivo    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:00:55 by ballain           #+#    #+#             */
/*   Updated: 2025/10/04 10:14:27 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftcpp.hpp"

std::string	ft_format(const std::string &text, std::size_t len, const int &justify)
{
	size_t	i(0);
	size_t	j(0);
	std::string	r_value("");

	while (justify && text.length() < len && j++ < len - text.length())
		r_value += " ";
	while (text[i])
	{
		if (len && i == (len - 1) && text.length() != len)
			break ;
		r_value += text[i++];
	}
	if ((len - 1) == i && text.length() > len)
		i += ((r_value += "."), 1);
	while ((j + i++) < len)
		r_value += " ";
	return (r_value);
}