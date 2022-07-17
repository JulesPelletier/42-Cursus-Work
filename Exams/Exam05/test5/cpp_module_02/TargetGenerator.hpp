# pragma once

# include <iostream>
# include "ATarget.hpp"
# include <map>

class	TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();


		void	learnTargetType(ATarget *t);
		void	forgetTargetType(std::string const &t);
		ATarget	*createTarget(std::string const &type);

	private:
		TargetGenerator(TargetGenerator const &tg);
		TargetGenerator &operator=(TargetGenerator const &tg);

		std::map<std::string, ATarget *>	targets;
	protected:

};