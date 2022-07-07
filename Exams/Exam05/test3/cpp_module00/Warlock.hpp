/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:18:34 by julpelle          #+#    #+#             */
/*   Updated: 2022/06/28 18:39:32 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

class Warlock
{
	private:
		std::string		name;
		std::string		title;
		

		Warlock(Warlock const &w);
		Warlock(void);
		Warlock &operator=(Warlock const &w);
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);
		
		std::string		const &getName(void) const;
		std::string 	const &getTitle(void) const;
		void			setTitle(std::string const &title);
		void			introduce(void) const;
};