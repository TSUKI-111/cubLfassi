#include "cub.h"

void    error(char *message)
{
    printf("error/ %s\n", message);
    exit(1);
}
int is_map(char *line)
{
    skip_Spaces(line);
    if(ft_isdigit(*line))
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
                if(tmp[i][j] == '\n')
                    continue;
                printf("%d  %d   %d*\n", tmp[i][j], i , j);
                return 1;
            }
            j++;
        }
        if(j > 3 )
        {
            printf("aaaaaaaaa/n");
            return 1;
        }
        i++;
    }
    if(i != 3)
    {
        printf("*****\n");
        return 1;
    }
    
        // FREE TMP;
    return(0);
}


int        check_compo(char *filename,t_data *data)
{
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
    if(fd == -1)
        error("OPEN FAILED");
    line = get_next_line(fd);
    while (line)
    {
        if(!ft_strncmp(line, "NO ", 3))
        {
            data->NO_path = get_path(line);
        }
        else if(!ft_strncmp(line, "SO ", 3))
        {
            data->SO_path = get_path(line);
        }
        else if(!ft_strncmp(line, "WE ", 3))
        {
            data->WE_path = get_path(line);
        }
        else if(!ft_strncmp(line, "EA ", 3))
        {
            data->EA_path = get_path(line);
        }
        else if(is_map(line))
            data->count++;
        else if(*line == 'F' || *line == 'C')
        {
            if(floor_ceiling(line))
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
// int parse_map(t_data *data)
// {


// }

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
void parsing(char **av, t_data *data)
{
    if(check_filename(av[1]))
        error("invalid filename");
    if(check_compo(av[1], data))
        error("invalid path or componant");
    allocate_map(data, av[1]);
    //parse_map(data);
}