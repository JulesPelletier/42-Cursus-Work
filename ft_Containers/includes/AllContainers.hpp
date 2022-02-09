/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllContainers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:42:15 by julpelle          #+#    #+#             */
/*   Updated: 2022/02/09 01:24:30 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLCONTAINERS_HPP
# define ALLCONTAINERS_HPP

// Include standard libraries
# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <memory>
# include <fstream>

// Include color formating librarie
# include "Colors.hpp"

// Includes new container libraries
# include "Stack.hpp"
# include "Vector/Vector.hpp"
# include "Vector/IterVector.hpp"
# include "Vector/RevIterVector.hpp"
# include "Map.hpp"

// Include test libraries
# include "../srcs/tests/vector/TestVector.hpp"
# include "../srcs/tests/stack/TestStack.hpp"
# include "../srcs/tests/map/TestMap.hpp"

// Functions

void	test_vector_constructor();
void	test_vector_iterators();
void	test_vector_overload();
void	test_vector_capacity();
void	test_vector_element_access();
void	test_vector_modifiers();
void	test_vector_allocator();
void	test_vector_all();


#endif /* *************************************************** ALLCONTAINERS_H */