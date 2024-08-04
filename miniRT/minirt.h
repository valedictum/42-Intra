/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:11:49 by atang             #+#    #+#             */
/*   Updated: 2024/08/04 14:50:01 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h> //read, close
# include <stdio.h> //size_t, printf
# include <stdlib.h>
# include <fcntl.h> // O_RDONLY macro

// DEFINITIONS //

# define MAX_OBJECTS 100

# define RST    "\033[0m"      /* Reset to default color */
# define RED    "\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */

// STRUCTURES//

typedef	struct
{
	float x;
	float y;
	float z;
}	Vector3;

typedef	struct
{
	int	r;
	int	g;
	int	b;
}	Colour;

typedef	struct
{
	float	ratio;
	Colour	colour;
}	AmbientLight;

typedef	struct
{
	Vector3	position;
	Vector3	orientation;
	float	fov;
}	Camera;

typedef	struct
{
	Vector3	position;
	float	brightness;
	Colour	colour;
}	Light;

typedef	struct
{
	Vector3	centre;
	float	diameter;
	Colour	color;
}	Sphere;

typedef	struct
{
	Vector3	point;
	Vector3	normal;
	Colour	color;
}	Plane;

typedef	struct
{
	Vector3	centre;
	Vector3	axis;
	float	diameter;
	float	height;
	Colour	color;
}	Cylinder;

typedef enum
{
    SPHERE,
    PLANE,
    CYLINDER
}	ObjectType;

typedef	struct 
{
	ObjectType	type;
	union
	{
		Sphere		sphere;
		Plane		plane;
		Cylinder	cylinder;
	}	data;
}	Object;

typedef	struct
{
	AmbientLight	ambient_light;
	Camera			camera;
	Light			light;
	Object			objects[MAX_OBJECTS];
	int				object_count;
}	Scene;

// PROTOTYPES //

// file_check.c //
int		file_exists(char *filename);
int		filename_error(char	*filename);
int		file_empty(const char	*filename);

// utils //
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// get_next_line //
char 	*get_next_line(int fd);

#endif