/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   All.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:55:43 by julpelle          #+#    #+#             */
/*   Updated: 2022/08/09 18:29:18 by julpelle         ###   ########.fr       */
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
# include <deque>
# include <vector>
# include <stack>
# include <map>

///////////////////////
//       Utils       //
///////////////////////

// Color
# include "colors.hpp"

// Pair
# include "pair.hpp"
# include "less.hpp"
# include "binary.hpp"

// Node
# include "node.hpp"

// Extras
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "equal.hpp"

///////////////////////
//     Containers    //
///////////////////////

# include "vector.hpp"
# include "map.hpp"

///////////////////////
//     Iterators     //
///////////////////////

# include "iterRev.hpp"
# include "itervector.hpp"
# include "iterMap.hpp"
# include "iterTraits.hpp"
# include "types.hpp"

///////////////////////
//       Tests       //
///////////////////////

/*
# include "tests/basic/basicTest.hpp"
# include "tests/basic/showContainer.hpp"
# include "tests/preliminary/preliminary.hpp"
# include "tests/vector/vectorTest.hpp"
# include "tests/map/mapTest.hpp"
# include "tests/compare/compare.hpp"
*/

///////////////////////
//     Functions     //
///////////////////////

int 	error_msg(std::string msg, int color, int ret);
void 	print_header(std::string msg, std::string arg);





#endif