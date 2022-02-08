/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:36:47 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/08 16:30:40 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int main()
{

	std::cout << std::endl;
	std::cout << " ==== Test with MutantStack ==== " << std::endl;
	std::cout << std::endl;

	MutantStack<int> mstack;
	
	std::cout << Blue "Adding 5 and 12 to MutantStack" Reset << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << Blue "Showing top of stack" Reset << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << Blue "Popping top of stack" Reset << std::endl;
	mstack.pop();
	std::cout << Blue "Showing top of stack" Reset << std::endl;
	std::cout << mstack.top() << std::endl;
	std::cout << Blue "Showing size of stack" Reset << std::endl;
	std::cout << mstack.size() << std::endl;

	std::cout << Blue "Adding 3, 5, 737 and 0 to our MutantStack" Reset << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);

	std::cout << std::endl;
	std::cout << " ==== Test with list container ==== " << std::endl;
	std::cout << std::endl;


	std::list<int> lstack;
	
	std::cout << Blue "Adding 5 and 12 to MutantStack" Reset << std::endl;
	lstack.push_front(5);
	lstack.push_front(17);
	
	std::cout << Blue "Showing top of stack" Reset << std::endl;
	std::cout << lstack.front() << std::endl;
	std::cout << Blue "Popping top of stack" Reset << std::endl;
	lstack.pop_front();
	std::cout << Blue "Showing top of stack" Reset << std::endl;
	std::cout << lstack.front() << std::endl;
	std::cout << Blue "Showing size of stack" Reset << std::endl;
	std::cout << lstack.size() << std::endl;
	
	std::cout << Blue "Adding 3, 5, 737 and 0 to our MutantStack" Reset << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);
	
	std::list<int>::iterator jt = lstack.begin();
	std::list<int>::iterator jte = lstack.end();
	
	++jt;
	--jt;
	while (jt != jte)
	{
		std::cout << *jt << std::endl;
		++jt;
	}
	std::list<int> l(lstack);
	
	return 0;
}