/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:24:03 by atang             #+#    #+#             */
/*   Updated: 2024/08/25 14:26:50 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
	parse_float()
	Converts a str to float and updates the string pointer to point at the next 
	part of the string after the converted number
*/

/*
float	parse_float(char	**str) // The OG one
{
	char	*end; // points to the first character AFTER the parsed number
	float	result; // stores the converted floating-point number

	result = strtof(*str, &end);
	if (end == *str) // No digits were found
		return (0.0f); // May need to change
	if (*end == ',' || *end == '\0')
		*str = end + 1;
	else
		*str = end;
	return (result);
}
*/
float parse_float(const char *str, float *result)
{
    char *endptr;
    *result = strtof(str, &endptr);
    return (*endptr == '\0'); // Return 1 if parsing was successful
}

/*
	parse_int()
	Converts a str to int and updates the string pointer to point at the next 
	part of the string after the converted number
*/

int	parse_int(char	**str)
{
	char	*end;
	int		result;

	result = (int)strtol(*str, &end, 10); // uses strtol to convert str to int in base 10
	if (end == *str) // No digits were found
		return (0); // May need to change
	if (*end == ',' || *end == '\0')
		*str = end + 1;
	else
		*str = end;
	return (result);
}

/*
	parse_vector3()
	Converts 3 floating-point numbers from a str and assigns them to the Vector3 structure's 
	x, y, and z components. Each call to parse_float updates the str pointer to point at the
	next part of the string
*/

/*
void	parse_vector3(char	*str, Vector3	*vec)
{
	vec->x = parse_float(&str);
	vec->y = parse_float(&str);
	vec->z = parse_float(&str);
}
*/

void parse_vector3(const char *str, Vector3 *vec)
{
    float temp;

    // Parse x component
    if (!parse_float(str, &temp)) {
        // Handle error if needed
        return;
    }
    vec->x = temp;

    // Move to the next token
    str = strtok(NULL, " \t");

    // Parse y component
    if (!parse_float(str, &temp)) {
        // Handle error if needed
        return;
    }
    vec->y = temp;

    // Move to the next token
    str = strtok(NULL, " \t");

    // Parse z component
    if (!parse_float(str, &temp)) {
        // Handle error if needed
        return;
    }
    vec->z = temp;
}



/*
	parse_colour()
	Converts 3 int numbers from a str and assigns them to the Colour structure's 
	r, g, and b components
*/

void	parse_colour(char	*str, Colour	*colour)
{
	colour->r = parse_int(&str);
	colour->g = parse_int(&str);
	colour->b = parse_int(&str);
}

int	get_next_token(char **token)
{
	*token = strtok(NULL, " \t");
	if (!*token)
		return (0);
	return (1);
}