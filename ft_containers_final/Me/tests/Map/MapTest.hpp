/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTest.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:13:53 by julpelle          #+#    #+#             */
/*   Updated: 2022/03/31 22:22:33 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAPTEST_HPP
# define MAPTEST_HPP

# include "../../includes/All.hpp"
# include "../../includes/Map/Map.hpp"

namespace	test_m
{

	void	test_map(void);

	template <class T>
	void	print_cont(const T &cont, const std::string &name)
	{
		typename T::const_iterator		it_var;

		std::cout << BCyan << "\n\t******** Map " << name << " - Size : " << cont.size() << " ******** \n\n\t" << Cyan"[\n";
		for (typename T::const_iterator it(cont.begin()); it != cont.end(); ++it)
		{
			it_var = it;
			std::cout << "\t\t" Blue << it->a << " : " Purple<< it->b << Reset;
			std::cout << (++it_var != cont.end() ? ",\n" : "\n");
		}
		std::cout <<Cyan " \t]\n\n" Reset;
	}

	template <class T>
	void	print_cont2(const T &cont, const std::string &name)
	{
		typename T::const_iterator		it_var;
		int								t;

		std::cout << BCyan << "\n\t******** Map " << name << " - Size : " << cont.size() << " ******** \n\n\t" << Cyan"\n";
		for (typename T::const_iterator it(cont.begin()); it != cont.end(); ++it)
		{
			t = 0;
			while (t < it->b)
			{
				std::cout << "   ";
				t++;
			}
			it_var = it;
			std::cout << Blue << it->a << " : " Purple<< it->b << Reset;
			std::cout << (++it_var != cont.end() ? ",\n" : "\n");
		}
		std::cout <<Cyan "\n\n" Reset;
	}

	

	template <class Cont, class T>
	void	test_capacity(T *init, size_t size_init)
	{
		Cont				c1;
		Cont				c2(init, init + size_init);
	

		print_cont(c1, "Empty Map");
		std::cout << "\tSize \t\t: " << c1.size() << "\n";
		std::cout << "\tMax size \t: " << c2.max_size() << "\n";
		std::cout << "\tEmpty \t\t: " << c2.empty() << "\n";
		print_cont(c2, "Default Map");
		std::cout << "\tSize \t\t: " << c2.size() << "\n";
		std::cout << "\tMax size \t: " << c2.max_size() << "\n";
		std::cout << "\tEmpty \t\t: " << c2.empty() << "\n";
	}

	template <class Container, class T>
	void
	test_access(T *init, size_t size_init)
	{
		Container			c(init, init + size_init);

		std::cout << "\n";
		std::cout << "\n";
		for (size_t i = 0; i < size_init; ++i)
		{
			if (i % 2 == 0)
				std::cout << "\tPair " Green << i << Reset "\t\tAccess [ "  Green 
					<< c[init[i].a] << Reset " ] \t\t Original  [" Green<< init[i].b << Reset " ]\n";
			else
				std::cout << "\tPair " Green << i << Red "\t\t ******* Odd number *******\n" Reset;
		}
	}

	template <class Container, class T>
	void
	test_modifiers(T *init, size_t size_init)
	{
		Container			c1;
		Container			c2;

		(void)size_init;
		print_cont(c1, "Starting Map");
		print_cont(c2, "Empty Map for Swap");
		std::cout << "\tSize \t\t: " << c1.size() << "\n";
		std::cout << "\tMax size \t: " << c1.max_size() << "\n";
		std::cout << "\tEmpty \t\t: " << c1.empty() << "\n";
		std::cout << "\n";
		std::cout << "\n";
		
		std::cout << BGreen "\tInsert : \n";
		c1.insert(init[0]);
		print_cont(c1, "Container 1");
		c1.insert(init[5]);
		c1.insert(init[3]);
		c1.insert(init[6]);
		print_cont(c1, "Container 1");
		c1.insert(init[2]);
		c1.insert(init[9]);
		c1.insert(init[11]);
		print_cont(c1, "Container 1");
		
		std::cout << BGreen "\tErase : \n";
		c1.erase(c1.begin());
		c1.erase(init[1].a);
		c1.erase(init[2].a);
		c1.erase(init[3].a);
		c1.erase(init[4].a);
		print_cont(c1, "Container 1");

		std::cout << BGreen "\tSwap : \n";
		print_cont(c1, "New Map");
		print_cont(c2, "Original Map");
		std::cout << Green"\t------------------------------------------------\n"Reset;

		c1.swap(c2);
		print_cont(c1, "Container 1");
		print_cont(c2, "Container 2");
		
		std::cout << BGreen "\tClear : \n";
		c1.clear();
		c2.clear();
		print_cont(c1, "Container 1");
		print_cont(c2, "Container 2");
	}

	template <class Container, class T>
	void
	test_observers(T *init, size_t size_init)
	{
		Container		c1(init, init + size_init);

		print_cont(c1, "Container");
		std::cout << BGreen"\tKey Compare : \n" Reset;
		std::cout << "\t - val 0 and 1 - \n" Reset;
		std::cout << "\tFirst key : " << init[0].a << "\t| Second key : " << init[1].a << "\n\tres = " << 
			(c1.key_comp()(init[0].a, init[1].a) ? Green "true\n" Reset : Red "false\n" Reset);
		std::cout << "\t - val 1 and 4 - \n" Reset;
		std::cout << "\tFirst key : " << init[1].a << "\t| Second key : " << init[4].a << "\n\tres = " << 
			(c1.key_comp()(init[1].a, init[4].a) ? Green "true\n" Reset : Red "false\n" Reset );
		std::cout << BGreen"\n\tValue Compare : \n" Reset;
		std::cout << "\t - val 0 and 4 - \n" Reset;
		std::cout << "\tFirst value : " << init[0].a << "\t| Second value : " << init[0].b << "\n" <<
			"\tFirst value : " << init[4].a << "\t| Second value : " << init[4].b << "\n\tres = " << 
			(c1.value_comp()(init[0], init[4]) ? Green "true\n" Reset : Red "false\n" Reset);
		std::cout << "\t - val 3 and 4 - \n" Reset;
		std::cout << "\tFirst value : " << init[3].a << "\t| Second value : " << init[3].b << "\n" <<
			"\tFirst value : " << init[4].a << "\t| Second value : " << init[4].b << "\n\tres = " << 
			(c1.value_comp()(init[3], init[4]) ? Green "true\n" Reset : Red "false\n" Reset);
		std::cout << "\t - val 1 and 6 - \n" Reset;
		std::cout << "\tFirst value : " << init[1].a << "\t| Second value : " << init[1].b << "\n" <<
			"\tFirst value : " << init[6].a << "\t| Second value : " << init[6].b << "\n\tres = " << 
			(c1.value_comp()(init[1], init[6]) ? Green "true\n" Reset : Red "false\n" Reset);
		
	}

	template <class Container, class T>
	void
	test_operations(T *init, size_t size_init)
	{
		Container						c1(init, init + size_init);
		typename Container::iterator	res;
		size_t							count = 0;

		print_cont(c1, "Container");
		res = c1.find(init[0].a);
		std::cout << Yellow "\tFinding : " << init[0].a << "\n\n";
		std::cout << Reset "\t\tResult : \t" Blue << res->a << " | " << res->b << Reset "\n\n";
		res = c1.find(init[4].a);
		std::cout << Yellow "\tFinding : " << init[4].a << "\n\n";
		std::cout << Reset "\t\tResult : \t" Blue << res->a << " | " << res->b << Reset "\n\n";
		res = c1.find(init[8].a);
		std::cout << Yellow "\tFinding : " << init[4].b << "\n\n";
		std::cout << Reset "\t\tResult : \t" Blue << res->a << " | " << res->b << Reset "\n\n";
		count = c1.count(init[0].a);
		std::cout << Yellow "\tCounting : " << init[0].a << "\n\n";
		std::cout << Reset "\t\tResult : \t" Blue << count << "\n\n";
		count = c1.count(init[1].a);
		std::cout << Yellow "\tCounting : " << init[1].a << "\n\n";
		std::cout << Reset "\t\tResult : \t" Blue << count << "\n\n";
		count = c1.count(init[2].a);
		std::cout << Yellow "\tCounting : " << init[2].a << "\n\n";
		std::cout << Reset "\t\tResult : \t" Blue << count << "\n\n";
	}


}	// end of namespace


# endif