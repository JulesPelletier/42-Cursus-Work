# pragma once

# include <iostream>
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
		std::map<std::string, ATarget *>	targets;
		
	protected:

};