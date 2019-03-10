/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 13:39:17 by bdomansk          #+#    #+#             */
/*   Updated: 2018/09/28 13:39:20 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_flags
{
	int	h;
	int e;
	int l;
	int	c;
	int	s;
	int	a;
	int	f;
	int	m;

}				t_flags;

typedef struct	s_lines
{
	char			*line;
	struct s_lines	*next;
}				t_lines;

typedef struct	s_links
{
	char			*name1;
	char			*name2;
	struct s_links	*next;
}				t_links;

typedef struct	s_rooms
{
	char			*name;
	int				x;
	int				y;
	struct s_rooms	*next;
}				t_rooms;

typedef struct	s_adj_list
{
	char				*name;
	int					id;
	struct s_adj_list	*next;
}				t_adj_list;

typedef struct	s_queue
{
	int				id;
	int				id_prev;
	int				level;
	struct s_queue	*next;
	struct s_queue	*prev;
}				t_queue;

typedef struct	s_text
{
	char			*content;
	int				id;
	struct s_text	*next;
}				t_text;

typedef struct	s_path
{
	t_text			*text;
	struct s_path	*next;
}				t_path;

typedef struct	s_moves
{
	int				num;
	int				id_room;
	int				active;
	t_text			*text;
	struct s_moves	*next;
}				t_moves;

typedef struct	s_lemin
{
	t_flags		*flags;
	t_lines		*lines;
	t_rooms		*rooms;
	t_links		*links;
	t_adj_list	**adj_list;
	t_path		*path;
	t_queue		*queue;
	t_moves		*moves;
	char		*error_reason;
	char		*start;
	char		*end;
	int			fl_start;
	int			fl_end;
	int			fl_links;
	int			ants;
	int			*visited;
	int			fastest;
}				t_lemin;

t_lemin			*init_info(int argc, char **argv);
void			put_manual(t_lemin *info);
void			put_lines(t_lemin *info);
void			error(t_lemin *info);

void			check_input(t_lemin *info);
void			check_start_and_end(t_lemin *info);
void			check_rooms_and_links(t_lemin *info);
void			check_link(t_lemin *info, char **words);
void			check_filling(t_lemin *info);
void			check_route(t_lemin *info);

void			make_adjacency_lists(t_lemin *info);

void			algoritm(t_lemin *info);
void			init_path(t_lemin *info);
void			get_all_paths(t_lemin *info);
t_queue			*get_queue(t_lemin *info);
t_text			*get_path(t_lemin *info, t_queue *queue);

void			simple_moves(t_lemin *info);
int				path_len(t_path *path);
void			moves(t_lemin *info);
void			execute_moves(t_lemin *info);

int				num_words(char **words);
int				num_rooms(t_lemin *info);
void			free_words(char **words);
void			free_queue(t_queue *queue);

void			bonuses(t_lemin *info);
void			check_music(t_lemin *info);
void			colours(t_lemin *info, t_moves *moves);
void			stop_colours(t_lemin *info);

#endif
