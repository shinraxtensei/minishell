#include "minishell.h"

// void ft_new_split(t_meta_data *data)
// {
//     char **arr;
//     int i;
//     int len;

//     i = 0;
//     len = 0;
//     while (data->input[i])
//     {
//         if (data->input[i] == '|')
//             len++;
//         i++;
//     }
//     if (len >= 1)
//         arr = ft_split(data->input, ' ');
//     while ()
// }
void env_setup(char **env, t_meta_data *data)
{
    
}

int main (int ac, char **argv, char **env)
{
    (void) ac;
    (void) argv;    
    t_meta_data data;
    

    while(1)
    {
        data.input = readline("minishell :");
        ft_new_split(&data);








        if(strcmp(data.input, "exit") == 0)
            break;
    }
    return 0;
}