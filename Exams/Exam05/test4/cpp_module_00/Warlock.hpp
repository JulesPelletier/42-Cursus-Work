# pragma once 

# include <iostream>

class	Warlock
{
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		std::string	const 	&getName(void)const;
		std::string const 	&getTitle(void) const;

		void				setTitle(std::string const &title);
		void				introduce(void) const;

	private:
		Warlock(void);
		Warlock(Warlock const &w);
		Warlock	&operator=(Warlock const &w);

		
		std::string	name;
		std::string	title;

	protected:
};