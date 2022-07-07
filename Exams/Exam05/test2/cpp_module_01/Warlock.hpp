# include <iostream>

class	Warlock
{
	private:
		std::string	_name;
		std::string _title;

		Warlock(void);
		Warlock(const Warlock &w);
		Warlock	&operator=(const Warlock &w);

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock(void);


		std::string const	&getName(void) const;
		std::string const	&getTitle(void) const;
		void				setTitle(std::string const &title);
		void				introduce(void) const;

};