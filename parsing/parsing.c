#include "../minishell.h"


static int quotes_index(char *str , char quote)
{
char *e;
int index;

if(!(e = strchr(str, quote)))
    return -1;
index = (int)(e - str);
return (index);
}


// char **quotes_manager(t_meta_data *data)
// {
//     int i = 0;
//     int  j = 0;
//     int begin = 0;
//     int end = 0;
//     int quotes = 0;
//     char **strs;
//     while (data->input[i])
//     {
//         if (data->input[i]== '\"')
//             quotes++;
//         i++;
//     }
//     if(quotes % 2 != 0)
//     {
//         printf("error: invalid quotes");
//         exit(1);
//     }
//     strs = malloc(sizeof(char *) * (quotes / 2) + 2);
 
//     i = 0;
//     while (i < quotes / 2)
//     {
//         if((begin = quotes_index(&data->input[i] , '\"')) != -1)
//             i = begin + 1;
//         if((end = quotes_index(&data->input[i] , '\"')) != -1)
//             i = end + 1;
//         strs[j] = ft_strjoin(ft_substr(data->input, 0 , begin) , &data->input[end + begin + 2]);
//         j++;
//         strs[j] = ft_substr(data->input, begin + 1, end);
//         j++;
//     }

//     return(strs);

    
// }


int words_count(char *str)
{
    int  i = -1;
    int  words = 1;
    int quotes = 0;
    while (str[++i])
    {
        if (str[i] == '\"' || str[i] == '\'')
            quotes++;
        if ((str[i] == '|') && quotes % 2 == 0)
            words++;
    }
    return (words);
}

int *l9ali_index(char *str, int words)
{
    int *indexes;
    int i;
    int j;
    int quotes;

    i = -1;
    j = 0;
    quotes = 0;
    indexes = malloc (sizeof(int) * words - 1);
    while (str[++i])
    {
        if (str[i] == '\"' || str[i] == '\'')
            quotes++;
        if ((str[i] == '|') && quotes % 2 == 0)
        {
            indexes[j] = i;
            j++;
        }
    }
    return (indexes);
}

char **split_pipes(char *str)
{
    char **strs;
    int words;
    int *indexes;
    int i;
    words = words_count(str);
    indexes = l9ali_index(str, words);
    strs = malloc(sizeof(char) * words + 1);
    // char *test = ft_substr(str , 0, 6); 
    // printf("%s\n", test);
    
    i = 0;
    int j = 0;
    while (i < words - 1 && str)
    {
        if (i == 0)
            strs[i] = ft_substr(str , j, indexes[i]);
        else
            strs[i] = ft_substr(str , j, indexes[i]  - indexes[i - 1] - 1);
        j = indexes[i] + 1;
        i++;
    }
    j++;
    strs[i] = ft_substr(str , j ,ft_strlen(str - indexes[i]));
  
    i  = -1;
    while (++i < words)
        printf("%s\n", strs[i]);
    return strs;
}

#include <stdio.h>
int main()
{
    split_pipes("ls -l | grep \"test | allah\"| 796");
}