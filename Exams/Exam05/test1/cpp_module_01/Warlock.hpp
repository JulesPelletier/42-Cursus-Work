# include <iostream>

class	Warlock
{
	private:
		std::string  	_name;
		std::string 	_title;

		Warlock();
		Warlock(Warlock const &w);
		Warlock	&operator=(const Warlock &w);

	public:

		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string	const	&getName(void) const;
		std::string	const	&getTitle(void) const;

		void				introduce(void) const;
		void				setTitle(std::string const &title);
};
