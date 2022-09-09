/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:56:52 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/28 20:44:11 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>

# include "ATarget.hpp"

class Dummy: public ATarget
{
	public:
		Dummy(void);
		~Dummy(void);

		virtual ATarget	*clone(void) const;
};