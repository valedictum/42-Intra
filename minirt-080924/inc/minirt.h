/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:11:49 by atang             #+#    #+#             */
/*   Updated: 2024/09/08 16:22:22 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h> // read, close
# include <stdio.h> // size_t, printf
# include <stdlib.h>
# include <fcntl.h> // O_RDONLY macro
# include <string.h>

// DEFINITIONS //

# define BUFFER_SIZE 1024 
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
	Colour	colour;
}	Sphere;

typedef	struct
{
	Vector3	point;
	Vector3	normal;
	Colour	colour;
}	Plane;

typedef	struct
{
	Vector3	centre;
	Vector3	axis;
	float	diameter;
	float	height;
	Colour	colour;
}	Cylinder;

typedef enum
{
    SPHERE,
    PLANE,
    CYLINDER
}	ObjectType;

typedef	struct Object
{
	ObjectType	type;
	union
	{
		Sphere		sphere;
		Plane		plane;
		Cylinder	cylinder;
	}	data;
	struct Object	*next; // added ths
}	Object;

typedef	struct
{
	AmbientLight	ambient_light;
	Camera			camera;
	Light			light;
	//Object			objects[MAX_OBJECTS]; // Changed to pointer as below
	Object			*objects;
	int				object_count;
}	Scene;

// PROTOTYPES //

// file_check.c //
int		file_exists(char *filename);
int		filename_error(char	*filename);
int		file_empty(const char *filename);

// utils.c //
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		err_ret(const char *error_message);

// get_next_line.c //
char	*read_and_append_lines(int fd, char	*stash);
char	*extract_line_from_stash(char	*stash);
char	*remaining_stash_after_extraction(char *stash);
char	*get_next_line(int fd, char **line);

// get_next_line_utils.c //
size_t	gnl_strlen(const char *str);
char	*gnl_strchr(char *str, int target_char);
char	*gnl_strjoin(char *first_str, char *second_str);
char	*gnl_initialise_str(void);

// parse_elements.c //
int		parse_ambient_light(char *line, AmbientLight *ambient_light);
int		parse_camera(char *line, Camera *camera);
int		parse_light(char *line, Light *light);

// parse_main.c //
int		parse_rt_file(const char *filename, Scene *scene);
int		parse_line(char	*line, Scene *scene);

// parse_shapes.c //
int		parse_sphere(char *line, Scene *scene);
int		parse_plane(char *line, Scene *scene);
int		parse_cylinder(char *line, Scene *scene);

// parse_utils.c //
float	parse_float(char **str);
int		parse_int(char	**str);
int		parse_vector3(char *str, Vector3 *vec);
int		parse_colour(char *str, Colour *colour);
int		get_next_token(char **token);
int		free_and_return(Object *obj, int ret_val);

#endif