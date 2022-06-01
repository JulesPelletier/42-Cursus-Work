/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   All.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:55:43 by julpelle          #+#    #+#             */
/*   Updated: 2022/03/30 00:26:32 by julpelle         ###   ########.fr       */
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
# include "Utils/Colors.hpp"

// Pair
# include "Utils/Pair.hpp"
# include "Utils/Less.hpp"
# include "Utils/Binary.hpp"

// Node
# include "Utils/Node.hpp"

///////////////////////
//     Containers    //
///////////////////////

# include "Vector/Vector.hpp"
# include "Stack/Stack.hpp"
# include "Map/Map.hpp"

///////////////////////
//     Iterators     //
///////////////////////

# include "Iterators/IterRev.hpp"
# include "Iterators/IterVector.hpp"
# include "Iterators/IterMap.hpp"
# include "Iterators/Types.hpp"

///////////////////////
//       Tests       //
///////////////////////

# include "../tests/Basic/BasicTest.hpp"
# include "../tests/Basic/ShowContainer.hpp"
# include "../tests/Vector/VectorTest.hpp"
# include "../tests/Map/MapTest.hpp"

///////////////////////
//     Functions     //
///////////////////////

int 	error_msg(std::string msg, int color, int ret);
void 	print_header(std::string msg, std::string arg);





#endif