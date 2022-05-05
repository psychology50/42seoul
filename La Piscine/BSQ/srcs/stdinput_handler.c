/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdinput_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 08:32:51 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 10:12:34 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	stdinput_handler(void)
{
	int		fd;
	int		readn;
	char	buf[100];

	fd = open(STDINPUT, O_WRONLY | O_TRUNC | O_CREAT, 0777); // 쓰기 전용으로 열 때, 파일이 없는 경우
	// O_WRONLY : 쓰기 전용
	// O_TRUNC  : 파일 생성 시, 이미 존재하는 파일이고 쓰기 옵션이면 내용을 모두 지우고 파일의 길이 0으로 변경
	// O_CREAT  : 파일이 없으면 생성한다. 파일을 생성할 권한을 필요로 한다.
	// 0777 : chmod 권한 설정과 비슷하다. O_CREAT 옵션을 위해 필수적으로 사용해야 하며, 파일 접근 권한을 명시한다.
	if (fd < 0)
	{
		ft_puterr();
		return ;
	}
	while (1)
	{
		readn = read(0, buf, 100);
		if (readn <= 0)
			break ;
		write(fd, buf, readn);
	}
	close(fd);
}