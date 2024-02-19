/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:31:10 by iubieta-          #+#    #+#             */
/*   Updated: 2024/02/19 20:05:48 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ft_join_args(int argc,char *argv[]) {
	int		i;
	int		j;
	int		arg_len;
	char	*final_arg;
	char	*temp_arg;
	
	i = 1;
	arg_len = 0;
	while (i++ < argc)
		arg_len = arg_len + ft_strlen(argv[i]) + 1;
	final_arg = malloc(arg_len);
	i = 1;
	while (i++ < argc)
	{
		ft_join(final_arg, argv[i])
	}
	
}

int verify_arguments(int argc, char *argv[]) {
    if (argc == 1) return 0; // No arguments

    if (argc > 2)
		ft_join_args(argc, argv);
		

    if (has_duplicates(argc, argv)) return -1; // There are duplicate numbers

    return 1; // Arguments are correct
}