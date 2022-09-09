# pragma once

# include <iostream>
# include <map>
# include "ATarget.hpp"

class	TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();


		void	learnTargetType(ATarget *t);
		void	forgetTargetType(std::string const &type);
		ATarget	*createTarget(std::string const &type);
		
	private:
		TargetGenerator(TargetGenerator const &tg);
		TargetGenerator &operator=(TargetGenerator const &tg);

		std::map<std::string, ATarget *>	targets;
	protected:
};