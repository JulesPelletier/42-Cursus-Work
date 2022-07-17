# include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
	
}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator b = targets.begin();
	std::map<std::string, ATarget *>::iterator e = targets.end();
	while (b != e)
	{
		delete b->second;
		++b;
	}
	this->targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget *t)
{
	if (t)
		targets.insert(std::pair<std::string, ATarget *>(t->getType(), t->clone()));
	
}

void	TargetGenerator::forgetTargetType(std::string const &type)
{
	std::map<std::string, ATarget *>::iterator it = targets.find(type);
	if (it != targets.end())
		delete it->second;
	targets.erase(type);

}

ATarget	*TargetGenerator::createTarget(std::string const &type)
{
	std::map<std::string, ATarget *>::iterator it = targets.find(type);
	if (it != targets.end())
		return this->targets[type];
	return NULL;
}
