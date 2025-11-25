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
    char player_dir;
    int player_x;
    int player_y;
    int count;
}   t_data;

//utils
int is_whitespaces(char *str);
char    *skip_Spaces(char *str);
int is_space(char c);


// LIBFT
int	ft_strncmp(const char *str1, const char *str2, size_t n);
int	ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
//parsing
void    error(char *message);
int parse_spaces(char **map, int i, int j, int count, int width);
void parse_map(t_data *data);
char    *get_path(char *str);
int check_filename(char *filename);
int is_map(char *line);
void    initialize(t_data *data);
int is_whitespaces(char *str);
int        check_compo(char *filename,t_data *data);
void allocate_map(t_data *data, char *filename);
void parsing(char **av, t_data *data);
#endif