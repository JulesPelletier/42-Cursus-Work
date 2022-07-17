# pragma once

# include <iostream>

class	Warlock
{
	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();


		std::string	const	&getName() const;
		std::string const	&getTitle() const;
		void				introduce() const;
		void				setTitle(std::string const &title);

	private:
		Warlock();
		Warlock(Warlock const &w);

		Warlock &operator=(Warlock const &w);

		std::string name;
		std::string title;
	protected:

};