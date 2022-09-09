/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   All.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:55:43 by julpelle          #+#    #+#             */
/*   Updated: 2022/07/12 15:21:33 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ALL_HPP
# define ALL_HPP

///////////////////////
// Include Libraries //
///////////////////////

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <memory>
# include <fstream>
# include <cstddef>

///////////////////////
//       Utils       //
///////////////////////

// Color
# include "Colors.hpp"

// Pair
# include "Pair.hpp"
# include "Less.hpp"
# include "Binary.hpp"

// Node
# include "Node.hpp"

///////////////////////
//     Containers    //
///////////////////////

# include "Vector.hpp"
# include "Stack.hpp"
# include "Map.hpp"

///////////////////////
//     Iterators     //
///////////////////////

# include "IterRev.hpp"
# include "IterVector.hpp"
# include "IterMap.hpp"
# include "Types.hpp"

///////////////////////
//       Tests       //
///////////////////////

# include "tests/Basic/BasicTest.hpp"
# include "tests/Basic/ShowContainer.hpp"
# include "tests/Vector/VectorTest.hpp"
# include "tests/Map/MapTest.hpp"

///////////////////////
//     Functions     //
///////////////////////

int 	error_msg(std::string msg, int color, int ret);
void 	print_header(std::string msg, std::string arg);





#endif