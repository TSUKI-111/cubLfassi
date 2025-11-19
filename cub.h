#ifndef CUB_H
#define CUB_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./gnl/get_next_line.h"


typedef struct s_data
{
    char    *NO_path;
    char    *SO_path;
    char    *WE_path;
    char    *EA_path;
    char    **map;
    int count;
}   t_data;

//utils
int is_whitespaces(char *str);
char    *skip_Spaces(char *str);

// LIBFT
int	ft_strncmp(const char *str1, const char *str2, size_t n);
int	ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
//parsing
char    *get_path(char *str);
int check_filename(char *filename);
int is_map(char *line);
void    initialize(t_data *data);
int is_whitespaces(char *str);
int        check_compo(char *filename,t_data *data);
void allocate_map(t_data *data, char *filename);
void parsing(char **av, t_data *data);
#endif