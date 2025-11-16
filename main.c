#include "cub.h"
char    *skip_Spaces(char *str)
{
    while (str)
    {
        if(!((*str >=9 && *str <= 13) || *str ==32))
            break;
        str++;
    }
    return(str);
}
int is_whitespaces(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(!(str[i] >= 9 && str[i] <= 13) && str[i] != 32)
            return 1;
        i++;
    }
    return 0;
}


void    initialize(t_data *data)
{
    data->EA_path =NULL;
    data->NO_path =NULL;
    data->SO_path= NULL;
    data->WE_path= NULL;
    data->count = 0;
}



int main(int ac, char **av)
{
    (void) ac;
    t_data data;
    initialize(&data);
    parsing(av, &data);
}