#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int c_occur(char const *s, char c)
{
    int n;
    int n_occur;

    n = 0;
    n_occur = 0;
    while (s[n] == c)
        n++;
    while (s[n])
    {
        if (s[n] == c)
        {
            while (s[n] == c)
                n++;
            n_occur++;
        }
        else
            n++;
    }
    if (n > 0 && s[n - 1] == c)
        n_occur--;
    return (n_occur);
}

int get_del_pos(char const *s, char c, int c_it)
{
    int n;
    int i_c_it;

    i_c_it = 0;
    n = 0;
    while (s[n] == c)
        n++;
    while (s[n] && i_c_it != c_it)
    {
        if (s[n] == c)
        {
            while (s[n] == c)
                n++;
            i_c_it++;
        }
        else
            n++;
    }
    return(n);
}


int get_str_size(char const *s, char c, int n)
{
    while(s[n] && s[n] != c)
    n++;
    return (n);
}

char    *splitted_str(char const *s, char c, int c_it)
{
    int     n;
    int     nres;
    char    *res;
    
    nres = 0;
    n = get_del_pos(s, c, c_it);
    if ((res = malloc(sizeof(char) * get_str_size(s, c, n) + 1)) == NULL)return (NULL);
    while(s[n] && s[n] != c)
    {    
        res[nres] = s[n];
        nres++;
        n++;
    }
    res[nres] = 0;
    return (res);
}

char    **ft_split(char const *s, char c)
{
    char    **res;
    int     n;
    int     n_occur;

    n = 0;
    n_occur = c_occur(s, c);
    if ((res = malloc(sizeof(char *) * n_occur + 1)) == NULL)
        return (NULL);
    while (n <= n_occur)
    {
        res[n] = splitted_str(s, c, n);
        n++;
    }
    res[n] = NULL;
    return (res);
}

int main()
{
    char *s = " code  pourauoiu il marche pas de merde     ";
    char c = ' ';
    char **res = ft_split(s, c);
    for (int i = 0; res[i] != NULL; i++)
        printf(" res = %s\n", res[i]);
}