/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:03:35 by eguelin           #+#    #+#             */
/*   Updated: 2023/02/15 17:23:32 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

static void		ft_free_tab(char **tab, size_t n);
static size_t	ft_count_word(char const *s, char c);
static char		*ft_dup_word(char const *s, char c, size_t n);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	*word;
	char	**tab;

	i = 0;
	j = ft_count_word(s, c);
	tab = malloc(sizeof(char *) * (j + 1));
	if (!tab)
		return (NULL);
	while (i < j)
	{
		word = ft_dup_word(s, c, i);
		if (!word)
			return (ft_free_tab(tab, i), NULL);
		tab[i++] = word;
	}
	tab[i] = NULL;
	return (tab);
}

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			j++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (j);
}

static char	*ft_dup_word(char const *s, char c, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*word;

	i = 0;
	j = 0;
	k = 0;
	while (k <= n)
	{
		if ((i > 0 && s[i - 1] != c && s[i] == c) || !s[i])
			k++;
		if (k == n && s[i] != c)
			j++;
		i++;
	}
	i = i - 2;
	word = malloc(sizeof(char) * (j + 1));
	if (!word)
		return (NULL);
	word[j--] = 0;
	while (i + 1 && s[i] != c)
		word[j--] = s[i--];
	return (word);
}

static void	ft_free_tab(char **tab, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(tab[i++]);
	free(tab);
}
