#include "cub.h"

int is_surrounded_by_walls(t_data *data)
{
    int i;
    int j;
    char **map = data->map;

    i = 1;
    j = 0;
    while(map[0][j])
    {
        if(map[0][j] != '1')
            return 1;
        j++;
    }
    j=0;
    while(map[data->count - 1][j])
    {
        if(map[data->count - 1][j] != '1')
            return 1;
        j++;
    }
    while (map[i])
    {
        if(map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
            return 1;
        i++;
    }
    return 0;
}

void allocate_map(t_data *data, char *filename)
{
    char *line;
    int fd;
    int i;

    i = 0;
    fd = open(filename, O_RDONLY);
    if(fd == -1)
    {
        printf("ERROR/open");
        exit(1);
    }
    data->map = malloc(data->count * sizeof(char *));
    line = get_next_line(fd);
    while(line)
    {
        if(is_map(line))
        {
            data->map[i] = ft_strdup(line);
            i++;
        }
        free(line);
        line = get_next_line(fd);
    }
    if(!line)
        free(line);
    close(fd);
    data->map[i] = 0;
}

int map_elements(t_data *data)
{
    int i;
    int j;

    i = 0;
    while(data->map[i])
    {
        j = 0;
        while(data->map[i][j])
        {
            if(ft_strchr("10NSEW",data->map[i][j]))
            {
                if(ft_strchr("NSEW", data->map[i][j]) && !data->player_dir)
                {
                    data->player_dir = data->map[i][j];
                    data->player_x = i;
                    data->player_y = j;
                }
                else
                    return 1;

            }
            else
                return 1;
            j++;

        }
        i++;
    }
    return 0;
}

void parse_map(t_data *data)
{
    if(is_surrounded_by_walls(data))
        error("not surrounded by wall");
    if(map_elements(data))
        error("invalid map elements");
    
    
}
int parse_spaces(char **map, int i, int j)
{
    if(map[i][j] == '1')
        return 0;
    if(!(map[i][j]>= 9 && map[i][j]<= 13) && map[i][j] != 32)
        return 1;
    if(parse_spaces(map, i - 1, j))
        return 1;
    if(parse_spaces(map, i + 1, j))
        return 1;
    if(parse_spaces(map, i, j - 1))
        return 1;
    if(parse_spaces(map, i, j + 1))
        return 1;
    return(0);
}