/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:41:26 by ple-stra          #+#    #+#             */
/*   Updated: 2022/11/26 01:39:54 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static char	*ft_join_paths(char const *p1, size_t len_p1, char const *p2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	int		is_finished;

	if (!p1 || !p2)
		return (NULL);
	len1 = len_p1;
	is_finished = *(p1 + len1 - 1) == '/';
	len2 = ft_strlen(p2);
	str = malloc(sizeof(char) * (len1 + (!is_finished) + len2 + 1));
	if (!str)
		return (0);
	while (len_p1--)
		*str++ = *p1++;
	if (!is_finished)
		*str++ = '/';
	while (*p2)
		*str++ = *p2++;
	*str = 0;
	return (str - (len1 + (!is_finished) + len2));
}

static int	from_env_path(char **abs_path, const char *r_path,
	const char *env_path)
{
	char	*next;

	while (*env_path)
	{
		next = ft_strchr(env_path, ':');
		if (next == 0)
			next = ft_strchr(env_path, '\0');
		if (next - env_path <= 1)
		{
			env_path = next + 1;
			continue ;
		}
		*abs_path = ft_join_paths(env_path, next - env_path, r_path);
		if (!*abs_path)
			return (0);
		if (access(*abs_path, F_OK) == 0)
			return (1);
		free(*abs_path);
		*abs_path = 0;
		if (*next == '\0')
			return (0);
		env_path = next + 1;
	}
	*abs_path = 0;
	return (1);
}

// Store the absolute path or the relative path in abs_path if he is available.
// Returns 0 in case of sucess, returns errno otherwise (be sure to use the
// return value of this method as errno can be overwritted).
int	get_absolute_path(char **abs_path, const char *r_path, const char *env_path)
{
	int	s_errno;

	*abs_path = 0;
	s_errno = 0;
	errno = 0;
	if (access(r_path, X_OK) == 0)
	{
		*abs_path = ft_strdup(r_path);
		return (errno);
	}
	s_errno = errno;
	if (env_path)
		if (!from_env_path(abs_path, r_path, env_path))
			return (errno);
	if (*abs_path)
		return (0);
	return (s_errno);
}

const char	*get_path_from_env(char *const *env)
{
	if (!env)
		return (0);
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (*env + 5);
		env++;
	}
	return (0);
}

char	*ft_basename(const char *path)
{
	const char	*last_separator;

	while (*path)
	{
		if (*path == '/')
			last_separator = path;
		path++;
	}
	return (ft_strdup(++last_separator));
}
