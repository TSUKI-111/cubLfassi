#include "cub.h"

void    error(char *message)
{
    printf("error/ %s\n", message);
    exit(1);
}
int is_map(char *line)
{
    char *str;
    str = skip_Spaces(line);
    if(ft_isdigit(*str))
        return 1;
    return 0;
}
int check_filename(char *filename)
{
    size_t i;

    i = ft_strlen(filename);
    
    if( i <= 4 || filename[i - 1]!= 'b' || filename[i - 2]!= 'u' || filename[i - 3]!= 'c' || filename[i - 4]!= '.')
        return (1);
    return(0);

}
char    *get_path(char *str)
{
    char *path = ft_strchr(str, '.');
    if(!path)
        return NULL;
    if(path[1] == '/')
        return(path);
    return NULL;

}

int    floor_ceiling(char *line)
{
    char **tmp;
    int i;
    int r;
    int g;
    int b;
    int j;

    line++;
    line = skip_Spaces(line);
    tmp = ft_split(line, ',');

    i= 0;
    while(tmp[i])
    {
        j = 0;
        while(tmp[i][j])
        {
            if(!ft_isdigit(tmp[i][j]))          //FREE
            {   
                return 1;
            }
            j++;
        }
        if(j > 3 )
        {
            return 1;
        }
        i++;
    }
    if(i != 3)
    {
        return 1;
    }
    r = ft_atoi(tmp[0]);
    g = ft_atoi(tmp[1]);
    b = ft_atoi(tmp[2]);
    if(r > 250 || g > 250 || b > 250)
        return 1;
    //function to convert rgb and store it
    
        // FREE TMP;
    return(0);
}
int is_identifier(char *str)
{
    if(!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3) || !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3))
        return 1;
    return 0;
}

int parse_identif(char *str, t_data *data)
{
    if(!ft_strncmp(str, "NO ", 3))
    {
        if(data->NO_path)
            return 0;
        data->NO_path = get_path(str);
    }
    else if(!ft_strncmp(str, "SO ", 3))
    {
        if(data->SO_path)
            return 0;
        data->SO_path = get_path(str);
    }
    else if(!ft_strncmp(str, "WE ", 3))
    {
        if(data->WE_path)
            return 0;
        data->WE_path = get_path(str);
    }
    else if(!ft_strncmp(str, "EA ", 3))
    {
        if(data->EA_path)
            return 0;
        data->EA_path = get_path(str);
    }
    return 1;
}
int        check_map_file(char *filename,t_data *data)
{
    int fd;
    char *line;
    char *str;
    fd = open(filename, O_RDONLY);
    if(fd == -1)
        error("OPEN FAILED");
    line = get_next_line(fd);
    while (line)
    {
        str = skip_Spaces(line);
        if(is_identifier(str))
        {
            if(!parse_identif(str,data))
                error("too many identifiers");
        }
        else if(is_map(str))
            data->count++;
        else if(*str == 'F' || *str == 'C')
        {
            if(floor_ceiling(str))
                error("invalid F identifier");
        }
        else if(!is_whitespaces(line))
        {
            free(line);
            line = get_next_line(fd);
            continue;
        }
        else
        {
            free(line);
            error("INVALID MAP");
        }
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    if(!data->EA_path || !data->SO_path || !data->NO_path || !data->WE_path)
        return 1;
    
    return 0;
    
}


void parsing(char **av, t_data *data)
{
    
    if(check_filename(av[1]))
        error("invalid filename");
    if(check_map_file(av[1], data))
        error("invalid path or componant");
    allocate_map(data, av[1]);
    parse_map(data);
    printf("VALID MAP\n");
}